
#include "Sim01_ActionInitialization.h"
#include "Sim01_PrimaryGeneratorAction.h"
#include <G4Run.hh>
#include "Sim01_RunAction.h"
#include "Sim01_EventAction.h"
#include "Sim01_SteppingAction.h"
#include "Sim01_TrackingAction.h"

Sim01_ActionInitialization::Sim01_ActionInitialization()
 : G4VUserActionInitialization()
{}


Sim01_ActionInitialization::~Sim01_ActionInitialization()
{}


void Sim01_ActionInitialization::BuildForMaster() const
{
}


void Sim01_ActionInitialization::Build() const
{
  
  SetUserAction(new Sim01_PrimaryGeneratorAction);

  Sim01_RunAction *runAction = new Sim01_RunAction;
  SetUserAction(runAction);
  Sim01_EventAction *eventAction = new Sim01_EventAction(runAction);
  SetUserAction(eventAction);
  SetUserAction(new Sim01_SteppingAction(runAction,eventAction));
  //SetUserAction(new Sim01_TrackingAction);
}  

