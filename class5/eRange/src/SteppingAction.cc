
#include "SteppingAction.hh"
#include "G4SteppingManager.hh"
#include "EventAction.hh"

using namespace CLHEP;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(EventAction* aEvtAction)
{
    myEventAction = aEvtAction;
    sout.open("csda_air.out");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{
    sout.close(); 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* thisStep)
{ 
    G4Track* thisTrack = thisStep->GetTrack();
    // Note that each particle has an associated track,
    // and the primary particle has ID = 1
    G4int trackID = thisTrack->GetTrackID();
    
    G4double kinEner = thisTrack->GetKineticEnergy();
    G4double trackLength = thisTrack->GetTrackLength();

    // We will use the distance along the initial direction
    // as our 'projected range'
    G4double projRange = (thisTrack->GetPosition()).x();

    // This is how you can access a variable from the EventAction
    //myEventAction->range

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

