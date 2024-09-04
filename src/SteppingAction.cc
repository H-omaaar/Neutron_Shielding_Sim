#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4AnalysisManager.hh"

SteppingAction::SteppingAction() : G4UserSteppingAction() {
    // Initialize analysis manager
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetDefaultFileType("root"); // Set default file type
    analysisManager->OpenFile("neutron_shielding.root"); // Use a file name with an extension
    analysisManager->CreateNtuple("NeutronData", "Neutron Data");
    analysisManager->CreateNtupleDColumn("TrackID");
    analysisManager->CreateNtupleDColumn("StepLength");
    analysisManager->CreateNtupleDColumn("EnergyDeposited");
    analysisManager->FinishNtuple();
}

SteppingAction::~SteppingAction() {
    // Finalize and close the analysis file
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    G4Track* track = step->GetTrack();
    auto analysisManager = G4AnalysisManager::Instance();

    // Collect data
    G4int trackID = track->GetTrackID();
    G4double stepLength = step->GetStepLength();
    G4double energyDeposited = step->GetTotalEnergyDeposit();

    // Fill data into the ntuple
    analysisManager->FillNtupleDColumn(0, trackID);
    analysisManager->FillNtupleDColumn(1, stepLength);
    analysisManager->FillNtupleDColumn(2, energyDeposited);
    analysisManager->AddNtupleRow();
}
