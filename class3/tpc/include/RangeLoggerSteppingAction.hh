
#ifndef __RANGER_LOGGER_STEPPING_ACTION_H__
#define __RANGER_LOGGER_STEPPING_ACTION_H__

#include "G4UserSteppingAction.hh"
#include <fstream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class RangeLoggerSteppingAction : public G4UserSteppingAction
{
  public:
    RangeLoggerSteppingAction();
   ~RangeLoggerSteppingAction();

    void UserSteppingAction(const G4Step*);
    
  private:
    std::ofstream bout;
    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif//__RANGER_LOGGER_STEPPING_ACTION_H__
