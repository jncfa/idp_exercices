#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"

using namespace CLHEP;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::PrimaryGeneratorAction(DetectorConstruction* myDC)
    :myDetector(myDC)
{
  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);

    particleGun->SetParticleEnergy(0*eV);
    particleGun->SetParticlePosition(G4ThreeVector(0.,0.,0.));
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete particleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{ 
    G4double ionCharge   = 0.*eplus;
    G4double excitEnergy = 0.*keV;
    //H3
    //G4int Z = 1, A = 3;
    // Ne24
    G4int Z = 10, A = 24;
    //Mg23
    //G4int Z = 12, A = 23;
    //K40
    //G4int Z = 19, A = 40;
    //Co60
    //G4int Z = 27, A = 60;
    //Kr83m
    //G4int Z = 36, A = 83;
    //G4double excitEnergy = 41.6*keV;
    //Kr85
    //G4int Z = 36, A = 85;
    //Cs137
    //G4int Z = 55, A = 137;
    // Bi210
    //G4int Z = 83, A = 210;
    //Am241
    //G4int Z = 95, A = 241;
    
    G4IonTable* ionTable
        = G4ParticleTable::GetParticleTable()->GetIonTable();
    G4ParticleDefinition* ion = ionTable->GetIon(Z,A,excitEnergy);
    particleGun->SetParticleDefinition(ion);
    particleGun->SetParticleCharge(ionCharge);

//create vertex
  particleGun->GeneratePrimaryVertex(anEvent);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
