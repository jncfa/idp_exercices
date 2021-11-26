
#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include <fstream>

class EventAction;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class SteppingAction : public G4UserSteppingAction
{
  public:
    SteppingAction();
    SteppingAction(EventAction*);
   ~SteppingAction();

    void UserSteppingAction(const G4Step*);
    
  private:
    EventAction* myEventAction;
    std::ofstream sout;
    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
