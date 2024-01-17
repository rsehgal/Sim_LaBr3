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

Sim01_SteppingAction::Sim01_SteppingAction(Sim01_RunAction *runAction, Sim01_EventAction *eventAction) {
  fEventAction = eventAction;
}

Sim01_SteppingAction::~Sim01_SteppingAction() {}

void Sim01_SteppingAction::UserSteppingAction(const G4Step *step) {
  /* Can be used to
    --Initialize the Step parameters like EDep in a step
  */

  // G4Track *track = step->GetTrack();
  // if (track->GetParentID() == 0) {
  /*std::cout << "--------------------------------------" << std::endl;
  std::cout << "Step length from SteppingAction : " << step->GetStepLength() << std::endl;
  std::cout << "Total Energy deposited in the Step : " << step->GetTotalEnergyDeposit() << std::endl;*/
  //}
  G4String volumeName = step->GetTrack()->GetVolume()->GetName();
  if (volumeName == "Physical_LaBr3") {
    G4Track *track = step->GetTrack();
    G4String particleName = track->GetDefinition()->GetParticleName();

    std::string procName = step->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
    // std::cout << "ProcessName : " << procName << std::endl;
    // if(particleName=="gamma" && track->GetTrackID()==1)

    const G4VProcess *creatorProcess = track->GetCreatorProcess();
    std::string processName = "";
    if (track->GetTrackID() == 1)
      processName = "Sehgal";

    if (creatorProcess) {
      // std::cout << "Process that creates gamma : " << creatorProcess->GetProcessName() << std::endl;
      processName = creatorProcess->GetProcessName();
    }
    std::cout << "RAMAN : ParticleName : " << particleName << " :: Created by  : " << processName
              << " :: TrackID : " << track->GetTrackID() << " :: KE : " << track->GetKineticEnergy() << std::endl;

    // if(particleName=="gamma")
    {
      double edep = step->GetTotalEnergyDeposit();
      // std::cout << "Edep : " << edep << " : ProcessName : " << procName << std::endl;
      fEventAction->fEDep += edep;
    }
  }
}
