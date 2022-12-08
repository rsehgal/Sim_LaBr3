#ifndef Sim01_PrimaryGeneratorAction_h
#define Sim01_PrimaryGeneratorAction_h 

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;
class G4Box;

class Sim01_PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    Sim01_PrimaryGeneratorAction();    
     ~Sim01_PrimaryGeneratorAction();

    // method from the base class
    void GeneratePrimaries(G4Event*);         
  
    // method to access particle gun
    const G4ParticleGun* GetParticleGun() const { return fParticleGun; }
  
  private:
    G4ParticleGun*  fParticleGun; // pointer a to G4 gun class
};


#endif
