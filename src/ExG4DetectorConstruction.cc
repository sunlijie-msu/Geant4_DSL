#include "ExG4DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

#include "G4SDManager.hh"
#include "G4VSensitiveDetector.hh"
#include "G4ios.hh"

ExG4DetectorConstruction::ExG4DetectorConstruction():G4VUserDetectorConstruction(),physiDSSD1(0),physiDSSD2(0),physiQSD1(0),physiQSD2(0),silicon(0),csi(0),vacuum(0)
{}

ExG4DetectorConstruction::~ExG4DetectorConstruction()
{}

G4VPhysicalVolume* ExG4DetectorConstruction::Construct()
{
	ConstructMaterials();
	G4bool checkOverlaps = true;

	//World
	G4VSolid* solidWorld
		= new G4Box("worldBox",2*m,2*m,2*m);
	G4LogicalVolume* logicWorld
		= new G4LogicalVolume(solidWorld,vacuum,"logicWorld");
	G4VPhysicalVolume* physiWorld
		= new G4PVPlacement(0,G4ThreeVector(),logicWorld,"physiWorld",0,false,0,checkOverlaps);

	//DSSD1
// 	G4VSolid* solidDSSD1
// 		= new G4Tubs("solidDSSD1",0*mm, 6.91*mm, 1/2.*mm,	0.*deg, 	360.*deg);//DSL1
	G4VSolid* solidDSSD1
		= new G4Box("solidDSSD1",50./2.*mm,50./2.*mm,1/2.*mm);//DSL2 ER
	logicDSSD1
		= new G4LogicalVolume(solidDSSD1,silicon,"logicDSSD1");
	physiDSSD1
		= new G4PVPlacement(0,G4ThreeVector(0,0,-20.8*mm),logicDSSD1,"physiDSSD1",logicWorld,false,0,checkOverlaps);
	//0,0,-155 is for real TIGRESS

	//DSSD2
//	G4VSolid* solidDSSD2
//		= new G4Tubs("solidDSSD2",0*mm, 6.91*mm, 0.5/2.*mm,	0.*deg, 	360.*deg);//DSL1
	G4VSolid* solidDSSD2
		= new G4Box("solidDSSD2",50/2.*mm,50/2.*mm,0.14/2.*mm);//DSL2 ΔE
	logicDSSD2
		= new G4LogicalVolume(solidDSSD2,silicon,"logicDSSD2");
	physiDSSD2
		= new G4PVPlacement(0,G4ThreeVector(0,0,-16.7*mm),logicDSSD2,"physiDSSD2",logicWorld,false,0,checkOverlaps);

	//DSSD3
	G4VSolid* solidDSSD3
		= new G4Box("solidDSSD3",45./2.*mm,45./2.*mm,90./2.*mm);
	logicDSSD3
		= new G4LogicalVolume(solidDSSD3,silicon,"logicDSSD3");
	physiDSSD3
		= new G4PVPlacement(0,G4ThreeVector(0,0,-100.*mm),logicDSSD3,"physiDSSD3",logicWorld,false,0,checkOverlaps);
	//0,0,155 is for real TIGRESS
	//QSD1
	G4VSolid* solidQSD1
		= new G4Box("solidQSD1",50./2.*mm,50./2.*mm,15460./2.*um);
	logicQSD1
		= new G4LogicalVolume(solidQSD1,germanium,"logicQSD1");
	physiQSD1
		= new G4PVPlacement(0,G4ThreeVector(0,0,45.*mm),logicQSD1,"physiQSD1",logicWorld,false,0,checkOverlaps);

	//QSD2
	G4VSolid* solidQSD2
		= new G4Tubs("solidQSD2",4*mm, 30*mm, 3/2.*mm,	0.*deg, 	360.*deg);
// 	G4VSolid* solidQSD2
// 		= new G4Box("solidQSD2",50./2.*mm,50./2.*mm,300./2.*um);
	logicQSD2
		= new G4LogicalVolume(solidQSD2,germanium,"logicQSD2");
	physiQSD2
		= new G4PVPlacement(0,G4ThreeVector(0,0,400.*mm),logicQSD2,"physiQSD2",logicWorld,false,0,checkOverlaps);

	return physiWorld;
	//   	G4Box* solidWorld= new G4Box("solidWorld",0.5*fSizeWorld[0],0.5*fSizeWorld[1],0.5*fSizeWorld[2]);
	//   	G4LogicalVolume* logicWorld= new G4LogicalVolume(solidWorld,vacuum, "logicWorld",0,0,0);
	//   	G4VPhysicalVolume* physiWorld= new G4PVPlacement(0,G4ThreeVector(0,0,0),logicWorld,"physiWorld",0,false,0);
	// 	//NaI
	// 	G4Tubs* solidDSSD1 = new G4Box("solidDSSD1",0.*cm, 5.*cm, 10.*cm, 0.*deg, 360.*deg);
	//     G4LogicalVolume* logicDSSD1= new G4LogicalVolume(solidDSSD1,germanium,"logicDSSD1",0,0,0);
	//     G4VPhysicalVolume* physiDSSD1 = new G4PVPlacement(0,G4ThreeVector(0,0,0),logicDSSD1,"physiDSSD1",logicWorld,false,0);             

	//Sensitive Detector 	
	// 	ybSD *DSSD1SD= new ybSD("DSSD1SD");	
	// 	logicDSSD1->SetSensitiveDetector( DSSD1SD );
	// 	G4SDManager* SDman = G4SDManager::GetSDMpointer();
	// 	SDman->AddNewDetector( DSSD1SD );

}

