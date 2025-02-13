#ifndef ExG4DetectorConstruction_h
#define ExG4DetectorConstruction_h

#include "G4VUserDetectorConstruction.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4NistManager.hh"
#include "G4FieldManager.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh" 
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4SDManager.hh"
#include "G4VSensitiveDetector.hh"
#include "globals.hh"
#include "G4ios.hh"
#include "ExG4SD.hh"
#include <vector>

class G4VPhysicalVolume;
class G4Material;
class G4VSensitiveDetector;
class G4VisAttributes;
class G4GenericMessenger;

//Detector construction
class ExG4DetectorConstruction : public G4VUserDetectorConstruction
{
public:
    ExG4DetectorConstruction();
    virtual ~ExG4DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();
    
    void ConstructMaterials();

private:
	G4VPhysicalVolume* physiDSSD1;
	G4VPhysicalVolume* physiDSSD1_Chip;
	G4VPhysicalVolume* physiDSSD1_Frame;
	G4VPhysicalVolume* physiDSSD1_Window_Front;
	G4VPhysicalVolume* physiDSSD1_Metal_Front;
	G4VPhysicalVolume* physiDSSD1_Window_Back;
	G4VPhysicalVolume* physiDSSD1_Metal_Back;
	G4VPhysicalVolume* physiDSSD2;
	G4VPhysicalVolume* physiDSSD2_Chip;
	G4VPhysicalVolume* physiDSSD2_Frame;
	G4VPhysicalVolume* physiDSSD2_Window_Front;
	G4VPhysicalVolume* physiDSSD2_Metal_Front;
	G4VPhysicalVolume* physiDSSD2_Window_Back;
	G4VPhysicalVolume* physiDSSD2_Metal_Back;
	G4VPhysicalVolume* physiDetectorMount;
	G4VPhysicalVolume* physiDetectorSupport;
	G4VPhysicalVolume* physiAu_Layer;
	G4VPhysicalVolume* physiHe_Layer1;
	G4VPhysicalVolume* physiHe_Layer2;
	G4VPhysicalVolume* physiHe_Layer3;
	G4VPhysicalVolume* physiHe_Layer4;
	G4VPhysicalVolume* physiHe_Layer5;
	G4VPhysicalVolume* physiHe_Layer6;
	G4VPhysicalVolume* physiHe_Layer7;
	G4VPhysicalVolume* physiClover;
	G4VPhysicalVolume* physiCollimator;
	G4VPhysicalVolume* physiChamber;
	G4VPhysicalVolume* physiHousing;

	G4LogicalVolume* logicDSSD1;
	G4LogicalVolume* logicDSSD1_Chip;
	G4LogicalVolume* logicDSSD1_Frame;
	G4LogicalVolume* logicDSSD1_Window_Front;
	G4LogicalVolume* logicDSSD1_Metal_Front;
	G4LogicalVolume* logicDSSD1_Window_Back;
	G4LogicalVolume* logicDSSD1_Metal_Back;
	G4LogicalVolume* logicDSSD2;
	G4LogicalVolume* logicDSSD2_Chip;
	G4LogicalVolume* logicDSSD2_Frame;
	G4LogicalVolume* logicDSSD2_Window_Front;
	G4LogicalVolume* logicDSSD2_Metal_Front;
	G4LogicalVolume* logicDSSD2_Window_Back;
	G4LogicalVolume* logicDSSD2_Metal_Back;
	G4LogicalVolume* logicDetectorMount;
	G4LogicalVolume* logicDetectorSupport;
	G4LogicalVolume* logicAu_Layer;
	G4LogicalVolume* logicHe_Layer1;
	G4LogicalVolume* logicHe_Layer2;
	G4LogicalVolume* logicHe_Layer3;
	G4LogicalVolume* logicHe_Layer4;
	G4LogicalVolume* logicHe_Layer5;
	G4LogicalVolume* logicHe_Layer6;
	G4LogicalVolume* logicHe_Layer7;
	G4LogicalVolume* logicClover;
	G4LogicalVolume* logicCollimator;
	G4LogicalVolume* logicChamber;
	G4LogicalVolume* logicHousing;

	//Materials
	G4Element* O;
	G4Element* Si;
	G4Element* H;
	G4Element* C;
	G4Element* Fe;
	G4Element* Cr;
	G4Element* Ni;
	G4Element* Au;

	G4Material* silicon;
	G4Material* germanium;
	G4Material* copper;
	G4Material* gold;
	G4Material* iron;
	G4Material* carbon;
	G4Material* hydrogen;
	G4Material* aluminum;
	G4Material* csi;
	G4Material* vacuum;
	G4Material* plastic;
	G4Material *P10_780torr;
	G4Material *air;
	G4Material *methane;
	G4Material *argon;
	G4Material* mylar;
	G4Material* stainless_steel;
	G4Material* brass;
	G4Material* teflon;
	G4Material* Al2O3;
	G4Material* SiO2;
	G4Material* epoxy;
	G4Material* FR4;
	G4Material* PEEK;
	G4Material* G10;
	G4Material* low_density_Au1;
	G4Material* low_density_Au2;
	G4Material* low_density_Au3;
	G4Material* low_density_Au4;
	G4Material* low_density_Au5;
	G4Material* low_density_Au6;
	G4Material* low_density_Au7;

	G4double density, temperature, pressure, PressureFactor;
	G4int nel;

	G4int Use_DSL;              //flag to determine whether DSL1/2 is used
	G4VisAttributes* DetectorVisAtt;
};

#endif
