#ifndef Sim01_ActionInitialization_h
#define Sim01_ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"


class Sim01_ActionInitialization : public G4VUserActionInitialization
{
  public:
    Sim01_ActionInitialization();
    virtual ~Sim01_ActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

#endif

    
