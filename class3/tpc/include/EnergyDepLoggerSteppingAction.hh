
#ifndef __ENERGYDEP_LOGGER_STEPPING_ACTION_H__
#define __ENERGYDEP_LOGGER_STEPPING_ACTION_H__

#include "G4UserSteppingAction.hh"
#include <fstream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class EnergyDepLoggerSteppingAction : public G4UserSteppingAction
{
  public:
    EnergyDepLoggerSteppingAction();
   ~EnergyDepLoggerSteppingAction();

    void UserSteppingAction(const G4Step*);
    
  private:
    std::ofstream bout;
    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif//__ENERGYDEP_LOGGER_STEPPING_ACTION_H__
