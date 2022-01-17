
#include "SteppingAction.hh"
#include "G4SteppingManager.hh"

using namespace CLHEP;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction()
{
    bout.open("BraggPeak.out");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{
    bout.close();
}

// USE THIS METHOD FOR STEP #2 -- PRODUCING THE BRAGG PEAK
void SteppingAction::UserSteppingAction(const G4Step* thisStep)
{ 
	G4Track* thisTrack = thisStep->GetTrack();
	G4VPhysicalVolume* theVolume = thisTrack->GetVolume();
	const G4ParticleDefinition* thisParticle = thisTrack->GetParticleDefinition();
	if(theVolume->GetName() == "Target" && thisParticle->GetParticleName() == "proton"){
		bout << thisTrack->GetTrackLength() / cm << "\t"
				<< thisStep->GetTotalEnergyDeposit() /MeV << "\t"
                << thisStep->GetStepLength() / cm << G4endl;
	}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

