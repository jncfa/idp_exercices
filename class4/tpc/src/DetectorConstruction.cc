
#include "DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4GeometryManager.hh"

#include "G4UserLimits.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4ios.hh"

using namespace CLHEP;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume *DetectorConstruction::Construct()
{
    //--------- Material definition ---------

    G4double a, z;
    G4double density, temperature, pressure;
    G4int nel;

    // Elements
    G4Element *H = new G4Element("Hydrogen", "H", z = 1., a = 1.01 * g / mole);
    G4Element *N = new G4Element("Nitrogen", "N", z = 7., a = 14.01 * g / mole);
    G4Element *O = new G4Element("Oxygen", "O", z = 8., a = 16.00 * g / mole);
    G4Element *Pb = new G4Element("Lead", "Pb", z = 82., a = 207.2 * g / mole);

    // Materials
    density = universe_mean_density; //from PhysicalConstants.h
    pressure = 3.e-18 * pascal;
    temperature = 2.73 * kelvin;
    G4Material *Vacuum = new G4Material("Vacuum",
                                        1., 1.01 * g / mole, density,
                                        kStateGas, temperature, pressure);

    //Air
    G4Material *Air = new G4Material("Air", density = 1.29 * mg / cm3, nel = 2);
    Air->AddElement(N, 70 * perCent);
    Air->AddElement(O, 30 * perCent);

    //Water
    density = 1.000 * g / cm3;
    int ncomp = 2;
    G4Material *H2O = new G4Material("Water", density, ncomp);
    G4int natoms;
    H2O->AddElement(H, natoms = 2);
    H2O->AddElement(O, natoms = 1);

    // Lead
    G4Material *Lead = new G4Material("Lead", density = 11.2 * g / cm3, nel = 1);
    Lead->AddElement(Pb, natoms = 1);

    // Print all the materials defined.
    //
    G4cout << G4endl << "The materials defined are : " << G4endl << G4endl;
    G4cout << *(G4Material::GetMaterialTable()) << G4endl;

    //--------- Definitions of Solids, Logical Volumes, Physical Volumes ---------

    //------------------------------
    // World
    //------------------------------
    G4double fWorldLength = 10.0 * m;
    G4double HalfWorldLength = 0.5 * fWorldLength;

    G4double fTargetThickness = 2.89 * cm;
    G4double fDetectorThickness = 0.01 * cm;

    G4Box *solidWorld =
        new G4Box("world", HalfWorldLength, HalfWorldLength, HalfWorldLength);

    G4LogicalVolume *logicWorld =
        new G4LogicalVolume(solidWorld, Vacuum, "World", 0, 0, 0);

    //  Must place the World Physical volume unrotated at (0,0,0).
    G4VPhysicalVolume *physiWorld =
        new G4PVPlacement(nullptr,               // no rotation
                          G4ThreeVector(), // at (0,0,0)
                          logicWorld,      // its logical volume
                          "World",         // its name
                          nullptr,         // its mother  volume
                          false,           // no boolean operations
                          0);              // copy number

    G4Box *solidTarget =
        new G4Box("target", 0.5*fTargetThickness, HalfWorldLength, HalfWorldLength);

    G4LogicalVolume *logicTarget =
        new G4LogicalVolume(solidTarget, Lead, "Target", 0, 0, 0);

    //  Must place the Target Physical volume unrotated at (halfWorldLength,0,0) in relation to the world Physical Volume.
    G4VPhysicalVolume *physiTarget =
        new G4PVPlacement(nullptr, // no rotation
                          G4ThreeVector(fTargetThickness/2),
                          logicTarget, // its logical volume
                          "Target",    // its name
                          logicWorld,  // its mother  volume
                          false,       // no boolean operations
                          0);          // copy number

    G4Box *solidDetector =
        new G4Box("detector", 0.5*fDetectorThickness, HalfWorldLength, HalfWorldLength);

    G4LogicalVolume *logicDetector =
        new G4LogicalVolume(solidDetector, Vacuum, "Detector", 0, 0, 0);

    //  Must place the Target Physical volume unrotated at (halfWorldLength + targetThickness,0,0) in relation to the world Physical Volume.
    G4VPhysicalVolume *physiDetector =
        new G4PVPlacement(nullptr, // no rotation
                          G4ThreeVector(1*fTargetThickness+0.5*fDetectorThickness, 0, 0),
                          logicDetector, // its logical volume
                          "Detector",    // its name
                          logicWorld,  // its mother  volume
                          false,       // no boolean operations
                          0);

    //--------- Visualization attributes -------------------------------

    G4VisAttributes *WorldVisAtt = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0));
    G4VisAttributes *TargetVisAtt = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0));
    G4VisAttributes *DetectorVisAtt = new G4VisAttributes(G4Colour(0.0, 1.0, 0.0));
    logicWorld->SetVisAttributes(WorldVisAtt);
    logicTarget->SetVisAttributes(TargetVisAtt);
    logicDetector->SetVisAttributes(DetectorVisAtt);

    return physiWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
