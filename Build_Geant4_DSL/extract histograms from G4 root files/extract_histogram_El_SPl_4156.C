
TFile *_file0 = TFile::Open("S31_Gamma4156_Eg4155.53_Tau0.0_SP0.60_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",8000,0.,8000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<8000&&DSSD1e+DSSD2e>10000&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("S31_Gamma4156_Eg4155.53_Tau0.0_SP0.60_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("S31_Gamma4156_Eg4155.53_Tau2.0_SP0.60_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",8000,0.,8000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<8000&&DSSD1e+DSSD2e>10000&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("S31_Gamma4156_Eg4155.53_Tau2.0_SP0.60_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("S31_Gamma4156_Eg4155.53_Tau4.0_SP0.60_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",8000,0.,8000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<8000&&DSSD1e+DSSD2e>10000&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("S31_Gamma4156_Eg4155.53_Tau4.0_SP0.60_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("S31_Gamma4156_Eg4155.53_Tau6.0_SP0.60_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",8000,0.,8000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<8000&&DSSD1e+DSSD2e>10000&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("S31_Gamma4156_Eg4155.53_Tau6.0_SP0.60_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("S31_Gamma4156_Eg4155.53_Tau8.0_SP0.60_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",8000,0.,8000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<8000&&DSSD1e+DSSD2e>10000&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("S31_Gamma4156_Eg4155.53_Tau8.0_SP0.60_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("S31_Gamma4156_Eg4155.53_Tau10.0_SP0.60_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",8000,0.,8000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<8000&&DSSD1e+DSSD2e>10000&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("S31_Gamma4156_Eg4155.53_Tau10.0_SP0.60_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("S31_Gamma4156_Eg4155.53_Tau14.0_SP0.60_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",8000,0.,8000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<8000&&DSSD1e+DSSD2e>10000&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("S31_Gamma4156_Eg4155.53_Tau14.0_SP0.60_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("S31_Gamma4156_Eg4155.53_Tau18.0_SP0.60_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",8000,0.,8000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<8000&&DSSD1e+DSSD2e>10000&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("S31_Gamma4156_Eg4155.53_Tau18.0_SP0.60_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();

TFile *_file0 = TFile::Open("S31_Gamma4156_Eg4155.53_Tau30.0_SP0.60_AC0.0_all.root");
TH1F *Eg=new TH1F("Eg","Eg",8000,0.,8000);
tree->Draw("Clovere>>Eg","Clovere>0&&Clovere<8000&&DSSD1e+DSSD2e>10000&&DSSD1e>100&&DSSD2e>100","");
TFile *fout = new TFile("S31_Gamma4156_Eg4155.53_Tau30.0_SP0.60_AC0.0.root","RECREATE");
Eg->Write();
fout->Close();
