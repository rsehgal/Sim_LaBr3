/*
**	Filename : Sim01_RunAction.cpp
**	2022-12-02
**	username : rsehgal
*/
#include "Sim01_RunAction.h"
#include <iostream>
#ifdef USE_ROOT
#include <TH1F.h>
#include <TFile.h>
#include <TRandom3.h>
#endif

Sim01_RunAction::Sim01_RunAction() {}

Sim01_RunAction::~Sim01_RunAction() {}

void Sim01_RunAction::BeginOfRunAction(const G4Run *)
{
  /* Can be used to
    --Open a file
    -- Registering histogram etc
  */

  std::cout << "======================================" << std::endl;
  std::cout << "Entered begin of RunAction....." << std::endl;
  fAsciiFile.open("output.txt");
#ifdef USE_ROOT
  fp = new TFile("output.root", "RECREATE");
  fHist     = new TH1F("EnergyHist", "EnergyHist", 662, 0, 1000.);
  fRnd = new TRandom3;
#endif
}

void Sim01_RunAction::Fill(double energy)
{
double enerSmeared = energy;
double enerResolution = 0.03;
double sigma = (0.03*662)/2.355;
#ifdef USE_ROOT
  //enerSmeared =  fRnd->Gaus(energy*1000.,20);
  enerSmeared =  fRnd->Gaus(energy*1000.,sigma);
  fHist->Fill(enerSmeared);
#endif
  fAsciiFile << enerSmeared << std::endl;
}
void Sim01_RunAction::EndOfRunAction(const G4Run *)
{
  /* Can be used to
    --Writing histogram to file
    --Close the file
  */
  std::cout << "Entered end of RunAction....." << std::endl;
  std::cout << "======================================" << std::endl;
#ifdef USE_ROOT
  fHist->Write();
  fp->Close();
#endif
  fAsciiFile.close();
}
