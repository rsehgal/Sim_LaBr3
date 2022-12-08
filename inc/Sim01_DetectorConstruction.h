#ifndef Sim01_DetectorConstruction_h
#define Sim01_DetectorConstruction_h 

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VUserDetectorConstruction;
class G4VPhysicalVolume;
class G4LogicalVolume;

class Sim01_DetectorConstruction : public G4VUserDetectorConstruction
{
public:
	Sim01_DetectorConstruction();
	~Sim01_DetectorConstruction();
	G4VPhysicalVolume* Construct();
};
#endif