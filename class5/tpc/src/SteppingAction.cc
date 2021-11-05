
#include "SteppingAction.hh"
#include "G4SteppingManager.hh"

using namespace CLHEP;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction()
{
    bout.open("Decay_Ne24.out");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{
    bout.close();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step *thisStep)
{
	G4Track* thisTrack = thisStep->GetTrack();
    G4VPhysicalVolume* theVolume = thisTrack->GetVolume();
    G4String thisVolumeName = theVolume->GetName();
    G4int parentID = thisTrack->GetParentID();
	const G4ParticleDefinition* thisParticle = thisTrack->GetParticleDefinition();
	G4String particleName = thisParticle->GetParticleName();
    G4double kineticEnergy = thisTrack->GetKineticEnergy();
    G4double time = thisTrack->GetGlobalTime();

    // Only check electrons
    if (thisParticle->GetParticleName() == "e-")
    {
        bout << kineticEnergy / cm << "\t"
                << time / cm << G4endl;

        thisTrack->SetTrackStatus(G4TrackStatus::fKillTrackAndSecondaries);
    }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

