#ifndef Sim01_EventAction_h
#define Sim01_EventAction_h
#include "G4UserEventAction.hh"
#include "globals.hh"

class G4Run;
class Sim01_RunAction;
class Sim01_EventAction : public  G4UserEventAction{
public:
    Sim01_EventAction(Sim01_RunAction *runAction);
    Sim01_EventAction();
    ~Sim01_EventAction();
public:
    void BeginOfEventAction(const G4Event* anEvent);
    void EndOfEventAction(const G4Event* anEvent);

    double fEDep;
    Sim01_RunAction *fRunAction;
};

#endif
