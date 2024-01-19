/*
**	Filename : Sim01_EventAction.cpp
**	2022-12-02
**	username : rsehgal
*/
#include "Sim01_EventAction.h"
#include "Sim01_RunAction.h"
#include <iostream>
unsigned int Sim01_EventAction::evNo = 0;
Sim01_EventAction::Sim01_EventAction() { fEDep = 0; }
Sim01_EventAction::Sim01_EventAction(Sim01_RunAction *runAction) {
  fEDep = 0;
  fRunAction = runAction;
}

Sim01_EventAction::~Sim01_EventAction() {}

void Sim01_EventAction::BeginOfEventAction(const G4Event *anEven) {
  /* Can be used to
    --Initialize the Event parameters like EDep,
  */

  /* std::cout << "--------------------------------------" << std::endl;
   std::cout << "Entered begin of EventAction....." << std::endl;
   */
  fEDep = 0;
  evNo++;
  #ifdef VERBOSE
  std::cout << "------------------ Ayush Event No : " << evNo << " -------------------" << std::endl;
  #endif
}
void Sim01_EventAction::EndOfEventAction(const G4Event *anEven) {
  /* Can be used to
    --Fill the histogram, which were opened in RunAction
    --Printing event by event information
  */
  /*std::cout << "Entered end of EventAction....." << std::endl;
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "Total Energy Deposited : " << fEDep << std::endl;
  */
  fRunAction->Fill(fEDep);
  #ifdef VERBOSE
  std::cout << "--------------------------------------" << std::endl;
  #endif
}
