/*
**	Filename : Sim01_TrackingAction.h
**	2024-01-17
**	username : rsehgal
*/
#ifndef Sim01_TrackingAction_h
#define Sim01_TrackingAction_h

#include <G4UserTrackingAction.hh>

class G4Track;
class G4UserTrackingAction;

class Sim01_TrackingAction : public G4UserTrackingAction {
public:
  Sim01_TrackingAction();
  ~Sim01_TrackingAction();
  virtual void PreUserTrackingAction(const G4Track *aTrack);
  virtual void PostUserTrackingAction(const G4Track *aTrack);
};

#endif
