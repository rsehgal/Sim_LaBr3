/*
**	Filename : Sim01_SteppingAction.cpp
**	2022-12-02
**	username : rsehgal
*/
#include "Sim01_SteppingAction.h"
#include "Sim01_EventAction.h"
#include "Sim01_RunAction.h"
#include <G4Step.hh>
#include <G4Track.hh>
#include <G4VProcess.hh>
#include <iostream>
#include <string>
Sim01_SteppingAction::Sim01_SteppingAction() {}

Sim01_SteppingAction::Sim01_SteppingAction(Sim01_RunAction *runAction, Sim01_EventAction *eventAction)
{
  fEventAction = eventAction;
}

Sim01_SteppingAction::~Sim01_SteppingAction() {}

void Sim01_SteppingAction::UserSteppingAction(const G4Step *step)
{
     double edep = step->GetTotalEnergyDeposit();
     fEventAction->fEDep += edep;
}
