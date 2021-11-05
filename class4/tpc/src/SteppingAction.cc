
#include "SteppingAction.hh"
#include "G4SteppingManager.hh"

using namespace CLHEP;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction()
{
    bout.open("Shielding_Pb.out");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{
    bout.close();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step *thisStep)
{
    G4Track *thisTrack = thisStep->GetTrack();
    G4VPhysicalVolume *theVolume = thisTrack->GetVolume();
    const G4ParticleDefinition *thisParticle = thisTrack->GetParticleDefinition();
    double kinEner = thisTrack->GetKineticEnergy();
    G4ThreeVector position = thisTrack->GetPosition();

    // Only check particles that hit the detector
    if (theVolume->GetName() == "Detector")
    {
        // Only check primary particles
        if (thisParticle->GetParticleName() == "gamma")
        {
            bout << position.x() / cm << "\t"
                 << position.y() / cm << "\t"
                 << position.z() / cm << "\t"
                 << kinEner / MeV << G4endl;
        }
        thisTrack->SetTrackStatus(G4TrackStatus::fKillTrackAndSecondaries);
    }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