void ExG4DetectorConstruction::ConstructMaterials()
{
	G4NistManager* nistManager = G4NistManager::Instance();

	germanium=nistManager->FindOrBuildMaterial("G4_Ge");
	silicon=nistManager->FindOrBuildMaterial("G4_Si");
	csi=nistManager->FindOrBuildMaterial("G4_CESIUM_IODIDE");
	plastic=nistManager->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");	// Scintillator	// (PolyVinylToluene, C_9H_10)

	// vacuum
	nistManager->FindOrBuildMaterial("G4_Galatic");

	G4double density, temperature, pressure;
	G4int nel;
	// vacuum : air with low density
	air = nistManager->FindOrBuildMaterial("G4_AIR");
	density = 1.0e-6*air->GetDensity();
	vacuum = nistManager->BuildMaterialWithNewDensity("VACUUM","G4_AIR",density);

	//P10 Gas 780 torr
	Ar = nistManager->FindOrBuildMaterial("G4_Ar");
	G4Material *Methane = nistManager->FindOrBuildMaterial("G4_METHANE");
	G4double PressureFactor = 1.0263;  // 780 torr/760 torr=1.0263
	density = PressureFactor*0.001564*g/cm3; // 1564*1.0263=1605
	pressure = PressureFactor*atmosphere;
	P10_780torr = new G4Material("P10_780torr", density, nel=2, kStateGas,temperature= 293.15*kelvin, pressure);
	P10_780torr->AddMaterial(Ar, 0.90);
	P10_780torr->AddMaterial(Methane, 0.10);
}

void ExG4DetectorConstruction::ConstructSDandField()
{
  G4SDManager* SDman = G4SDManager::GetSDMpointer();
  G4String SDname;
  G4VSensitiveDetector* DSSD1SD = new ExG4SD(SDname="/DSSD1");//SensitiveDetectorName
  SDman->AddNewDetector(DSSD1SD);//向探测器的管理器注册
  logicDSSD1->SetSensitiveDetector(DSSD1SD);//attach SD to a logical volume

  G4VSensitiveDetector* DSSD2SD = new ExG4SD(SDname="/DSSD2");//SensitiveDetectorName
  SDman->AddNewDetector(DSSD2SD);
  logicDSSD2->SetSensitiveDetector(DSSD2SD);

  G4VSensitiveDetector* DSSD3SD = new ExG4SD(SDname="/DSSD3");//SensitiveDetectorName
  SDman->AddNewDetector(DSSD3SD);
  logicDSSD3->SetSensitiveDetector(DSSD3SD);

  G4VSensitiveDetector* QSD1SD = new ExG4SD(SDname="/QSD1");//SensitiveDetectorName
  SDman->AddNewDetector(QSD1SD);
  logicQSD1->SetSensitiveDetector(QSD1SD);//attach SD to a logical volume
}
