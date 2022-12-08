#include "Sim01_DetectorConstruction.h"
#ifdef SEPARATE_ACTION_INITIALIZATION
#include "Sim01_ActionInitialization.h"
#endif 

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "QBBC.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Randomize.hh"
#include "Sim01_PrimaryGeneratorAction.h"

#include "FTFP_BERT.hh"
int main(int argc, char **argv)
{
  G4UIExecutive *ui = 0;
  if (argc == 1) {
    ui = new G4UIExecutive(argc, argv);
  }

  G4RunManager *runManager = new G4RunManager;
  // G4RunManager *runManager2 = new G4RunManager; //Second instance, will show error at runtime

  //Initalizing the Detector
  runManager->SetUserInitialization(new Sim01_DetectorConstruction());

  // Physics list
  //Initialing the Physics
  G4VModularPhysicsList *physicsList = new FTFP_BERT; // QBBC;
  // Sim01_PhysicsList *physicsList = new Sim01_PhysicsList();
  // physicsList->SetVerboseLevel(1);
  runManager->SetUserInitialization(physicsList);

  //Initializing the UserActions that gets invoked at run time (Primary Generator, RunAction, EventAction, Stepping Action etc.)
#ifdef SEPARATE_ACTION_INITIALIZATION
  runManager->SetUserInitialization(new Sim01_ActionInitialization());
#else
  runManager->SetUserAction(new Sim01_PrimaryGeneratorAction);
#endif

  // Initialize visualization
  //
  G4VisManager *visManager = new G4VisExecutive;
  visManager->Initialize();

  // Get the pointer to the User Interface manager
  G4UImanager *UImanager = G4UImanager::GetUIpointer();

  // Process macro or start UI session
  //
  if (!ui) {
    // batch mode
    G4String command  = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command + fileName);
  } else {
    // interactive mode
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;
  }

  //Freeing the memory
  delete visManager;
  delete runManager;
}

