#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4MTRunManager.hh"
#include "G4AnalysisManager.hh"
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

int main(int argc, char** argv) {
    // Detect interactive mode (if no arguments) and define UI session
    G4UIExecutive* ui = nullptr;
    if (argc == 1) {
        ui = new G4UIExecutive(argc, argv);
    }

    // Construct the default run manager
    G4RunManager* runManager = new G4RunManager();

    // Set mandatory initialization classes
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new PhysicsList());

    // Set mandatory user action class
    runManager->SetUserAction(new PrimaryGeneratorAction());

    // Set user action classes
    runManager->SetUserAction(new RunAction());
    runManager->SetUserAction(new EventAction());
    runManager->SetUserAction(new SteppingAction());

    // Initialize G4 kernel
    runManager->Initialize();

    // Initialize visualization
    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();

    // Get the pointer to the User Interface manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    if (ui) {
        // Interactive mode
        UImanager->ApplyCommand("/control/execute ../vis.mac");
        ui->SessionStart();
        delete ui;
    } else {
        // Batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    }

    // Job termination
    delete visManager;
    delete runManager;

    return 0;
}
