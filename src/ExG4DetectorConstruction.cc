#include "ExG4DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"
#include "G4IntersectionSolid.hh"

#include "G4SDManager.hh"
#include "G4VSensitiveDetector.hh"
#include "G4ios.hh"

ExG4DetectorConstruction::ExG4DetectorConstruction() :G4VUserDetectorConstruction(), physiDSSD1(0), physiDSSD2(0), physiAu_Layer(0), physiHe_Layer1(0), physiHe_Layer2(0), physiHe_Layer3(0), physiHe_Layer4(0), physiHe_Layer5(0), physiClover(0), physiCollimator(0), physiChamber(0), physiHousing(0), silicon(0), germanium(0), gold(0), iron(0), carbon(0), csi(0), vacuum(0)
{
	Use_DSL=2; // DSL=1 or 2 is used.
}

ExG4DetectorConstruction::~ExG4DetectorConstruction()
{}

G4VPhysicalVolume* ExG4DetectorConstruction::Construct()
{
	ConstructMaterials();
	G4bool checkOverlaps = false; // use true sometimes, true slows down too much

// 	G4Tubs(const G4String &pname, // name 
// 		G4double pRmin, // inner radius 
// 		G4double pRmax, // outer radius 
// 		G4double pDz, // Z half length 
// 		G4double pSphi, // starting Phi 
// 		G4double pDphi); // segment angl

	//Coordinates:
	//upstream -z, downstream +z
	//toward the beam:
	//left -x, right +x
	//up -y, down +y
	//In this simulation, (0,0,0) is placed at the upstream surface of the gold target

	//World
	G4VSolid* solidWorld
		= new G4Box("worldBox",2*m,2*m,2*m);
	G4LogicalVolume* logicWorld
		= new G4LogicalVolume(solidWorld,vacuum,"logicWorld");
	G4VPhysicalVolume* physiWorld
		= new G4PVPlacement(0,G4ThreeVector(),logicWorld,"physiWorld",0,false,0,checkOverlaps);



	if(Use_DSL==1)//DSL1 is used. Don't change the number.
	{

		//DSSD1
		G4VSolid* solidDSSD1
			= new G4Tubs("solidDSSD1",0*mm, 6.91*mm, 0.087/2.*mm,	0.*deg, 	360.*deg);//DSL1 DE active area
		logicDSSD1
			= new G4LogicalVolume(solidDSSD1,silicon,"logicDSSD1");
		physiDSSD1
			= new G4PVPlacement(0,G4ThreeVector(0,0,22.64*mm),logicDSSD1,"physiDSSD1",logicWorld,false,0,checkOverlaps);

		//DSSD1_Frame
		G4VSolid* solidDSSD1_Frame
			= new G4Tubs("solidDSSD1_Frame",6.92*mm, 15.9*mm, 7.9/2.*mm,	0.*deg, 	360.*deg);//DSL1 DE package
		logicDSSD1_Frame
			= new G4LogicalVolume(solidDSSD1_Frame,brass,"logicDSSD1_Frame");//360 brass, also referred to as free-machining brass, is a copper-zinc alloy
		physiDSSD1_Frame
			= new G4PVPlacement(0,G4ThreeVector(0,0,22.64*mm),logicDSSD1_Frame,"physiDSSD1_Frame",logicWorld,false,0,checkOverlaps);

		//DSSD1_Window_Front
		G4VSolid* solidDSSD1_Window_Front
			= new G4Tubs("solidDSSD1_Window_Front",0*mm, 6.91*mm, 0.000080/2.*mm,	0.*deg, 	360.*deg);//DSL1 DE doped silicon dead layer window front
		logicDSSD1_Window_Front
			= new G4LogicalVolume(solidDSSD1_Window_Front,silicon,"logicDSSD1_Window_Front");
		physiDSSD1_Window_Front
			= new G4PVPlacement(0,G4ThreeVector(0,0,(22.64-0.087/2.-0.000080/2.)*mm),logicDSSD1_Window_Front,"physiDSSD1_Window_Front",logicWorld,false,0,checkOverlaps);//10-0.010/2-0.0005/2=9.99475

		//DSSD1_Window_Back
		G4VSolid* solidDSSD1_Window_Back
			= new G4Tubs("solidDSSD1_Window_Back",0*mm, 6.91*mm, 0.000225/2.*mm,	0.*deg, 	360.*deg);//DSL1 DE doped silicon dead layer window back
		logicDSSD1_Window_Back
			= new G4LogicalVolume(solidDSSD1_Window_Back,silicon,"logicDSSD1_Window_Back");
		physiDSSD1_Window_Back
			= new G4PVPlacement(0,G4ThreeVector(0,0,(22.64+0.087/2.+0.000225/2.)*mm),logicDSSD1_Window_Back,"physiDSSD1_Window_Back",logicWorld,false,0,checkOverlaps);//10+0.010/2+0.0005/2=10.00525


		//DSSD2
		G4VSolid* solidDSSD2
			= new G4Tubs("solidDSSD2",0*mm, 6.91*mm, 1./2.*mm,	0.*deg, 	360.*deg);//DSL1 Er active area
		logicDSSD2
			= new G4LogicalVolume(solidDSSD2,silicon,"logicDSSD2");
		physiDSSD2
			= new G4PVPlacement(0,G4ThreeVector(0,0,33*mm),logicDSSD2,"physiDSSD2",logicWorld,false,0,checkOverlaps);

		//DSSD2_Frame
		G4VSolid* solidDSSD2_Frame
			= new G4Tubs("solidDSSD2_Frame",6.92*mm, 13.05*mm, 7.9/2.*mm,	0.*deg, 	360.*deg);//DSL1 ER package
		logicDSSD2_Frame
			= new G4LogicalVolume(solidDSSD2_Frame,brass,"logicDSSD2_Frame");//360 brass, also referred to as free-machining brass, is a copper-zinc alloy
		physiDSSD2_Frame
			= new G4PVPlacement(0,G4ThreeVector(0,0,33*mm),logicDSSD2_Frame,"physiDSSD2_Frame",logicWorld,false,0,checkOverlaps);

		//DSSD2_Window_Front
		G4VSolid* solidDSSD2_Window_Front
			= new G4Tubs("solidDSSD2_Window_Front",0*mm, 6.91*mm, 0.000080/2.*mm,	0.*deg, 	360.*deg);//DSL1 ER doped silicon dead layer window front
		logicDSSD2_Window_Front
			= new G4LogicalVolume(solidDSSD2_Window_Front,silicon,"logicDSSD2_Window_Front");
		physiDSSD2_Window_Front
			= new G4PVPlacement(0,G4ThreeVector(0,0,(33-1.0/2.0-0.000080/2.)*mm),logicDSSD2_Window_Front,"physiDSSD2_Window_Front",logicWorld,false,0,checkOverlaps);//20-1.0/2-0.0005/2=19.49975

		//DSSD2_Window_Back
		G4VSolid* solidDSSD2_Window_Back
			= new G4Tubs("solidDSSD2_Window_Back",0*mm, 6.91*mm, 0.000225/2.*mm,	0.*deg, 	360.*deg);//DSL1 ER doped silicon dead layer window back
		logicDSSD2_Window_Back
			= new G4LogicalVolume(solidDSSD2_Window_Back,silicon,"logicDSSD2_Window_Back");
		physiDSSD2_Window_Back
			= new G4PVPlacement(0,G4ThreeVector(0,0,(33+1.0/2.0+0.000225/2.)*mm),logicDSSD2_Window_Back,"physiDSSD2_Window_Back",logicWorld,false,0,checkOverlaps);//20+1.0/2+0.0005/2=20.50025




		//DSL1 Collimator, DSL2 doesn't have a collimator
		G4VSolid* solidCollimator_Plate
			= new G4Box("solidCollimator_Plate",64.516/2.*mm,60.452/2.*mm,1.6/2.*mm);
		G4VSolid* solidCollimator_Aperture
			= new G4Tubs("solidCollimator_Aperture",0.*mm, 3.2*mm, 1.61/2.*mm,	0.*deg, 	360.*deg); // slightly thicker
		G4SubtractionSolid* solidCollimator
			= new G4SubtractionSolid("solidCollimator",solidCollimator_Plate, solidCollimator_Aperture, 0, G4ThreeVector(0.,0.,0.));
		logicCollimator
			= new G4LogicalVolume(solidCollimator,iron,"logicCollimator"); // A36 Mild/Low Carbon Steel  Composition: 98% Iron
		physiCollimator
			= new G4PVPlacement(0,G4ThreeVector(0,0,15.6*mm),logicCollimator,"physiCollimator",logicWorld,false,0,checkOverlaps);

		//DSL1 Si Detector mount
		G4VSolid* solidDetectorMount_Block
			= new G4Box("solidDetectorMount_Block",44.45/2.*mm,42.926/2.*mm,0.817*25.4/2.*mm);

		G4VSolid* solidDetectorMount_ApertureD1
			= new G4Tubs("solidDetectorMount_ApertureD1",0.*mm, (1.256*25.4/2.)*mm, (0.386*25.4)/2.+0.01*mm,	0.*deg, 	360.*deg); // slightly thicker
		G4SubtractionSolid* solidDetectorMount_Block_with_ApertureD1
			= new G4SubtractionSolid("solidDetectorMount_Block_with_ApertureD1",solidDetectorMount_Block, solidDetectorMount_ApertureD1, 0, G4ThreeVector(0.,10.3124,-(0.817/2.-0.386/2.)*25.4*mm));
		
		G4VSolid* solidDetectorMount_ApertureD2
			= new G4Tubs("solidDetectorMount_ApertureD2",0.*mm, (1.028*25.4/2.)*mm, (0.336*25.4)/2.+0.01*mm,	0.*deg, 	360.*deg); // slightly thicker
		G4SubtractionSolid* solidDetectorMount_Block_with_ApertureD1D2
			= new G4SubtractionSolid("solidDetectorMount_Block_with_ApertureD1D2",solidDetectorMount_Block_with_ApertureD1, solidDetectorMount_ApertureD2, 0, G4ThreeVector(0.,10.3124,(0.817/2.-0.336/2.)*25.4*mm));
		
		G4VSolid* solidDetectorMount_Aperture_BetweenD1andD2
			= new G4Tubs("solidDetectorMount_Aperture_BetweenD1andD2",0.*mm, (0.75*25.4/2.)*mm, (0.817-0.386-0.336)*25.4/2.+5*mm,	0.*deg, 	360.*deg); // slightly thicker
		G4SubtractionSolid* solidDetectorMount
			= new G4SubtractionSolid("DetectorMount",solidDetectorMount_Block_with_ApertureD1D2, solidDetectorMount_Aperture_BetweenD1andD2, 0, G4ThreeVector(0.,10.3124,0.));
		// "name", solid big, solid small, rotation, translation position relative to solid big
		logicDetectorMount
			= new G4LogicalVolume(solidDetectorMount,teflon,"logicDetectorMount");
		physiDetectorMount
			= new G4PVPlacement(0,G4ThreeVector(0,-((1.69/2.0-0.439)*25.4),27.1615*mm),logicDetectorMount,"physiDetectorMount",logicWorld,false,0,checkOverlaps);
		
		G4VSolid* solidDetectorSupport_Upper
			= new G4Box("solidDetectorSupport_Upper",76.2/2.*mm,4.7752/2.*mm,35.052/2.*mm);
		G4VSolid* solidDetectorSupport_Lower
			= new G4Box("solidDetectorSupport_Upper",76.2/2.*mm,4.7752/2.*mm,50.8/2.*mm);
		G4UnionSolid* solidDetectorSupport
			= new G4UnionSolid("solidDetectorSupport",solidDetectorSupport_Upper, solidDetectorSupport_Lower, 0, G4ThreeVector(0,-4.7752*mm,0));
		logicDetectorSupport
			= new G4LogicalVolume(solidDetectorSupport,stainless_steel,"logicDetectorSupport");
		physiDetectorSupport
			= new G4PVPlacement(0,G4ThreeVector(0,-34.4*mm,34*mm),logicDetectorSupport,"physiDetectorSupport",logicWorld,false,0,checkOverlaps);

		
	}//if(Use_DSL=1) DSL1 is used




	


	if(Use_DSL==2)//DSL2 is used. Don't change the number.
	{
		// switch between 0.138 and 0.074
		// switch between 0.139 and 0.075
		//DSSD1
		G4VSolid* solidDSSD1
			= new G4Box("solidDSSD1",49.5/2.*mm,49.5/2.*mm,0.074/2.*mm);//DSL2 DE active area
		logicDSSD1
			= new G4LogicalVolume(solidDSSD1,silicon,"logicDSSD1");
		physiDSSD1
			= new G4PVPlacement(0,G4ThreeVector(0,0,18.38*mm),logicDSSD1,"physiDSSD1",logicWorld,false,0,checkOverlaps);

		//DSSD1_Chip
		G4VSolid* solidDSSD1_Wafer
			= new G4Box("solidDSSD1_Wafer",53.78/2.*mm,53.78/2.*mm,0.075/2.*mm);//DE Chip inactive area
		G4VSolid* solidDSSD1_Active
			= new G4Box("solidDSSD1_Active",49.5/2.*mm,49.5/2.*mm,0.15/2.*mm);
		G4SubtractionSolid* solidDSSD1_Chip
			= new G4SubtractionSolid("solidDSSD1_Chip",solidDSSD1_Wafer, solidDSSD1_Active, 0, G4ThreeVector(0,0,0));
		logicDSSD1_Chip
			= new G4LogicalVolume(solidDSSD1_Chip,silicon,"logicDSSD1_Chip");
		physiDSSD1_Chip
			= new G4PVPlacement(0,G4ThreeVector(0,0,18.38*mm),logicDSSD1_Chip,"physiDSSD1_Chip",logicWorld,false,0,checkOverlaps);

		//DSSD1_Frame
		G4VSolid* solidDSSD1_Substrate
			= new G4Box("solidDSSD1_Substrate",67.5/2.*mm,74./2.*mm,1.6/2.*mm);
		G4VSolid* solidDSSD1_Aperture
			= new G4Box("solidDSSD1_Aperture",53.78/2.*mm,53.78/2.*mm,1.61/2.*mm);
		G4SubtractionSolid* solidDSSD1_Frame
			= new G4SubtractionSolid("solidDSSD1_Frame",solidDSSD1_Substrate, solidDSSD1_Aperture, 0, G4ThreeVector(0,(74.0/2.0-8.5-53.78/2.0)*mm,0));
		logicDSSD1_Frame
			= new G4LogicalVolume(solidDSSD1_Frame,Al2O3,"logicDSSD1_Frame");//DSL2 DE ceramic package
		physiDSSD1_Frame
			= new G4PVPlacement(0,G4ThreeVector(0,-(74.0/2.0-8.5-53.78/2.0)*mm,17.9*mm),logicDSSD1_Frame,"physiDSSD1_Frame",logicWorld,false,0,checkOverlaps);

		//DSSD1_Window_Front
		G4VSolid* solidDSSD1_Window_Front
			= new G4Box("solidDSSD1_Window_Front",49.5/2.*mm,49.5/2.*mm,0.0005/2.*mm);//DSL1 DE doped silicon dead layer window front
		logicDSSD1_Window_Front
			= new G4LogicalVolume(solidDSSD1_Window_Front,silicon,"logicDSSD1_Window_Front");
		physiDSSD1_Window_Front
			= new G4PVPlacement(0,G4ThreeVector(0,0,(18.38-0.074/2.-0.0005/2.)*mm),logicDSSD1_Window_Front,"physiDSSD1_Window_Front",logicWorld,false,0,checkOverlaps);//10-0.010/2-0.0005/2=9.99475

		//DSSD1_Window_Back
		G4VSolid* solidDSSD1_Window_Back
			= new G4Box("solidDSSD1_Window_Back",49.5/2.*mm,49.5/2.*mm,0.0005/2.*mm);//DSL1 DE doped silicon dead layer window back
		logicDSSD1_Window_Back
			= new G4LogicalVolume(solidDSSD1_Window_Back,silicon,"logicDSSD1_Window_Back");
		physiDSSD1_Window_Back
			= new G4PVPlacement(0,G4ThreeVector(0,0,(18.38+0.074/2.+0.0005/2.)*mm),logicDSSD1_Window_Back,"physiDSSD1_Window_Back",logicWorld,false,0,checkOverlaps);//10+0.010/2+0.0005/2=10.00525

		//DSSD1_Metal_Front
		G4VSolid* solidDSSD1_Metal_Front
			= new G4Box("solidDSSD1_Metal_Front", 49.5/2.*mm,49.5/2.*mm,0.0003/2.*mm);//DSL1 DE aluminum metal coverage front
		logicDSSD1_Metal_Front
			= new G4LogicalVolume(solidDSSD1_Metal_Front, aluminum, "logicDSSD1_Metal_Front");
		physiDSSD1_Metal_Front
			= new G4PVPlacement(0, G4ThreeVector(0, 0, (18.38-0.074/2.-0.0005-0.0003/2.) * mm), logicDSSD1_Metal_Front, "physiDSSD1_Metal_Front", logicWorld, false, 0, checkOverlaps);//10-0.010/2-0.0005/2=9.99475

		//DSSD1_Metal_Back
		G4VSolid* solidDSSD1_Metal_Back
			= new G4Box("solidDSSD1_Metal_Back", 49.5/2.*mm,49.5/2.*mm,0.0003/2.*mm);//DSL1 DE aluminum metal coverage back
		logicDSSD1_Metal_Back
			= new G4LogicalVolume(solidDSSD1_Metal_Back, aluminum, "logicDSSD1_Metal_Back");
		physiDSSD1_Metal_Back
			= new G4PVPlacement(0, G4ThreeVector(0, 0, (18.38+0.074/2.+0.0005+0.0003/2.) * mm), logicDSSD1_Metal_Back, "physiDSSD1_Metal_Back", logicWorld, false, 0, checkOverlaps);//10+0.010/2+0.0005/2=10.00525

		//DSSD2
		G4VSolid* solidDSSD2
			= new G4Box("solidDSSD2",49.5/2.*mm, 49.5 /2.*mm,1.010/2.*mm);//DSL2 Er active area
		logicDSSD2
			= new G4LogicalVolume(solidDSSD2,silicon,"logicDSSD2");
		physiDSSD2
			= new G4PVPlacement(0,G4ThreeVector(0,0,24.11*mm),logicDSSD2,"physiDSSD2",logicWorld,false,0,checkOverlaps);

		//DSSD2_Chip
		G4VSolid* solidDSSD2_Wafer
			= new G4Box("solidDSSD2_Wafer",53.78/2.*mm,53.78/2.*mm,1.011/2.*mm);//Er Chip inactive area
		G4VSolid* solidDSSD2_Active
			= new G4Box("solidDSSD2_Active", 49.5 /2.*mm, 49.5 /2.*mm,1.1/2.*mm);
		G4SubtractionSolid* solidDSSD2_Chip
			= new G4SubtractionSolid("solidDSSD2_Chip",solidDSSD2_Wafer, solidDSSD2_Active, 0, G4ThreeVector(0,0,0));
		logicDSSD2_Chip
			= new G4LogicalVolume(solidDSSD2_Chip,silicon,"logicDSSD2_Chip");
		physiDSSD2_Chip
			= new G4PVPlacement(0,G4ThreeVector(0,0,24.11*mm),logicDSSD2_Chip,"physiDSSD2_Chip",logicWorld,false,0,checkOverlaps);

		//DSSD2_Frame
		G4VSolid* solidDSSD2_Substrate
			= new G4Box("solidDSSD2_Substrate",67.5/2.*mm,74./2.*mm,1.6/2.*mm);
		G4VSolid* solidDSSD2_Aperture
			= new G4Box("solidDSSD2_Aperture",53.78/2.*mm,53.78/2.*mm,1.61/2.*mm);
		G4SubtractionSolid* solidDSSD2_Frame
			= new G4SubtractionSolid("solidDSSD2_Frame",solidDSSD2_Substrate, solidDSSD2_Aperture, 0, G4ThreeVector(0,(74.0/2.0-8.5-53.78/2.0)*mm,0));
		logicDSSD2_Frame
			= new G4LogicalVolume(solidDSSD2_Frame,Al2O3,"logicDSSD2_Frame");//DSL2 Er ceramic package
		physiDSSD2_Frame
			= new G4PVPlacement(0,G4ThreeVector(0,-(74.0/2.0-8.5-53.78/2.0)*mm,24.11*mm),logicDSSD2_Frame,"physiDSSD2_Frame",logicWorld,false,0,checkOverlaps);

		//DSSD2_Window_Front
		G4VSolid* solidDSSD2_Window_Front
			= new G4Box("solidDSSD2_Window_Front",49.5/2.*mm,49.5/2.*mm,0.0005/2.*mm);//DSL2 ER doped silicon dead layer window front
		logicDSSD2_Window_Front
			= new G4LogicalVolume(solidDSSD2_Window_Front,silicon,"logicDSSD2_Window_Front");
		physiDSSD2_Window_Front
			= new G4PVPlacement(0,G4ThreeVector(0,0,(24.11-1.010/2.0-0.0005/2.)*mm),logicDSSD2_Window_Front,"physiDSSD2_Window_Front",logicWorld,false,0,checkOverlaps);//20-1.0/2-0.0005/2=19.49975

		//DSSD2_Window_Back
		G4VSolid* solidDSSD2_Window_Back
			= new G4Box("solidDSSD2_Window_Back",49.5/2.*mm,49.5/2.*mm,0.0005/2.*mm);//DSL2 ER doped silicon dead layer window back
		logicDSSD2_Window_Back
			= new G4LogicalVolume(solidDSSD2_Window_Back, silicon,"logicDSSD2_Window_Back");
		physiDSSD2_Window_Back
			= new G4PVPlacement(0,G4ThreeVector(0,0,(24.11+1.010/2.0+0.0005/2.)*mm),logicDSSD2_Window_Back,"physiDSSD2_Window_Back",logicWorld,false,0,checkOverlaps);//20+1.0/2+0.0005/2=20.50025

		//DSSD2_Metal_Front
		G4VSolid* solidDSSD2_Metal_Front
			= new G4Box("solidDSSD2_Metal_Front",49.5/2.*mm,49.5/2.*mm,0.0003/2.*mm);//DSL1 DE aluminum metal coverage front
		logicDSSD2_Metal_Front
			= new G4LogicalVolume(solidDSSD2_Metal_Front, aluminum, "logicDSSD2_Metal_Front");
		physiDSSD2_Metal_Front
			= new G4PVPlacement(0, G4ThreeVector(0, 0, (24.11 - 1.010 / 2. - 0.0005 - 0.0003 / 2.) * mm), logicDSSD2_Metal_Front, "physiDSSD2_Metal_Front", logicWorld, false, 0, checkOverlaps);//10-0.010/2-0.0005/2=9.99475

		//DSSD2_Metal_Back
		G4VSolid* solidDSSD2_Metal_Back
			= new G4Box("solidDSSD2_Metal_Back",49.5/2.*mm,49.5/2.*mm,0.0003/2.*mm);//DSL1 DE aluminum metal coverage back
		logicDSSD2_Metal_Back
			= new G4LogicalVolume(solidDSSD2_Metal_Back, aluminum, "logicDSSD2_Metal_Back");
		physiDSSD2_Metal_Back
			= new G4PVPlacement(0, G4ThreeVector(0, 0, (24.11 + 1.010 / 2. + 0.0005 + 0.0003 / 2.) * mm), logicDSSD2_Metal_Back, "physiDSSD2_Metal_Back", logicWorld, false, 0, checkOverlaps);//10+0.010/2+0.0005/2=10.00525

		//DSL2 doesn't have a collimator

		//DSL2 Si Detector mount
		G4VSolid* solidDetectorMount_Block
			= new G4Box("solidDetectorMount_Block",69.85/2.*mm,100.33/2.*mm,6.35/2.*mm);

 		G4VSolid* solidDetectorMount_Aperture
 			= new G4Box("solidDetectorMount_Aperture",68.58/2.*mm,57.15/2.*mm,6.5/2.*mm); // slightly thicker
 		G4SubtractionSolid* solidDetectorMount_Block_with_Aperture
 			= new G4SubtractionSolid("solidDetectorMount_Block_with_Aperture",solidDetectorMount_Block, solidDetectorMount_Aperture, 0, G4ThreeVector(0,((17.78+25.4)/2.-17.78)*mm,0));

		G4VSolid* solidDetectorMount_ApertureUp
			= new G4Box("solidDetectorMount_ApertureUp",50.8/2.*mm,14.615/2.*mm,6.5/2.*mm);
		G4SubtractionSolid* solidDetectorMount_Block_with_TwoAperture
			= new G4SubtractionSolid("solidDetectorMount_Block_with_TwoAperture",solidDetectorMount_Block_with_Aperture, solidDetectorMount_ApertureUp, 0, G4ThreeVector(0,(100.33/2.-14.6/2.)*mm,0));

		G4VSolid* solidDetectorMount_TrapezoidSide1
			= new G4Trd("solidDetectorMount_TrapezoidSide1", 6.35/2.*mm, 6.35/2.*mm, 57.15/2.*mm, 68.8689/2.*mm, 5.715/2.*mm);
		//G4Trd* a_trd=new G4Trd("name",x,x,y,y,z);
		G4RotationMatrix* RotDetectorMount_TrapezoidSide1 = new G4RotationMatrix();
		RotDetectorMount_TrapezoidSide1-> rotateY(90*deg);
		G4UnionSolid* solidDetectorMount_Block_with_TwoAperture_with_TrapezoidSide1
			= new G4UnionSolid("solidDetectorMount_Block_with_TwoAperture_with_TrapezoidSide1",solidDetectorMount_Block_with_TwoAperture, solidDetectorMount_TrapezoidSide1, RotDetectorMount_TrapezoidSide1, G4ThreeVector((69.85/2.+5.715/2.)*mm,((17.78+25.4)/2.-17.78)*mm,0));

		G4VSolid* solidDetectorMount_TrapezoidSide2
			= new G4Trd("solidDetectorMount_TrapezoidSide2", 6.35/2.*mm, 6.35/2.*mm, 57.15/2.*mm, 68.8689/2.*mm, 5.715/2.*mm);
		G4RotationMatrix* RotDetectorMount_TrapezoidSide2 = new G4RotationMatrix();
		RotDetectorMount_TrapezoidSide2-> rotateY(270*deg);
		G4UnionSolid* solidDetectorMount_Block_with_TwoAperture_with_TwoTrapezoidSide
			= new G4UnionSolid("solidDetectorMount_Block_with_TwoAperture_with_TwoTrapezoidSide",solidDetectorMount_Block_with_TwoAperture_with_TrapezoidSide1, solidDetectorMount_TrapezoidSide2, RotDetectorMount_TrapezoidSide2, G4ThreeVector(-(69.85/2.+5.715/2.)*mm,((17.78+25.4)/2.-17.78)*mm,0));

		logicDetectorMount
			= new G4LogicalVolume(solidDetectorMount_Block_with_TwoAperture_with_TwoTrapezoidSide,aluminum,"logicDetectorMount");
		physiDetectorMount
			= new G4PVPlacement(0,G4ThreeVector(0,-75,32*mm),logicDetectorMount,"physiDetectorMount",logicWorld,false,0,checkOverlaps);
		// "name", solid big, solid small, rotation, translation position relative to solid big
	}//if(Use_DSL=2) DSL2 is used





	//Target DSL1/2 gold foil
	G4double TotalThickness = 0.02500 * mm;
	G4double AuThickness = 0.02479 * mm;
	G4double HeThickness = 0.00003 * mm; // 30 nm * 7 layers = 210 nm = 0.00021 mm

	G4VSolid* solidHe_Layer1
		= new G4Tubs("solidHe_Layer1", 0 * mm, 10.0 * mm, HeThickness / 2., 0. * deg, 360. * deg);
	logicHe_Layer1 = new G4LogicalVolume(solidHe_Layer1, low_density_Au1, "logicHe_Layer1");
	physiHe_Layer1 = new G4PVPlacement(0, G4ThreeVector(0, 0, HeThickness / 2.), logicHe_Layer1, "physiHe_Layer1", logicWorld, false, 0, checkOverlaps);

	G4VSolid* solidHe_Layer2
		= new G4Tubs("solidHe_Layer2", 0 * mm, 10.0 * mm, HeThickness / 2., 0. * deg, 360. * deg);
	logicHe_Layer2 = new G4LogicalVolume(solidHe_Layer2, low_density_Au2, "logicHe_Layer2");
	physiHe_Layer2 = new G4PVPlacement(0, G4ThreeVector(0, 0, HeThickness + HeThickness / 2.), logicHe_Layer2, "physiHe_Layer2", logicWorld, false, 0, checkOverlaps);

	G4VSolid* solidHe_Layer3
		= new G4Tubs("solidHe_Layer3", 0 * mm, 10.0 * mm, HeThickness / 2., 0. * deg, 360. * deg);
	logicHe_Layer3 = new G4LogicalVolume(solidHe_Layer3, low_density_Au3, "logicHe_Layer3");
	physiHe_Layer3 = new G4PVPlacement(0, G4ThreeVector(0, 0, HeThickness * 2 + HeThickness / 2.), logicHe_Layer3, "physiHe_Layer3", logicWorld, false, 0, checkOverlaps);

	G4VSolid* solidHe_Layer4
		= new G4Tubs("solidHe_Layer4", 0 * mm, 10.0 * mm, HeThickness / 2., 0. * deg, 360. * deg);
	logicHe_Layer4 = new G4LogicalVolume(solidHe_Layer4, low_density_Au4, "logicHe_Layer4");
	physiHe_Layer4 = new G4PVPlacement(0, G4ThreeVector(0, 0, HeThickness * 3 + HeThickness / 2.), logicHe_Layer4, "physiHe_Layer4", logicWorld, false, 0, checkOverlaps);

	G4VSolid* solidHe_Layer5
		= new G4Tubs("solidHe_Layer5", 0 * mm, 10.0 * mm, HeThickness / 2., 0. * deg, 360. * deg);
	logicHe_Layer5 = new G4LogicalVolume(solidHe_Layer5, low_density_Au5, "logicHe_Layer5");
	physiHe_Layer5 = new G4PVPlacement(0, G4ThreeVector(0, 0, HeThickness * 4 + HeThickness / 2.), logicHe_Layer5, "physiHe_Layer5", logicWorld, false, 0, checkOverlaps);

	G4VSolid* solidHe_Layer6
		= new G4Tubs("solidHe_Layer6", 0 * mm, 10.0 * mm, HeThickness / 2., 0. * deg, 360. * deg);
	logicHe_Layer6 = new G4LogicalVolume(solidHe_Layer6, low_density_Au6, "logicHe_Layer6");
	physiHe_Layer6 = new G4PVPlacement(0, G4ThreeVector(0, 0, HeThickness * 5 + HeThickness / 2.), logicHe_Layer6, "physiHe_Layer6", logicWorld, false, 0, checkOverlaps);

	G4VSolid* solidHe_Layer7
		= new G4Tubs("solidHe_Layer7", 0 * mm, 10.0 * mm, HeThickness / 2., 0. * deg, 360. * deg);
	logicHe_Layer7 = new G4LogicalVolume(solidHe_Layer7, low_density_Au7, "logicHe_Layer7");
	physiHe_Layer7 = new G4PVPlacement(0, G4ThreeVector(0, 0, HeThickness * 6 + HeThickness / 2.), logicHe_Layer7, "physiHe_Layer7", logicWorld, false, 0, checkOverlaps);

	G4VSolid* solidAu_Layer
		= new G4Tubs("solidAu_Layer", 0 * mm, 10.0 * mm, AuThickness / 2., 0. * deg, 360. * deg);
	logicAu_Layer = new G4LogicalVolume(solidAu_Layer, gold, "logicAu_Layer");
	physiAu_Layer = new G4PVPlacement(0, G4ThreeVector(0, 0, TotalThickness - AuThickness / 2.), logicAu_Layer, "physiAu_Layer", logicWorld, false, 0, checkOverlaps);

	//In this simulation, (0,0,0) is placed at the upstream surface of the first He layer
	//Each He layer is 40 nm thick (0.00004 mm) and placed sequentially so that five layers total 200 nm (0.0002 mm), followed by the Au layer starting right after the He layers at 0.0002 mm and extending to 0.0250 mm.



	//GRIFFIN Clover Ge Detector
	//make first crystal
	G4VSolid* solidClover
		= new G4Tubs("solidClover",0.*mm,30.*mm,90./2.*mm, 0.*deg, 360.*deg); //GRIFFIN
	//add flats to first crystal
	G4VSolid* flat1_1
		= new G4Box("flat1_1",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* firstflat
		= new G4SubtractionSolid("firstflat",solidClover, flat1_1, 0, G4ThreeVector(0.,58.*mm,0.));
	G4VSolid* flat1_2
		= new G4Box("flat1_2",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* secondflat
		= new G4SubtractionSolid("secondflat",firstflat, flat1_2, 0, G4ThreeVector(0.,-58.*mm,0.));
	G4VSolid* flat1_3
		= new G4Box("flat1_3",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* thirdflat
		= new G4SubtractionSolid("thirdflat",secondflat, flat1_3, 0, G4ThreeVector(58.*mm,0.,0.));
	G4VSolid* flat1_4
		= new G4Box("flat1_4",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* fourthflat
		= new G4SubtractionSolid("fourthflat",thirdflat, flat1_4, 0, G4ThreeVector(-58.*mm,0.,0.));
	//add tapers
	G4RotationMatrix* rx = new G4RotationMatrix();
	rx-> rotateX(22.5*deg);
	G4VSolid* taper1_1
		= new G4Box("taper1_1", 30.*mm,30.*mm,32.5/2.*mm);
	G4SubtractionSolid* firsttaper
		= new G4SubtractionSolid("firsttaper",fourthflat,taper1_1,rx,G4ThreeVector(0.,51.5*mm,-42.*mm));
	G4RotationMatrix* ry = new G4RotationMatrix();
	ry-> rotateY(-22.5*deg);
	G4VSolid* taper1_2
		= new G4Box("taper1_2", 30.*mm,30.*mm,32.5/2.*mm);
	G4SubtractionSolid* secondtaper
		= new G4SubtractionSolid("secondtaper",firsttaper,taper1_2,ry,G4ThreeVector(51.5*mm,0.,-42.*mm));

	//make second crystal
	G4VSolid* add1
		= new G4Tubs("add1",0.*mm,30.*mm,90./2.*mm, 0.*deg, 360.*deg);
	//add flats to second crystal
	G4VSolid* flat2_1
		= new G4Box("flat2_1",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* firstflat2
		= new G4SubtractionSolid("firstflat2",add1, flat2_1, 0, G4ThreeVector(0.,58.*mm,0.));
	G4VSolid* flat2_2
		= new G4Box("flat2_2",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* secondflat2
		= new G4SubtractionSolid("secondflat2",firstflat2, flat2_2, 0, G4ThreeVector(0.,-58.*mm,0.));
	G4VSolid* flat2_3
		= new G4Box("flat2_3",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* thirdflat2
		= new G4SubtractionSolid("thirdflat2",secondflat2, flat2_3, 0, G4ThreeVector(58.*mm,0.,0.));
	G4VSolid* flat2_4
		= new G4Box("flat2_4",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* fourthflat2
		= new G4SubtractionSolid("fourthflat2",thirdflat2, flat2_4, 0, G4ThreeVector(-58.*mm,0.,0.));
	//add tapers
	G4RotationMatrix* rx2 = new G4RotationMatrix();
	rx2-> rotateX(-22.5*deg);
	G4VSolid* taper2_1
		= new G4Box("taper2_1", 30.*mm,30.*mm,32.5*mm);
	G4SubtractionSolid* firsttaper2
		= new G4SubtractionSolid("firsttaper2",fourthflat2,taper2_1,rx2,G4ThreeVector(0.,-51.5*mm,-42.*mm));
	G4VSolid* taper2_2
		= new G4Box("taper2_2", 30.*mm,30.*mm,32.5*mm);
	G4SubtractionSolid* secondtaper2
		= new G4SubtractionSolid("secondtaper2",firsttaper2,taper2_2,ry,G4ThreeVector(51.5*mm,0.,-42.*mm));
	//add second crystal to first
	G4UnionSolid* TwoClover
		= new G4UnionSolid("TwoClover",secondtaper, secondtaper2, 0, G4ThreeVector(0.,-56.*mm,0.));

	//make third crystal
	G4VSolid* add2
		= new G4Tubs("add2",0.*mm,30.*mm,90./2.*mm, 0.*deg, 360.*deg);
	//add flats to third crystal
	G4VSolid* flat3_1
		= new G4Box("flat3_1",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* firstflat3
		= new G4SubtractionSolid("firstflat3",add2, flat3_1, 0, G4ThreeVector(0.,58.*mm,0.));
	G4VSolid* flat3_2
		= new G4Box("flat3_2",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* secondflat3
		= new G4SubtractionSolid("secondflat3",firstflat3, flat3_2, 0, G4ThreeVector(0.,-58.*mm,0.));
	G4VSolid* flat3_3
		= new G4Box("flat3_3",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* thirdflat3
		= new G4SubtractionSolid("thirdflat3",secondflat3, flat3_3, 0, G4ThreeVector(58.*mm,0.,0.));
	G4VSolid* flat3_4
		= new G4Box("flat3_4",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* fourthflat3
		= new G4SubtractionSolid("fourthflat3",thirdflat3, flat3_4, 0, G4ThreeVector(-58.*mm,0.,0.));
	//add tapers
	G4VSolid* taper3_1
		= new G4Box("taper3_1", 30.*mm,30.*mm,32.5*mm);
	G4SubtractionSolid* firsttaper3
		= new G4SubtractionSolid("firsttaper3",fourthflat3,taper3_1,rx,G4ThreeVector(0.,51.5*mm,-42.*mm));
	G4RotationMatrix* ry2 = new G4RotationMatrix();
	ry2-> rotateY(22.5*deg);
	G4VSolid* taper3_2
		= new G4Box("taper3_2", 30.*mm,30.*mm,32.5*mm);
	G4SubtractionSolid* secondtaper3
		= new G4SubtractionSolid("secondtaper3",firsttaper3,taper3_2,ry2,G4ThreeVector(-51.5*mm,0.,-42.*mm));
	//add third crystal to first two
	G4UnionSolid* ThreeClover
		= new G4UnionSolid("ThreeClover",TwoClover, secondtaper3, 0, G4ThreeVector(-56.*mm,0.,0.));

	//make fourth crystal
	G4VSolid* add3
		= new G4Tubs("add3",0.*mm,30.*mm,90./2.*mm, 0.*deg, 360.*deg);
	//add flats to fourth crystal
	G4VSolid* flat4_1
		= new G4Box("flat4_1",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* firstflat4
		= new G4SubtractionSolid("firstflat4",add3, flat4_1, 0, G4ThreeVector(0.,58.*mm,0.));
	G4VSolid* flat4_2
		= new G4Box("flat1_2",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* secondflat4
		= new G4SubtractionSolid("secondflat4",firstflat4, flat4_2, 0, G4ThreeVector(0.,-58.*mm,0.));
	G4VSolid* flat4_3
		= new G4Box("flat4_3",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* thirdflat4
		= new G4SubtractionSolid("thirdflat4",secondflat4, flat4_3, 0, G4ThreeVector(58.*mm,0.,0.));
	G4VSolid* flat4_4
		= new G4Box("flat4_4",30.*mm,30.*mm,91./2.*mm);
	G4SubtractionSolid* fourthflat4
		= new G4SubtractionSolid("fourthflat4",thirdflat4, flat4_4, 0, G4ThreeVector(-58.*mm,0.,0.));
	//add tapers
	G4VSolid* taper4_1
		= new G4Box("taper4_1", 30.*mm,30.*mm,32.5*mm);
	G4SubtractionSolid* firsttaper4
		= new G4SubtractionSolid("firsttaper4",fourthflat4,taper4_1,rx2,G4ThreeVector(0.,-51.5*mm,-42.*mm));
	G4VSolid* taper4_2
		= new G4Box("taper4_2", 30.*mm,30.*mm,32.5*mm);
	G4SubtractionSolid* secondtaper4
		= new G4SubtractionSolid("secondtaper4",firsttaper4,taper4_2,ry2,G4ThreeVector(-51.5*mm,0.,-42.*mm));
	//add fourth crystal to first three
	G4UnionSolid* FourClover
		= new G4UnionSolid("FourClover",ThreeClover, secondtaper4, 0, G4ThreeVector(-56.*mm,-56.*mm,0.));
	logicClover
		= new G4LogicalVolume(FourClover,germanium,"logicClover");
	physiClover //(78.26+148.9/2)=152.71
		= new G4PVPlacement(0,G4ThreeVector(28.*mm,28.*mm,(125.7+0.00)*mm),logicClover,"physiClover",logicWorld,false,0,checkOverlaps);


	//aluminum crystal housing
	G4VSolid* frontface
		//		= new G4Box("solidClover",110./2.*mm,110./2.*mm,1.5/2.*mm); //GRIFFIN housing
		= new G4Box("frontface",93./2.*mm,93./2.*mm,1.5/2.*mm);
	//slanted housing over tapers
	// G4VSolid* topslant
	//   = new G4Box("topslant",87.7/2.*mm,43./2.*mm,1.5/2.*mm);
	G4VSolid* topslant
		= new G4Trd("topslant",93./2.*mm, 125./2.*mm, 1.5/2.*mm, 1.5/2.*mm, 43./2.*mm);
	G4RotationMatrix* rtop = new G4RotationMatrix();
	rtop-> rotateX(22.5*deg);
	G4UnionSolid* slant1
		= new G4UnionSolid("slant1",frontface,topslant,rtop,G4ThreeVector(0,110./2.*mm,20.*mm));
	// G4VSolid* bottomslant
	//   = new G4Box("bottomslant",87.7/2.*mm,43./2.*mm,1.5/2.*mm);
	G4VSolid* bottomslant
		= new G4Trd("bottomslant",93./2.*mm, 125./2.*mm, 1.5/2.*mm, 1.5/2.*mm, 43./2.*mm);
	G4RotationMatrix* rbottom = new G4RotationMatrix();
	rbottom-> rotateX(-22.5*deg);
	G4UnionSolid* slant2
		= new G4UnionSolid("slant2",slant1,bottomslant,rbottom,G4ThreeVector(0,-110./2.*mm,20.*mm));
	// G4VSolid* rightslant
	//   = new G4Box("rightslant",43./2.*mm,87.7/2.*mm,1.5/2.*mm);
	G4VSolid* rightslant
		= new G4Trd("rightslant", 1.5/2.*mm, 1.5/2.*mm, 93./2.*mm, 125./2.*mm, 43./2.*mm);
	G4RotationMatrix* rright = new G4RotationMatrix();
	rright-> rotateY(-22.5*deg);
	G4UnionSolid* slant3
		= new G4UnionSolid("slant3",slant2,rightslant,rright,G4ThreeVector(110./2.*mm,0,20.*mm));
	// G4VSolid* leftslant
	//   = new G4Box("leftslant",43./2.*mm,87.7/2.*mm,1.5/2.*mm);
	G4VSolid* leftslant
		= new G4Trd("leftslant", 1.5/2.*mm, 1.5/2.*mm, 93./2.*mm, 125./2.*mm, 43./2.*mm);
	G4RotationMatrix* rleft = new G4RotationMatrix();
	rleft-> rotateY(22.5*deg);
	G4UnionSolid* slant4
		= new G4UnionSolid("slant4",slant3,leftslant,rleft,G4ThreeVector(-110./2.*mm,0,20.*mm));
	// //slant corners
	// G4VSolid* slantcorner1
	//   =new G4Cons("slantcorner1",1.5/2.*mm,3.0/2.*mm,13.*mm,14.5*mm,43./2.*mm,-15.*deg,115.*deg);
	// G4RotationMatrix* rcorner = new G4RotationMatrix();
	// rcorner-> rotateX(7.5*deg);
	// rcorner-> rotateY(-27.5*deg);
	// G4UnionSolid* firstcorner
	//   =new G4UnionSolid("firstcorner",slant4,slantcorner1,rcorner,G4ThreeVector(90./2.*mm,98./2.*mm,20.*mm));

	//back housing
	G4VSolid* topback
		= new G4Box("topback", 125./2.*mm, 1.5/2.*mm, 60./2.*mm);
	G4UnionSolid* back1
		= new G4UnionSolid("back1",slant4,topback,0,G4ThreeVector(0,127./2.*mm,70.*mm));
	G4VSolid* bottomback
		= new G4Box("bottomback", 125./2.*mm, 1.5/2.*mm, 60./2.*mm);
	G4UnionSolid* back2
		= new G4UnionSolid("back2",back1,bottomback,0,G4ThreeVector(0,-127./2.*mm,70.*mm));
	G4VSolid* rightback
		= new G4Box("rightback", 1.5/2.*mm, 125./2.*mm, 60./2.*mm);
	G4UnionSolid* back3
		= new G4UnionSolid("back3",back2,rightback,0,G4ThreeVector(127./2.*mm,0,70.*mm));
	G4VSolid* lefttback
		= new G4Box("leftback", 1.5/2.*mm, 125./2.*mm, 60./2.*mm);
	G4UnionSolid* back4
		= new G4UnionSolid("back4",back3,lefttback,0,G4ThreeVector(-127./2.*mm,0,70.*mm));
	logicHousing
		= new G4LogicalVolume(back4,aluminum,"logicHousing");
	physiHousing //(78.26+148.9/2)=152.71
		= new G4PVPlacement(0,G4ThreeVector(0,0,(77.7+0.00)*mm),logicHousing,"physiHousing",logicWorld,false,0,checkOverlaps);

	

	//Chamber
	G4RotationMatrix* RotChamber = new G4RotationMatrix;
	RotChamber -> rotateX(M_PI/2.*rad); // Rotates 90 degrees
	G4VSolid* solidChamber
		= new G4Tubs("solidChamber",148.59/2.*mm, 152.40/2.*mm, 209.55/2.*mm,	0.*deg, 	360.*deg); //Chamber
	logicChamber
		= new G4LogicalVolume(solidChamber,aluminum,"logicChamber"); //6061 Aluminum Alloy Composition: 98% Aluminum
	physiChamber
		= new G4PVPlacement(RotChamber,G4ThreeVector(0,0,0*mm),logicChamber,"physiChamber",logicWorld,false,0,checkOverlaps);


	// visualization attributes ------------------------------------------------

	//G4Color(G4double red=1.0,G4double green=1.0, G4double blue=1.0, G4double opacity=1.0);
	DetectorVisAtt = new G4VisAttributes(G4Colour::Red());
	logicDSSD1_Frame->SetVisAttributes(DetectorVisAtt);

	DetectorVisAtt = new G4VisAttributes(G4Colour::Blue());
	logicDSSD2_Frame->SetVisAttributes(DetectorVisAtt);

	DetectorVisAtt = new G4VisAttributes(G4Colour::Yellow());
	logicDSSD1_Window_Front->SetVisAttributes(DetectorVisAtt);
	logicDSSD1_Window_Back->SetVisAttributes(DetectorVisAtt);
	logicDSSD2_Window_Front->SetVisAttributes(DetectorVisAtt);
	logicDSSD2_Window_Back->SetVisAttributes(DetectorVisAtt);

	if (Use_DSL == 2)//if DSL2 is used; DSL1 doesn't use metal and chip
	{
		DetectorVisAtt = new G4VisAttributes(G4Colour::Gray());
		logicDSSD1_Metal_Front->SetVisAttributes(DetectorVisAtt);
		logicDSSD1_Metal_Back->SetVisAttributes(DetectorVisAtt);
		logicDSSD2_Metal_Front->SetVisAttributes(DetectorVisAtt);
		logicDSSD2_Metal_Back->SetVisAttributes(DetectorVisAtt);

		DetectorVisAtt = new G4VisAttributes(G4Colour::Brown());
		logicDSSD1_Chip->SetVisAttributes(DetectorVisAtt);
		logicDSSD2_Chip->SetVisAttributes(DetectorVisAtt);
	}
		
	DetectorVisAtt = new G4VisAttributes(G4Colour::Cyan());
	logicDSSD1->SetVisAttributes(DetectorVisAtt);
	logicDSSD2->SetVisAttributes(DetectorVisAtt);

	DetectorVisAtt = new G4VisAttributes(G4Colour::Green());
	logicDetectorMount->SetVisAttributes(DetectorVisAtt);

	DetectorVisAtt = new G4VisAttributes(G4Colour::Yellow());
	logicAu_Layer->SetVisAttributes(DetectorVisAtt); //Gold foil

	DetectorVisAtt = new G4VisAttributes(G4Colour(1.,1.,0.,0.3));
	DetectorVisAtt->SetForceWireframe(true); //optional
	//DetectorVisAtt->SetVisibility(false); //optional
	logicChamber->SetVisAttributes(DetectorVisAtt); //Chamber
	
	DetectorVisAtt = new G4VisAttributes(G4Colour::Magenta());
	logicClover->SetVisAttributes(DetectorVisAtt); //GRIFFIN Ge detector

	DetectorVisAtt = new G4VisAttributes(G4Colour(0.,1.,1.,0.3));
	logicHousing->SetVisAttributes(DetectorVisAtt); //GRIFFIN Al Housing

	if (Use_DSL==1)//if DSL1 is used
	{
		DetectorVisAtt = new G4VisAttributes(G4Colour(0.5,0.5,0.5,0.3));
		logicCollimator->SetVisAttributes(DetectorVisAtt); //DSL1 Collimator

		DetectorVisAtt = new G4VisAttributes(G4Colour::Cyan());
		logicDetectorSupport->SetVisAttributes(DetectorVisAtt); //DSL1 Detector support
	}




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

	G4bool isotopes = false;
	O = nistManager->FindOrBuildElement("O" , isotopes);
	Si = nistManager->FindOrBuildElement("Si", isotopes);
	H = nistManager->FindOrBuildElement("H", isotopes);
	C = nistManager->FindOrBuildElement("C", isotopes);
	Fe = nistManager->FindOrBuildElement("Fe", isotopes);
	Cr = nistManager->FindOrBuildElement("Cr", isotopes);
	Ni = nistManager->FindOrBuildElement("Ni", isotopes);
	Au = nistManager->FindOrBuildElement("Au", isotopes);

	G4double density_pure_Au = 19.311 * g / cm3;
	low_density_Au1 = new G4Material("low_density_Au1", 0.85* density_pure_Au, 1);
	low_density_Au1->AddElement(Au, 1);

	low_density_Au2 = new G4Material("low_density_Au2", 0.73* density_pure_Au, 1);
	low_density_Au2->AddElement(Au, 1);

	low_density_Au3 = new G4Material("low_density_Au3", 0.68 * density_pure_Au, 1);
	low_density_Au3->AddElement(Au, 1);

	low_density_Au4 = new G4Material("low_density_Au4", 0.72 * density_pure_Au, 1);
	low_density_Au4->AddElement(Au, 1);

	low_density_Au5 = new G4Material("low_density_Au5", 0.82 * density_pure_Au, 1);
	low_density_Au5->AddElement(Au, 1);

	low_density_Au6 = new G4Material("low_density_Au6", 0.94 * density_pure_Au, 1);
	low_density_Au6->AddElement(Au, 1);

	low_density_Au7 = new G4Material("low_density_Au7", 0.99 * density_pure_Au, 1);
	low_density_Au7->AddElement(Au, 1);


	germanium=nistManager->FindOrBuildMaterial("G4_Ge");
	copper=nistManager->FindOrBuildMaterial("G4_Cu");
	gold=nistManager->FindOrBuildMaterial("G4_Au");
	iron=nistManager->FindOrBuildMaterial("G4_Fe");
	carbon=nistManager->FindOrBuildMaterial("G4_C");
	hydrogen=nistManager->FindOrBuildMaterial("G4_H");
	aluminum=nistManager->FindOrBuildMaterial("G4_Al");
	silicon=nistManager->FindOrBuildMaterial("G4_Si");
	csi=nistManager->FindOrBuildMaterial("G4_CESIUM_IODIDE");
	plastic=nistManager->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");	// Scintillator	// (PolyVinylToluene, C_9H_10)
	mylar = nistManager->FindOrBuildMaterial("G4_MYLAR");
	stainless_steel=nistManager->FindOrBuildMaterial("G4_STAINLESS-STEEL");
	brass=nistManager->FindOrBuildMaterial("G4_BRASS");
	teflon=nistManager->FindOrBuildMaterial("G4_TEFLON");
	Al2O3=nistManager->FindOrBuildMaterial("G4_ALUMINUM_OXIDE");


	// vacuum
//	nistManager->FindOrBuildMaterial("G4_Galatic");

	// vacuum : air with low density
	air = nistManager->FindOrBuildMaterial("G4_AIR");
	density = 1.0e-6*air->GetDensity();
	vacuum = nistManager->BuildMaterialWithNewDensity("VACUUM","G4_AIR",density);

	//P10 Gas 780 torr
	argon = nistManager->FindOrBuildMaterial("G4_Ar");
	methane = nistManager->FindOrBuildMaterial("G4_METHANE");
	PressureFactor = 1.0263;  // 780 torr/760 torr=1.0263
	density = PressureFactor*0.001564*g/cm3; // 1564*1.0263=1605
	pressure = PressureFactor*atmosphere;
	P10_780torr = new G4Material("P10_780torr", density, nel=2, kStateGas,temperature= 293.15*kelvin, pressure);
	P10_780torr->AddMaterial(argon, 0.90);
	P10_780torr->AddMaterial(methane, 0.10);

	//Epoxy (for FR4)
	epoxy = new G4Material("epoxy", 1.2*g/cm3, 2);
	epoxy->AddElement(H, 2);
	epoxy->AddElement(C, 2);

	//Glass (for FR4)
	SiO2 = new G4Material("SiO2", 2.2*g/cm3, 2);
	SiO2->AddElement(Si, 1);
	SiO2->AddElement(O, 2);

	//FR4 (Glass + Epoxy)
	density = 1.85*g/cm3;
	FR4 = new G4Material("FR4", density, 2);
	FR4->AddMaterial(SiO2, 0.528);
	FR4->AddMaterial(epoxy, 0.472);

	PEEK = new G4Material("PEEK", 1.320*g/cm3, 3);
	PEEK -> AddElement(C, 21);
	PEEK -> AddElement(H, 18);
	PEEK -> AddElement(O, 3);

	G10 = new G4Material("G10", 1.700*g/cm3, 4);
	G10->AddElement(Si, 1);
	G10->AddElement(O, 2);
	G10->AddElement(C, 3);
	G10->AddElement(H, 3);

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

  G4VSensitiveDetector* TargetSD = new ExG4SD(SDname="/Target");//SensitiveDetectorName
  SDman->AddNewDetector(TargetSD);
  logicAu_Layer->SetSensitiveDetector(TargetSD);

  G4VSensitiveDetector* CloverSD = new ExG4SD(SDname="/Clover");//SensitiveDetectorName
  SDman->AddNewDetector(CloverSD);
  logicClover->SetSensitiveDetector(CloverSD);//attach SD to a logical volume
}
