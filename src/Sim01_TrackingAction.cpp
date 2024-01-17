/*
**	Filename : Sim01_TrackingAction.cpp
**	2024-01-17
**	username : rsehgal
*/
#include "Sim01_TrackingAction.h"
#include <G4Track.hh>
#include <G4Step.hh>
#include <G4TouchableHandle.hh>
#include <G4VPhysicalVolume.hh>
#include <G4String.hh>
#include <G4UserTrackingAction.hh>

Sim01_TrackingAction::Sim01_TrackingAction() {}
Sim01_TrackingAction::~Sim01_TrackingAction() {}

void Sim01_TrackingAction::PreUserTrackingAction(const G4Track *aTrack) {
  const G4Step *preStep = aTrack->GetStep();
  const G4TouchableHandle &touchable = preStep->GetPreStepPoint()->GetTouchableHandle();

  // Get the volume information
  const G4VPhysicalVolume *volume = touchable->GetVolume();
  G4String volumeName = volume->GetName();

  // Now you have the information about the volume where the creator process occurred
  G4cout << "Creator process happened in volume: " << volumeName << G4endl;
}
