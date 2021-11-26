
#include "EventAction.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4ios.hh"
#include "Randomize.hh"

#include <math.h>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
EventAction::EventAction()
{
//    bout.open("range_air.out");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
EventAction::~EventAction()
{
//    bout.close();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void EventAction::BeginOfEventAction(const G4Event*)
{
	// We have 2 variables defined in this EventAction
	// One to store the CSDA range and the other the projected range
//    range = 0;
//	  csda = 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void EventAction::EndOfEventAction(const G4Event* evt)
{
	// At the end of the event we can write both to the screen or a file
//    G4cout << csda /cm << "\t" << range /cm << G4endl;
//    bout << csda /cm << "\t" << range /cm << G4endl;
}
