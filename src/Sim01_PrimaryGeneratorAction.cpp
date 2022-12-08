#include "Sim01_PrimaryGeneratorAction.h"

#include "G4Box.hh"
#include "G4Electron.hh"
#include "G4LogicalVolume.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4Proton.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4RandomDirection.hh"
Sim01_PrimaryGeneratorAction::Sim01_PrimaryGeneratorAction() {
 fParticleGun = new G4ParticleGun(1);
 G4ParticleDefinition* particle
           = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleEnergy(662*keV);    
  fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,-5*cm));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
}
Sim01_PrimaryGeneratorAction::~Sim01_PrimaryGeneratorAction() { delete fParticleGun; }

void Sim01_PrimaryGeneratorAction::GeneratePrimaries(G4Event *event) {
// fParticleGun = new G4ParticleGun(1);

// fParticleGun->SetParticleMomentumDirection(G4RandomDirection());
 fParticleGun->GeneratePrimaryVertex(event);
}
