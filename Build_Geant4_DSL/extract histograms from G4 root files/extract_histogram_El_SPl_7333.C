
TFile *_file0 = TFile::Open("Mg23_Gamma7333_Eg7331.20_Tau0.0_SP0.90_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",10000,0.,10000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<10000&&DSSD1e+DSSD2e>100&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("Mg23_Gamma7333_Eg7331.20_Tau0.0_SP0.90_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("Mg23_Gamma7333_Eg7331.20_Tau5.0_SP0.90_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",10000,0.,10000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<10000&&DSSD1e+DSSD2e>100&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("Mg23_Gamma7333_Eg7331.20_Tau5.0_SP0.90_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("Mg23_Gamma7333_Eg7331.20_Tau10.0_SP0.90_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",10000,0.,10000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<10000&&DSSD1e+DSSD2e>100&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("Mg23_Gamma7333_Eg7331.20_Tau10.0_SP0.90_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("Mg23_Gamma7333_Eg7331.20_Tau15.0_SP0.90_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",10000,0.,10000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<10000&&DSSD1e+DSSD2e>100&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("Mg23_Gamma7333_Eg7331.20_Tau15.0_SP0.90_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("Mg23_Gamma7333_Eg7331.20_Tau20.0_SP0.90_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",10000,0.,10000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<10000&&DSSD1e+DSSD2e>100&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("Mg23_Gamma7333_Eg7331.20_Tau20.0_SP0.90_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();
