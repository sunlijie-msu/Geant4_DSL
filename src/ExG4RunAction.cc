#include "ExG4RunAction.hh"
#include "ExG4Analysis.hh"
#include "G4Run.hh"
#include "G4UnitsTable.hh"
//#include "G4SystemOfUnits.hh"
#include <iostream>
#include <fstream>
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

using namespace std;
ExG4RunAction::ExG4RunAction()
: G4UserRunAction()
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  G4cout<<"2$ before run, by run, ExG4RunAction::ExG4RunAction() Using "<<analysisManager->GetType()<<G4endl;

  analysisManager->SetVerboseLevel(1);
  //analysisManager->SetFileName("ExG4");//root filename

  //Book histograms, ntuple
  //

  analysisManager->CreateH1("h1DSSD1n","h1DSSD1n",10,0.,10.); // h1 ID=0, the range may be not suitable, the results are subject to nt
  analysisManager->CreateH1("h1DSSD2n","h1DSSD2n",10,0.,10.); // h1 ID=1, the range may be not suitable, the results are subject to nt
  analysisManager->CreateH1("h1Targetn","h1Targetn",10,0.,10.); // h1 ID=2, the range may be not suitable, the results are subject to nt
  analysisManager->CreateH1("h1DSSD1e","h1DSSD1e",60000,0.,60000); // h1 ID=3//6000 is range, in what unit is defined in FillH1
  analysisManager->CreateH1("h1DSSD2e","h1DSSD2e",60000,0.,60000); // h1 ID=4//6000 is range, in what unit is defined in FillH1
  analysisManager->CreateH1("h1Targete","h1Targete",60000,0.,60000); // h1 ID=5//6000 is range, in what unit is defined in FillH1
  analysisManager->CreateH1("h1Clovere","h1Clovere",10000,0.,10000); // h1 ID=6//6000 is range, in what unit is defined in FillH1
  analysisManager->CreateH2("DSSD1XY","DSSD1XY",100,75.,125.,100,75.,125.); // h2 ID = 0
  analysisManager->CreateH2("DSSD2XY","DSSD2XY",100,75.,125.,100,75.,125.); // h2 ID = 1
  analysisManager->CreateH2("TargetXY","TargetXY",80,96.,104.,80,96.,104.); // h2 ID = 2
  //CreatH1(name,title,nbins,vmin,vmax)
  //analysisManager/h1set hID nxbin xmin xmax [xunit] [xfcn] [xfcn] [binscheme]
  //analysisManager/h2set hID nxbin xmin xmax xunit xfcn nybin ymin ymax yunit yfcn
  //histogram IDs are attributed automatically. 1D and 2D histograms IDs are defined independently
  analysisManager->CreateNtuple("tree","tree");
  analysisManager->CreateNtupleIColumn("DSSD1n"); //nt ID = 0
  analysisManager->CreateNtupleDColumn("DSSD1e"); //nt ID = 1
  analysisManager->CreateNtupleDColumn("DSSD1x");  //nt ID = 2
  analysisManager->CreateNtupleDColumn("DSSD1y");  //nt ID = 3
  analysisManager->CreateNtupleDColumn("DSSD1z");  //nt ID = 4
  analysisManager->CreateNtupleDColumn("DSSD1t");  //nt ID = 5

  analysisManager->CreateNtupleIColumn("DSSD2n"); //nt ID = 6
  analysisManager->CreateNtupleDColumn("DSSD2e"); //nt ID = 7
  analysisManager->CreateNtupleDColumn("DSSD2x");  //nt ID = 8
  analysisManager->CreateNtupleDColumn("DSSD2y");  //nt ID = 9
  analysisManager->CreateNtupleDColumn("DSSD2z");  //nt ID = 10
  analysisManager->CreateNtupleDColumn("DSSD2t");  //nt ID = 11

  analysisManager->CreateNtupleIColumn("Targetn"); //nt ID = 12
  analysisManager->CreateNtupleDColumn("Targete"); //nt ID = 13
  analysisManager->CreateNtupleDColumn("Targetx");  //nt ID = 14
  analysisManager->CreateNtupleDColumn("Targety");  //nt ID = 15
  analysisManager->CreateNtupleDColumn("Targetz");  //nt ID = 16
  analysisManager->CreateNtupleDColumn("Targett");  //nt ID = 17
  
  analysisManager->CreateNtupleIColumn("Clovern"); //nt ID = 18
  analysisManager->CreateNtupleDColumn("Clovere"); //nt ID = 19
  analysisManager->CreateNtupleDColumn("Cloverx");  //nt ID = 20
  analysisManager->CreateNtupleDColumn("Clovery");  //nt ID = 21
  analysisManager->CreateNtupleDColumn("Cloverz");  //nt ID = 22
  analysisManager->CreateNtupleDColumn("Clovert");  //nt ID = 23

}

ExG4RunAction::~ExG4RunAction()
{
	G4cout<<"7$ after run, by run,ExG4RunAction::~ExG4RunAction()"<<G4endl;
	delete G4AnalysisManager::Instance();
}

void ExG4RunAction::BeginOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  //analysisManager->OpenFile("/mnt/hgfs/out/G4_rootfiles_with_tree_Eg4156/ExG4.root");//output root file modify
  analysisManager->OpenFile("Em/ExG4.root");//output root file
  //ofstream outresultfile("out.txt",ios::out);//定义输出文件流对象outbeamfile，以输出方式打开磁盘文件，这里是by run的。
  G4cout<<"5$ first in run, by run, ExG4RunAction::BeginOfRunAction(const G4Run*)"<<G4endl;
}

void ExG4RunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  //G4cout<<analysisManager->GetH1(2)->mean()<<G4endl;
  analysisManager->Write();
  analysisManager->CloseFile();
  G4cout<<"6$ last in run, by run, ExG4RunAction::EndOfRunAction(const G4Run*)"<<G4endl;
}
