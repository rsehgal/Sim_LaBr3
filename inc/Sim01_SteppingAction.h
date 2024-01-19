#ifndef Sim01_SteppingAction_h
#define Sim01_SteppingAction_h
#include "G4UserSteppingAction.hh"
#include "globals.hh"

class G4Step;
class Sim01_RunAction;
class Sim01_EventAction;
class Sim01_SteppingAction : public G4UserSteppingAction {
public:
  
  Sim01_SteppingAction();
  Sim01_SteppingAction(Sim01_RunAction *runAction, Sim01_EventAction *eventAction);

  ~Sim01_SteppingAction();

public:
  void UserSteppingAction(const G4Step *);

private:
  Sim01_EventAction *fEventAction;
  Sim01_RunAction *fRunAction;
};

#endif
