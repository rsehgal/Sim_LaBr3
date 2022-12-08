#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Element.hh"
#include "G4Isotope.hh"
#include "G4LogicalVolume.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Orb.hh"
#include "G4PVPlacement.hh"
#include "G4RunManager.hh"
#include "G4Sphere.hh"
#include "G4SystemOfUnits.hh"
#include "G4Trd.hh"
#include "G4UnitsTable.hh"
#include "G4VPhysicalVolume.hh"
#include "Sim01_DetectorConstruction.h"
#include "G4Tubs.hh"
Sim01_DetectorConstruction::Sim01_DetectorConstruction() {}

Sim01_DetectorConstruction::~Sim01_DetectorConstruction() {}

G4VPhysicalVolume *Sim01_DetectorConstruction::Construct() {

  G4NistManager *nist = G4NistManager::Instance();
  G4bool checkOverlaps = true;

  //
  // World
  //
  G4double world_sizeXYZ = 200 * cm;
  //G4Material *world_mat = nist->FindOrBuildMaterial("G4_AIR");
  G4Material *world_mat = nist->FindOrBuildMaterial("G4_Galactic");

  G4Box *solidWorld = new G4Box("World",                                                        // its name
                                0.5 * world_sizeXYZ, 0.5 * world_sizeXYZ, 0.5 * world_sizeXYZ); // its size

  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, // its solid
                                                    world_mat,  // its material
                                                    "World");   // its name

  G4VPhysicalVolume *physWorld = new G4PVPlacement(0,               // no rotation
                                                   G4ThreeVector(), // at (0,0,0)
                                                   logicWorld,      // its logical volume
                                                   "World",         // its name
                                                   0,               // its mother  volume
                                                   false,           // no boolean operation
                                                   0,               // copy number
                                                   checkOverlaps);  // overlaps checking

  // Lets try to build material from NIST database
  /*G4Box *leadBlock = new G4Box("LeadBlock", 5. * cm, 5. * cm, 5. * cm);
  G4Material *Pb = nist->FindOrBuildMaterial("G4_Pb");
  G4LogicalVolume *logicalLeadBlock = new G4LogicalVolume(leadBlock, Pb, "LogicalLeadBlock");
  G4VPhysicalVolume *phyLeadBlock =    new G4PVPlacement(0,
				                        // G4ThreeVector(),
				                        G4ThreeVector(), 
							logicalLeadBlock, 
							"Physical_Lead_Block", 
							logicWorld, 
							false, 
							0, 
							checkOverlaps);
*/
G4double z,a;
  
  G4Material *nai = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
  G4Element* La = new G4Element("Lanthanum",  "La" , z= 57., a= 138.91*g/mole);
  G4Element* Br = new G4Element("Bromine",   "Br", z= 35., a= 79.90*g/mole);
  G4Tubs *labr3 = new G4Tubs("LaBr3",0.,1.5*cm,1.5*cm,0.,2*M_PI);
  G4double density;
  G4int ncomponents, natoms;
  G4double fractionmass;  
  G4Material* LaBr3 = new G4Material("LaBr3", density= 5.06*g/cm3, ncomponents=2);
  LaBr3->AddElement(La, fractionmass = 0.366875);
  LaBr3->AddElement(Br ,fractionmass = 0.633124);
  LaBr3->GetIonisation()->SetMeanExcitationEnergy(454.5*eV);
  G4LogicalVolume *logicalLaBr3 = new G4LogicalVolume(labr3, LaBr3, "Logical_LaBr3");
  //G4LogicalVolume *logicalLaBr3 = new G4LogicalVolume(labr3, nai, "Logical_LaBr3");
  G4VPhysicalVolume *phyLaBr3 =    new G4PVPlacement(0,
                                                        // G4ThreeVector(),
                                                        G4ThreeVector(), 
                                                        logicalLaBr3, 
                                                        "Physical_LaBr3", 
                                                        logicWorld, 
                                                        false, 
                                                        0, 
                                                        checkOverlaps);

  return physWorld;
}
