#include "DetectorConstruction.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4SystemOfUnits.hh"

DetectorConstruction::DetectorConstruction()
    : G4VUserDetectorConstruction(), fLogicWorld(nullptr), fPhysiWorld(nullptr) {}

DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    // Define materials
    G4NistManager* nist = G4NistManager::Instance();

    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");

    G4Material* SSA1 = new G4Material("SSA1", 9.04*g/cm3, 10);
    SSA1->AddElement(nist->FindOrBuildElement("Ni"), 38*perCent);
    SSA1->AddElement(nist->FindOrBuildElement("Cr"), 10*perCent);
    SSA1->AddElement(nist->FindOrBuildElement("Mn"), 2*perCent);
    SSA1->AddElement(nist->FindOrBuildElement("C"), 0.5*perCent);
    SSA1->AddElement(nist->FindOrBuildElement("Mo"), 1*perCent);
    SSA1->AddElement(nist->FindOrBuildElement("W"), 15*perCent);
    SSA1->AddElement(nist->FindOrBuildElement("Si"), 1*perCent);
    SSA1->AddElement(nist->FindOrBuildElement("Ti"), 3*perCent);
    SSA1->AddElement(nist->FindOrBuildElement("Fe"), 29.5*perCent);

    G4Material* SSA2 = new G4Material("SSA2", 9.85*g/cm3, 9);
    SSA2->AddElement(nist->FindOrBuildElement("Ni"), 22*perCent);
    SSA2->AddElement(nist->FindOrBuildElement("Cr"), 18*perCent);
    SSA2->AddElement(nist->FindOrBuildElement("Mn"), 2*perCent);
    SSA2->AddElement(nist->FindOrBuildElement("C"), 1*perCent);
    SSA2->AddElement(nist->FindOrBuildElement("W"), 18*perCent);
    SSA2->AddElement(nist->FindOrBuildElement("Fe"), 35.975*perCent);
    SSA2->AddElement(nist->FindOrBuildElement("V"), 1*perCent);
    SSA2->AddElement(nist->FindOrBuildElement("Re"), 0.025*perCent);

    G4Material* SSA3 = new G4Material("SSA3", 10.45*g/cm3, 10);
    SSA3->AddElement(nist->FindOrBuildElement("Ni"), 30*perCent);
    SSA3->AddElement(nist->FindOrBuildElement("Cr"), 15*perCent);
    SSA3->AddElement(nist->FindOrBuildElement("Mn"), 1*perCent);
    SSA3->AddElement(nist->FindOrBuildElement("C"), 0.5*perCent);
    SSA3->AddElement(nist->FindOrBuildElement("Mo"), 1*perCent);
    SSA3->AddElement(nist->FindOrBuildElement("W"), 20*perCent);
    SSA3->AddElement(nist->FindOrBuildElement("Fe"), 31.47*perCent);
    SSA3->AddElement(nist->FindOrBuildElement("S"), 0.015*perCent);
    SSA3->AddElement(nist->FindOrBuildElement("V"), 0.015*perCent);
    SSA3->AddElement(nist->FindOrBuildElement("Re"), 1*perCent);

    // World volume
    G4Box* solidWorld = new G4Box("World", 1*m, 1*m, 1*m);
    fLogicWorld = new G4LogicalVolume(solidWorld, air, "World");
    fPhysiWorld = new G4PVPlacement(0, G4ThreeVector(), fLogicWorld, "World", 0, false, 0);

    // Sample volumes
    G4Box* solidSample = new G4Box("Sample", 5*cm, 5*cm, 1*cm);

    G4LogicalVolume* logicSample1 = new G4LogicalVolume(solidSample, SSA1, "Sample1");
    new G4PVPlacement(0, G4ThreeVector(0, -20*cm, 0), logicSample1, "Sample1", fLogicWorld, false, 0);
    G4VisAttributes* sample1VisAttr = new G4VisAttributes(G4Colour(0.3, 0, 0)); // Dark red
    sample1VisAttr->SetForceSolid(true);
    logicSample1->SetVisAttributes(sample1VisAttr);

    G4LogicalVolume* logicSample2 = new G4LogicalVolume(solidSample, SSA2, "Sample2");
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logicSample2, "Sample2", fLogicWorld, false, 0);
    G4VisAttributes* sample2VisAttr = new G4VisAttributes(G4Colour(0, 0.3, 0)); // Dark green
    sample2VisAttr->SetForceSolid(true);
    logicSample2->SetVisAttributes(sample2VisAttr);

    G4LogicalVolume* logicSample3 = new G4LogicalVolume(solidSample, SSA3, "Sample3");
    new G4PVPlacement(0, G4ThreeVector(0, 20*cm, 0), logicSample3, "Sample3", fLogicWorld, false, 0);
    G4VisAttributes* sample3VisAttr = new G4VisAttributes(G4Colour(0, 0, 0.3)); // Dark blue
    sample3VisAttr->SetForceSolid(true);
    logicSample3->SetVisAttributes(sample3VisAttr);

    // Detector volume
    G4Box* solidDetector = new G4Box("Detector", 5*cm, 5*cm, 1*cm);
    G4LogicalVolume* logicDetector = new G4LogicalVolume(solidDetector, air, "Detector");
    new G4PVPlacement(0, G4ThreeVector(0, 0, 40*cm), logicDetector, "Detector", fLogicWorld, false, 0);
    G4VisAttributes* detectorVisAttr = new G4VisAttributes(G4Colour::Yellow());
    detectorVisAttr->SetForceSolid(true);
    logicDetector->SetVisAttributes(detectorVisAttr);

    return fPhysiWorld;
}
