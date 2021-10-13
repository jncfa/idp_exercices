
#include "RangeLoggerSteppingAction.hh"
#include "G4SteppingManager.hh"

using namespace CLHEP;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RangeLoggerSteppingAction::SteppingAction()
{
    bout.open("BraggPeak.out");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RangeLoggerSteppingAction::~SteppingAction()
{
    bout.close();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void RangeLoggerSteppingAction::UserSteppingAction(const G4Step* thisStep)
{ 
	G4Track* thisTrack = thisStep->GetTrack();
	G4VPhysicalVolume* theVolume = thisTrack->GetVolume();
    
	if(theVolume->GetName() == "Target"){
		const G4ParticleDefinition* thisParticle = thisTrack->GetParticleDefinition();
		if(thisParticle->GetParticleName() == "alpha"){
			double kinEner = thisTrack->GetKineticEnergy();
            		if (kinEner == 0) {
                		G4double trackLength = thisTrack->GetTrackLength();
                		G4ThreeVector finalPosition = thisTrack->GetPosition();
                		bout << trackLength /mm << "\t" << finalPosition.r() /mm << G4endl;
            		}
		}
	}
	
}