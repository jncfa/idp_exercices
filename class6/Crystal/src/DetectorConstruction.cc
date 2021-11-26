#include "DetectorConstruction.hh"

#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
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
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
DetectorConstruction::~DetectorConstruction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
G4VPhysicalVolume* DetectorConstruction::Construct()
{
//--------- Material definition ---------

  G4NistManager* man = G4NistManager::Instance();
    
  // Materials
  G4double a, z;
  G4double density, temperature, pressure;
  G4int nel;

  density     = universe_mean_density;    //from PhysicalConstants.h
  pressure    = 3.e-18*pascal;
  temperature = 2.73*kelvin;
  G4Material* Vacuum   = new G4Material("Vacuum",
                                        1., 1.01*g/mole, density,
                                        kStateGas,temperature,pressure);    



  // Print all the materials defined.
  G4cout << G4endl << "The materials defined are : " << G4endl << G4endl;
  G4cout << *(G4Material::GetMaterialTable()) << G4endl;
  
         
//--------- Definitions of Solids, Logical Volumes, Physical Volumes ---------
  
  //------------------------------ 
  // World
  //------------------------------ 
  G4double fWorldLength= 1.0*m;
  G4double HalfWorldLength = 0.5*fWorldLength;
 
  G4Box* solidWorld = 
  		new G4Box("world",HalfWorldLength,HalfWorldLength,HalfWorldLength);
  G4LogicalVolume* logicWorld = 
  		new G4LogicalVolume( solidWorld, Vacuum, "World", 0, 0, 0);
  
  //  Must place the World Physical volume unrotated at (0,0,0).
  G4VPhysicalVolume* physiWorld = 
  		new G4PVPlacement(0,               // no rotation
                          G4ThreeVector(), // at (0,0,0)
                          logicWorld,      // its logical volume
                          "World",         // its name
                          0,               // its mother  volume
                          false,           // no boolean operations
                          0);              // copy number
				 
	 

	 

//--------- Visualization attributes -------------------------------
  G4VisAttributes* WorldVisAtt= new G4VisAttributes(G4Colour(1.0,1.0,1.0));
  G4VisAttributes* TargetVisAtt = new G4VisAttributes(G4Colour(0.0,0.0,1.0));
  logicWorld->SetVisAttributes(WorldVisAtt);
  //crystal_log->SetVisAttributes(TargetVisAtt);
    

  return physiWorld;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
