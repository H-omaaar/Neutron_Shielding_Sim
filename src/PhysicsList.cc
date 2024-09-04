#include "PhysicsList.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronPhysicsQGSP_BERT.hh"
#include "G4EmStandardPhysics.hh"
#include "G4DecayPhysics.hh"

PhysicsList::PhysicsList() {
    // EM physics
    RegisterPhysics(new G4EmStandardPhysics());

    // Decay physics
    RegisterPhysics(new G4DecayPhysics());

    // Hadronic physics
    RegisterPhysics(new G4HadronElasticPhysics());
    RegisterPhysics(new G4HadronPhysicsQGSP_BERT());
}

PhysicsList::~PhysicsList() {}

