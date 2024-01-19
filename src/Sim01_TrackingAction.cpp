/*
**	Filename : Sim01_TrackingAction.cpp
**	2024-01-17
**	username : rsehgal
*/
#include "Sim01_TrackingAction.h"
#include <G4Step.hh>
#include <G4String.hh>
#include <G4TouchableHandle.hh>
#include <G4Track.hh>
#include <G4TrackVector.hh>
#include <G4TrackingManager.hh>
#include <G4VPhysicalVolume.hh>
#include <G4VProcess.hh>
#include <colors.h>

Sim01_TrackingAction::Sim01_TrackingAction() : G4UserTrackingAction() {}
Sim01_TrackingAction::~Sim01_TrackingAction() {}

void Sim01_TrackingAction::PreUserTrackingAction(const G4Track *aTrack) {

  // if (aTrack->GetParentID() == 1)
  {

    const G4VProcess *creatorProcess = aTrack->GetCreatorProcess();
    std::string processName = "";
    if (aTrack->GetTrackID() == 1)
      processName = "Sehgal";

    if (creatorProcess) {
      // std::cout << "Process that creates gamma : " << creatorProcess->GetProcessName() << std::endl;
      processName = creatorProcess->GetProcessName();
    }

    G4String particleName = aTrack->GetDefinition()->GetParticleName();

    #ifdef VERBOSE
    std::cout << "Sehgal Tracking action called : TrackID : " << aTrack->GetTrackID()
              << " :: Particle Name : " << particleName << " :: KE : " << aTrack->GetKineticEnergy()
              << " :: ParentID : " << aTrack->GetParentID() << " :: ProcessName : " << processName
              << " :: In Volume : " << aTrack->GetVolume()->GetName() << std::endl;
    #endif
              
  }

  if (!aTrack->GetStep()) {
    // No valid pre-step point, possibly during initialization
    return;
  }
  const G4Step *preStep = aTrack->GetStep();
  const G4TouchableHandle &touchable = preStep->GetPreStepPoint()->GetTouchableHandle();

  // Get the volume information
  const G4VPhysicalVolume *volume = touchable->GetVolume();
  G4String volumeName = volume->GetName();

  // Now you have the information about the volume where the creator process occurred
  #ifdef VERBOSE
  G4cout << "Creator process happened in volume: " << volumeName << G4endl;
  #endif
}

void Sim01_TrackingAction::PostUserTrackingAction(const G4Track *aTrack) {
  G4TrackVector *secTracks = fpTrackingManager->GimmeSecondaries();
  #ifdef VERBOSE
  std::cout << RED << "No of Secondaries produced : " << secTracks->size() << RESET << std::endl;
  #endif
  if (secTracks) {
    for (unsigned int i = 0; i < secTracks->size(); i++) {
      const G4VProcess *creatorProcess = secTracks->at(i)->GetCreatorProcess();
      std::string processName = "";
      if (secTracks->at(i)->GetTrackID() == 1)
        processName = "Sehgal";

      if (creatorProcess) {
        // std::cout << "Process that creates gamma : " << creatorProcess->GetProcessName() << std::endl;
        processName = creatorProcess->GetProcessName();
      }
      #ifdef VERBOSE
      std::cout << GREEN << "Secondary Tracks : TrackID : "
                << secTracks->at(i)->GetTrackID()
                //<< " :: Particle Name : " << particleName
                << " :: ParentID : "
                << secTracks->at(i)->GetParentID()
                << " :: ProcessName : " << processName
                << " :: In Volume : " << secTracks->at(i)->GetVolume()->GetName() << RESET << std::endl;
      #endif                
    }
  }
  /*
    if (secTracks) {
      for (unsigned int i = 0; i < secTracks->size(); i++) {
        const G4VProcess *creatorProcess = secTracks->at(i)->GetCreatorProcess();
        std::string processName = "";
        if (secTracks->at(i)->GetTrackID() == 1)
          processName = "Sehgal";

        if (creatorProcess) {
          // std::cout << "Process that creates gamma : " << creatorProcess->GetProcessName() << std::endl;
          processName = creatorProcess->GetProcessName();
        }

        std::cout << "Secondary Tracks : " << secTracks->at(i)->GetTrackID()
                << " :: ParentID : " << secTracks->at(i)->GetParentID() << " :: ProcessName : " << processName
                << " :: In Volume : " << secTracks->at(i)->GetVolume()->GetName() << std::endl;
      }
    }
    */
}
