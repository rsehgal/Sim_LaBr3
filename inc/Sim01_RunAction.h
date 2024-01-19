#ifndef Sim01_RunAction_h
#define Sim01_RunAction_h
#include "G4UserRunAction.hh"
#include "globals.hh"
#include <fstream>
class G4Run;
class TH1F;
class TFile;
class TRandom3;
class Data;

class Sim01_RunAction : public G4UserRunAction {
public:
  std::map<G4String, Data *> fData;
  Sim01_RunAction();
  ~Sim01_RunAction();

public:
  void BeginOfRunAction(const G4Run *);
  void EndOfRunAction(const G4Run *);
  void CheckAndInsertParticleCreatorProcessAndEnergy(G4String particleName, std::string processName, double energy);

  void Fill(double energy);
#ifdef USE_ROOT
  TH1F *fHist;
  TFile *fp;
  TRandom3 *fRnd;
#endif
  std::ofstream fAsciiFile;
};

#endif
