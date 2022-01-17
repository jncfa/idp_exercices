
#include "DetectorConstruction.hh"
#include "Shielding.hh"
#include "QGSP_BERT_HP.hh"
#include "PrimaryGeneratorAction.hh"
#include "SteppingAction.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "PhysicsList.hh"
#include "Randomize.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc,char** argv)
{
  // Run manager
  //
  G4RunManager * runManager = new G4RunManager;
  
  //CLHEP::RanluxEngine defaultEngine( 1234567, 4 );
  //G4Random::setTheEngine( &defaultEngine );
  //G4int seed = (G4int) time( NULL );
  //G4Random::setTheSeed( seed );

  // User Initialization classes (mandatory)
  //
  DetectorConstruction* detector = new DetectorConstruction;
  runManager->SetUserInitialization(detector);
  //
  G4VUserPhysicsList* physics = new PhysicsList;
  //Shielding *physics = new Shielding();
  //QGSP_BERT_HP *physics = new QGSP_BERT_HP();
  runManager->SetUserInitialization(physics);
   
  // User Action classes
  //
  G4VUserPrimaryGeneratorAction* gen_action = new PrimaryGeneratorAction(detector);
  runManager->SetUserAction(gen_action);
  //
  G4UserSteppingAction* stepping_action = new SteppingAction;
  runManager->SetUserAction(stepping_action);

  // Initialize G4 kernel
  //
  runManager->Initialize();
    
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();   
     
  // Get the pointer to the User Interface manager
  //
  G4UImanager * UImanager = G4UImanager::GetUIpointer();  

  if (argc!=1)   // batch mode  
    {
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UImanager->ApplyCommand(command+fileName);
    }
  else           // interactive mode : define UI session
    { 
      G4UIExecutive * ui = new G4UIExecutive(argc,argv);
      UImanager->ApplyCommand("/control/execute vis.mac");     
      ui->SessionStart();
      delete ui;
      delete visManager;   
    }

  // Free the store: user actions, physics_list and detector_description are
  //                 owned and deleted by the run manager, so they should not
  //                 be deleted in the main() program !

  delete runManager;

  return 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

