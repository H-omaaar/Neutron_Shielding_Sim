#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4Neutron.hh"
#include "G4SystemOfUnits.hh"
#include "G4Event.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
    : G4VUserPrimaryGeneratorAction() {
    G4int n_particle = 1;
    fParticleGun = new G4ParticleGun(n_particle);

    // Default neutron gun
    G4ParticleDefinition* particle = G4Neutron::NeutronDefinition();
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleEnergy(4.5*MeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., -40*cm));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    fParticleGun->GeneratePrimaryVertex(anEvent);
}
