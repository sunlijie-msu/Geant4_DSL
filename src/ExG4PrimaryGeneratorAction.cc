#include "ExG4PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"

#include "G4DynamicParticle.hh"
#include "G4PhysicalConstants.hh"
//#include "G4SystemOfUnits.hh"
#include "G4DecayProducts.hh"
#include "G4LorentzVector.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"
#include "G4PrimaryParticle.hh"
#include "Randomize.hh"
using namespace std;
ExG4PrimaryGeneratorAction::ExG4PrimaryGeneratorAction()
	: G4VUserPrimaryGeneratorAction(),
	fParticleGun(0)
{
	// The basic units are :
	//		millimeter              (millimeter)
	// 		nanosecond              (nanosecond)
	// 		Mega electron Volt      (MeV)
	// 		positron charge         (eplus)
	// 		degree Kelvin           (kelvin)
	//      the amount of substance (mole)
	//      luminous intensity      (candela)
	// 		radian                  (radian)
	//      steradian               (steradian)
	//	To output the data on the unit you wish you must divide the data by the corresponding unit.
		// /CLHEP::keV is equivalent to *1000
		// *CLHEP::keV is equivalent to /1000

	G4int nofParticles = 1;
	fParticleGun = new G4ParticleGun(nofParticles);

	// 	xygaus = new TF2("xygaus","xygaus",-15,15,-15,15);// predefined 2D Gaussian function  // 2D Gaussian beam spot
	// 	xygaus->SetParameters(1,0,3,0,3); // amplitude, mean_x, sigma_x, mean_y, sigma_y  in units of mm. // 2D Gaussian beam spot
	// 	xygaus->SetNpx(200);  // 2D Gaussian beam spot
	// 	xygaus->SetNpy(200);  // 2D Gaussian beam spot
	Rmax = 1.0 * CLHEP::mm;  // 2D Uniform beam spot // in units of mm. G4ThreeVector(mm)

	pFile = new TFile("depth.root", "read"); // put the depth.root file under the build directory
	//pFile=new TFile("/mnt/hgfs/HPGe/P26_pz.root","read");
	//pFile=new TFile("/mnt/hgfs/HPGe/Si25_pz.root","read");
	//pFile=new TFile("/mnt/hgfs/HPGe/Al22_pz.root","read");
	//pFile=new TFile("/mnt/hgfs/HPGe/S27simulate.root","read");
	//fout = fopen ("out.txt", "w");

//	numpeaks=1;//23 or 53 for 29Na, 46 or 88 for 30Na. with Doppler, 62 for 29Na, 1 for test
//	branch_lit_tot=0;
	//fin=fopen ("/mnt/hgfs/HPGe/Gamma30Naprecursor.dat","r");
//	wheretorun=3;
// 	if(wheretorun==1)//fishtank
// 	{
// 		ifstream fin("/user/sunli/HPGe/Gamma29Nadoppler.dat",ios::in);//fishtank下fscanf %lf报错
// 		for(int ii=0;ii<numpeaks;ii++)//fishtank
// 		{
// 			fin>>Eg_lit[ii]>>branch_lit[ii]>>En_lit[ii]>>Halflife_lit[ii];//Ecm keV; 1 ps = 0.001
// 		}//fishtank
// 	}
// 	if(wheretorun==2)//VMware
// 	{
// 		FILE *fin=fopen ("/mnt/hgfs/HPGe/Gamma29Nadoppler.dat","r");//VMware下ifstream报错
// 		for(int ii=0;ii<numpeaks;ii++)//VMware
// 	 	{
// 	 		fscanf(fin, "%lf", &Eg_lit[ii]);//keV
// 	 		fscanf(fin, "%lf", &branch_lit[ii]);
// 	 		fscanf(fin, "%lf", &En_lit[ii]);//Ecm keV
// 	 		fscanf(fin, "%lf", &Halflife_lit[ii]);//1 ps = 0.001
// 		}//VMware
// 	}
// 	if(wheretorun==3)//VMware test
// 	{
// 		FILE *fin=fopen ("/mnt/hgfs/HPGe/Onetest.dat","r");//VMware下ifstream报错
// 		for(int ii=0;ii<numpeaks;ii++)//VMware
// 		{
// 			fscanf(fin, "%lf", &Eg_lit[ii]);//keV
// 			fscanf(fin, "%lf", &branch_lit[ii]);
// 			fscanf(fin, "%lf", &En_lit[ii]);//Ecm keV
// 			fscanf(fin, "%lf", &Halflife_lit[ii]);//1 ps = 0.001
// 		}//VMware
// 	}
// 	for(int ii=0;ii<numpeaks;ii++)
// 	{
// 		branch_lit_tot+=branch_lit[ii];
// 		branch_lit_integ[ii]=branch_lit_tot;
// 	}
// 	for(int ii=0;ii<numpeaks+1;ii++)
// 	{
// 		G4cout<<"Eg=	"<<Eg_lit[ii]<<"	keV	br=	"<<branch_lit[ii]<<"	integ=	"<<branch_lit_integ[ii]<<"	En=	"<<En_lit[ii]<<"	keV	T=	"<<Halflife_lit[ii]<<"	ns"<<G4endl;
// 	}
// 	G4cout<<"brtot=	"<<branch_lit_tot<<G4endl;
	//std::ofstream outfile(filename,std::ios::out);//定义输出文件流对象outfile，以输出方式打开磁盘文件, formerly non-existent file can be created automatically
	depth_3He = new TH1F("depth_3He", "depth_3He", 100, -1.5, 298.5);//unit nm, this statement cannot be eliminated, the new TH1F cannot be named the same as the TH1F in the input root
	// 	py_impl = new TH1F("py_impl","py_impl", 50,-25,25);//unit mm, this statement cannot be eliminated, the new TH1F cannot be named the same as the TH1F in the input root
	// 	pz_impl = new TH1D("pz_impl","pz_impl", 100,0,100);//unit um, this statement cannot be eliminated, the new TH1F cannot be named the same as the TH1F in the input root
	G4cout<<"1$ before run, by run, ExG4PrimaryGeneratorAction::ExG4PrimaryGeneratorAction()"<<G4endl;
}

ExG4PrimaryGeneratorAction::~ExG4PrimaryGeneratorAction()
{
	G4cout << "8$ after run, by run, ExG4PrimaryGeneratorAction::~ExG4PrimaryGeneratorAction()" << G4endl;
	pFile->Close();
	//fclose(fout);
	//	fclose(fin);//VMware
	delete fParticleGun;
}

void ExG4PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	//G4cout<<"(1)$ before event, by event, ExG4PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)"<<G4endl;
	gRandom->SetSeed(0);
	//	xygaus->GetRandom2(x0,y0); // 2D Gaussian beam spot  // Return two random numbers to x0 and y0 following this function shape.
	r_beam = sqrt(gRandom->Uniform(0, 1)) * Rmax;  // 2D Uniform beam spot
	theta_beam = gRandom->Uniform(0, 2. * 3.14159);  // 2D Uniform beam spot
	x0 = r_beam * cos(theta_beam);  // 2D Uniform beam spot
	y0 = r_beam * sin(theta_beam);  // 2D Uniform beam spot
	depth_3He = (TH1F*)pFile->Get("depth");//Get("depth");//read implantation depth from root for 3He-implanted gold target
	z0 = depth_3He->GetRandom() * CLHEP::nm;//Return a random number distributed according the histogram depth_3He
	// 	z0=gRandom->Gaus(4.600,0.420)*CLHEP::um; // test for Nick's target implanted at LLNL
	// 	if(z0<0) z0=0; // test for Nick's target implanted at LLNL
	//G4cout<<"++++++++++++  x0="<<x0/CLHEP::mm<<"  y0="<<y0/CLHEP::mm<<"  z0="<<z0/CLHEP::nm<<G4endl;

		//py_impl=(TH1F*)pFile->Get("himpl40py");//Get("hy2");//from implantation root for DSSD2
		//pz_impl=(TH1D*)pFile->Get("himpl40pz");//Get("hz2");//from implantation root for DSSD2
		//	px_impl=(TH1F*)pFile->Get("himpl304px");//Get("hx2");//from implantation root for Target
		//	py_impl=(TH1F*)pFile->Get("himpl304py");//Get("hy2");//from implantation root for Target
		//	pz_impl=(TH1D*)pFile->Get("himpl304pz");//Get("hz2");//from implantation root for Target
		//	y0=py_impl->GetRandom()*CLHEP::mm;//from implantation root for both DSSD2\3
		//	z0=pz_impl->GetRandom()*0.001*CLHEP::mm;//from implantation root for both DSSD2\3
		//	for(;x0>49.5/2||x0<-49.5/2;){x0=px_impl->GetRandom()*CLHEP::mm;}//from implantation root for both DSSD2\3. To ensure an appropriate x0.
		//	for(;y0<-49.5/2||y0>49.5/2;){y0=py_impl->GetRandom()*CLHEP::mm;}//from implantation root for both DSSD2\3. To ensure an appropriate y0.
		//if(x0>49.5/2||x0<-49.5/2||y0<-49.5/2||y0>49.5/2)fprintf(fp, "%f%s%f\n", x0," ",y0); 
		//for(;z0>0.04;){z0=pz_impl->GetRandom()*0.001*CLHEP::mm;};To ensure an appropriate DSSD2 z0.
		//z0=0-0.040/2.0+z0;//from implantation root for DSSD2.
		//	z0=19-0.304/2.0+z0;//from implantation root for Target
		//x0=G4UniformRand();
		//x0=0; y0=0; z0=0*CLHEP::mm;//fixed point
		//G4cout<<pz300->GetMean()<<G4endl;
		//G4cout<<"yangbiao test : RMS of h1 is "<<((TH1F*)pFile->Get("h1"))->GetMean()<<G4endl;

	//	branch_integ=CLHEP::RandFlat::shoot(0.0,branch_lit_tot);

		//EMG response function
	// 	TF1 *EMGf1=new TF1("EMGf1","[0]*[3]/[1]*1.253314137*TMath::Exp(0.5*([3]*[3]/[1]/[1])+(x-[2])/[1])*TMath::Erfc(1/1.41421356*([3]/[1]+(x-[2])/[3]))",Excitation_recoil-50,Excitation_recoil+50);//Glassman_PRC2019
	// 	EMGf1->SetNpx(5000);//Set the number of points used to draw the function. [0]-N, [1]-τ, [2]-μ, [3]-σ,
	// 	// normalized cumulative Probability Density Function
	// 	TF1 *EMGf2=new TF1("EMGf2","[0]/2*(TMath::Exp((0.5*[3]*[3]-[1]*[2]+[1]*x)/([1]*[1]))*TMath::Erfc(1/1.41421356*([3]/[1]+(x-[2])/[3]))-TMath::Erfc((x-[2])/(1.41421356*[3])))+1",Excitation_recoil-50,Excitation_recoil+50);//Glassman_PRC2019
	// 	EMGf2->SetNpx(5000);//Set the number of points used to draw the function.
	// 
	// 	emg_sigp1= 0.00011508152;
	// 	emg_sigp0= 1.142295;
	// 	emg_taup1= 0.000823321;
	// 	emg_taup0= -0.354105;
	//	emg_sig = emg_sigp1*Excitation_recoil + emg_sigp0;
	// 	emg_tau = emg_taup1*Excitation_recoil + emg_taup0;
	// 
	// 	EMGf2->SetParameter(0,1.);//N
	// 	EMGf2->SetParameter(1,emg_tau);//τ
	// 	EMGf2->SetParameter(2,Excitation_recoil);//μ
	// 	EMGf2->SetParameter(3,emg_sig);//σ
	// 	Excitation_recoil = EMGf2->GetX(G4RandFlat::shoot(0.0,1.0), Excitation_recoil-50,Excitation_recoil+50);//After this, Excitation_recoil is the experimentally detected gamma energy
		//G4cout<<"Excitation_recoil = "<<Excitation_recoil<<G4endl;
		//G4cout<<"rundomnumber = "<<G4UniformRand()<<G4endl;
		//G4cout<<"rundomnumber = "<<G4RandFlat::shoot(0.0,1.0)<<G4endl;



	// 	if (branch_integ<branch_lit_integ[0])
	// 	{
	// 		Excitation_recoil=Eg_lit[0]*CLHEP::keV;
	// 		Erecoil=En_lit[0]*Aejectile/(Arecoil+Aejectile)*CLHEP::keV;
	// 		tau=1.443*Halflife_lit[0]*CLHEP::ns;
	// 	} 	
	// 	for(int ii=1;ii<numpeaks;ii++)
	// 	{
	// 		if(branch_integ>=branch_lit_integ[ii-1]&&branch_integ<branch_lit_integ[ii])
	// 		{
	// 			Excitation_recoil=Eg_lit[ii]*CLHEP::keV;
	// 			Erecoil=En_lit[ii]*Aejectile/(Arecoil+Aejectile)*CLHEP::keV;
	// 			tau=1.443*Halflife_lit[ii]*CLHEP::ns;
	// 		}
	// 	}
	//	tau=0.01*CLHEP::ns;//this is lifetime τ = 1.443*T1/2; 1 ps = 0.001 ns; 10 fs = 0.00001 ns //simplified test
	//	Erecoil=200*CLHEP::keV; Excitation_recoil=2000*CLHEP::keV; tau=0.000010*CLHEP::ns;//simplified test
	//	resolution=1.010473*pow(Excitation_recoil/CLHEP::keV,-0.888665);//resolution becomes better for high energy gamma
	//	if(Excitation_recoil<122*CLHEP::keV)
	//	{
	//		Excitation_recoil=G4RandGauss::shoot(Excitation_recoil,0.001414/2.355*Excitation_recoil);//sigma resolution, 0.01/2.355 means 1%//slow down the speed by a factor of 10
	//		//G4cout<<Excitation_recoil/CLHEP::keV<<"	"<<resolution<<G4endl;
	//	}
	//	Excitation_recoil width should be added in PrimaryGeneratorAction.cc, while detector resolution should be added in EventAction.cc
	//	Excitation_recoil=G4RandGauss::shoot(Excitation_recoil,resolution/2.355*Excitation_recoil);//sigma resolution, 0.01/2.355 means 1%//slow down the speed by a factor of 10
	//	Erecoil=G4RandGauss::shoot(Erecoil,0.01/2.355*Erecoil);

		//G4ParticleDefinition* particle = G4IonTable::GetIonTable()->GetIon(12,26,0); //28Mg: GetIon(12,28,0); 
		//G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("proton");
		//G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
		//G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("e+");
		//particle->SetProperTime(0.0);// seems useless

		//	G4cout<<"------- Er="<<Erecoil/CLHEP::keV<<" keV"<<"	branch_integ="<<branch_integ<<"	Eg=	"<<Excitation_recoil/CLHEP::keV<<"	T=	"<<0.69315*particle->GetPDGLifeTime()/CLHEP::ns<<"	ns"<<G4endl;
		//G4cout<<"	life=	"<<tau/CLHEP::ns<<"	ns	"<<particle->GetPDGLifeTime()/CLHEP::ns<<"	ns"<<G4endl;
		//G4DynamicParticle* particle = new G4DynamicParticle();

	//  	costheta_p1=CLHEP::RandFlat::shoot(-1,1);//isotropic particle
	//  	phi_p1=CLHEP::RandFlat::shoot(0.,2.*3.14159);//isotropic particle
	//  	costheta_recoil=-costheta_p1;//isotropic particle
	//  	phi_recoil=phi_p1+3.14159;//isotropic particle

	//	costheta_recoil=CLHEP::RandFlat::shoot(-1,1);//isotropic recoil
	//	phi_recoil=CLHEP::RandFlat::shoot(0.,2.*3.14159);//isotropic recoil
		//G4cout<<"------------ phi="<<phi<<' '<<"costheta="<<costheta<<G4endl;

	// 	sintheta_recoil=sqrt(1.0-costheta_recoil*costheta_recoil);//isotropy
	// 	dirx=sintheta_recoil*cos(phi_recoil);//isotropy
	// 	diry=sintheta_recoil*sin(phi_recoil);//isotropy
	// 	dirz=costheta_recoil;//isotropy

	//	Ebeam=128*CLHEP::MeV;

	// 24Mg
	Ebeam = CLHEP::RandGauss::shoot(75, 75 * 0.002 / 2.355) * CLHEP::MeV;// beam energy spread 0.2 % (FWHM) based on Oliver Kirsebom PRC2016
	Ebeam = Ebeam - z0 * 1000 * 7.200; // stopping power of 75-MeV 24Mg in gold is approximately 7.2 MeV/um, z0 was the depth of 3He in units of mm.
	//75-MeV 24Mg ions pass through 0.2 um thick gold lose 1.5 MeV
	if (Ebeam < 0) Ebeam = 75 * CLHEP::MeV;

	// 32S
	//Ebeam=CLHEP::RandGauss::shoot(128,128*0.002/2.355)*CLHEP::MeV;//Energy loss in gold foil
	//Ebeam=Ebeam-z0*1000*10.600; // stopping power of 128-MeV 32S in gold is approximately 10.6 MeV/um, z0 was the depth of 3He in units of mm.
		//128-MeV 32S ions pass through 0.2 um thick gold lose 2.12 MeV
	//if (Ebeam<0) Ebeam=128*CLHEP::MeV;
		//G4cout<<Ebeam/CLHEP::MeV<<endl;

	atomic_mass_unit = 931.49410242; // MeV/c2
	Abeam = 24; // 24Mg
	//Abeam=32; // 32S

		// 34Ar + 1n, should be the same kinematics as 34Cl + 1H
	// 	Atarget=3; Zrecoil=17; Arecoil=34; Zejectile=1; Aejectile=1;
	// 	Qvalue=-0.78*CLHEP::MeV; // gs Q-value
	// 	Excitation_recoil=3288*CLHEP::keV; tau=194; //fs // 34Ar
	// 	Excitation_recoil=4513*CLHEP::keV; tau=201; //fs // 34Ar

		 // 34Cl + 1H
	// 	Atarget=3; Zrecoil=17; Arecoil=34; Zejectile=1; Aejectile=1;
	// 	Qvalue=6.07*CLHEP::MeV; // gs Q-value
	//	Excitation_recoil=3334*CLHEP::keV; tau=47; //fs // 34Cl
	//	Excitation_recoil=2376.5*CLHEP::keV; tau=150; //fs // 34Cl
	//	Excitation_recoil=3983*CLHEP::keV; tau=131; //fs // 34Cl

		// 33Cl + 2H
	//  	Atarget=3; Zrecoil=17; Arecoil=33; Zejectile=1; Aejectile=2;
	//  	Qvalue=-3.22*CLHEP::MeV; // gs Q-value
	// 	Excitation_recoil=1986*CLHEP::keV; tau=55; //fs // 44Ti

		// 41Ca + 3He
	// 	Atarget=12; Zrecoil=20; Arecoil=41; Zejectile=2; Aejectile=3;
	// 	Qvalue=-5.81*CLHEP::MeV; // gs Q-value
	// 	Excitation_recoil=3731*CLHEP::keV; tau=45; //fs // 41Ca
	// 	Excitation_recoil=3740*CLHEP::keV; tau=20; //fs // 41Ca
	//	Excitation_recoil=4328*CLHEP::keV; tau=80; //fs // 41Ca

		// 41Ca + 3He + 4He
	// 	Atarget=16; Zrecoil=20; Arecoil=41; Zejectile=4; Aejectile=7;
	// 	Qvalue=-11.4*CLHEP::MeV; // gs Q-value
	// 	Excitation_recoil=4328*CLHEP::keV; tau=80; //fs // 41Ca

		// 42Sc + 2H
	// 	Atarget=12; Zrecoil=21; Arecoil=42; Zejectile=1; Aejectile=2;
	// 	Qvalue=-7.03*CLHEP::MeV; // gs Q-value

		// 40Ca + 4He
	// 	Atarget=12; Zrecoil=20; Arecoil=40; Zejectile=2; Aejectile=4;
	// 	Qvalue=6.41*CLHEP::MeV; // gs Q-value
	//	Excitation_recoil=5249*CLHEP::keV; tau=83; //fs // 40Ca
	// 	Excitation_recoil=6508*CLHEP::keV; tau=128; //fs // 40Ca
	// 	Excitation_recoil=6543*CLHEP::keV; tau=121; //fs // 40Ca

		// 44Ti + 4He
	// 	Atarget=16; Zrecoil=22; Arecoil=44; Zejectile=2; Aejectile=4;
	// 	Qvalue=4.37*CLHEP::MeV; // gs Q-value
	//	Excitation_recoil=4116*CLHEP::keV; tau=110; //fs // 44Ti

		// 33Cl + 2H
	// 	Atarget=16; Zrecoil=22; Arecoil=44; Zejectile=2; Aejectile=4;
	// 	Qvalue=4.37*CLHEP::MeV; // gs Q-value
	//	Excitation_recoil=4116*CLHEP::keV; tau=110; //fs // 33Cl

		// 30P + 1H + 4He
	// 	Atarget=3; Zrecoil=15; Arecoil=30; Zejectile=3; Aejectile=5;
	// 	Qvalue=-0.597*CLHEP::MeV; // gs Q-value
	// 	Excitation_recoil=4144*CLHEP::keV; tau=30; //fs // 30P

	// 31S + 4He
//  	Atarget=3; Zrecoil=16; Arecoil=31; Zejectile=2; Aejectile=4;
//  	Qvalue=5.533*CLHEP::MeV; // gs Q-value, uncertainty is negligible
// 	Excitation_recoil=1248.43*CLHEP::keV; tau=715.048; //half-life in fs // 31S emulator test
//	Excitation_recoil=1248.43*CLHEP::keV; tau=1100; //half-life in fs // 31S
//	Excitation_recoil=2234.06*CLHEP::keV; tau=100; //lifetime in fs // 31S

//	Excitation_recoil = 6390.30 * CLHEP::keV; tau = 1; //lifetime in fs // 31S Ex low modify
//	Excitation_recoil = 6390.46 * CLHEP::keV; tau = 3; //lifetime in fs // 31S Ex middle
//	Excitation_recoil = 6390.62 * CLHEP::keV; tau = 15; //lifetime in fs // 31S Ex high
	//Reasonable Doppler shift regardless of final states defined in the data/PhotonEvaporation3.2/z.a (Verified)

		// 23Mg + 4He
	Atarget = 3; Zrecoil = 12; Arecoil = 23; Zejectile = 2; Aejectile = 4;
	Qvalue = 4.0464 * CLHEP::MeV; // gs Q-value
	// 	Excitation_recoil=451*CLHEP::keV; tau=1659; //half-life in fs // 23Mg
	//Excitation_recoil = 7782.7 * CLHEP::keV; tau = 7; //half-life in fs // Ex for Q value
	Excitation_recoil = 7784.7 * CLHEP::keV; tau = 7; //half-life in fs // true Ex for Q value
	//Excitation_recoil = 7786.7 * CLHEP::keV; tau = 7; //half-life in fs // Ex for Q value
	//Excitation_recoil = 7788.7 * CLHEP::keV; tau = 30; //half-life in fs // Ex for Q value

	Excitation_ejectile = 0; // don't change
	Qvalue = Qvalue - Excitation_recoil; // effective Q-value. don't change
	// cout << Qvalue / CLHEP::MeV << G4endl;
	tau = tau / 1000 * CLHEP::picosecond; // lifetime
	//	cout<<tau/CLHEP::ns<<G4endl;
	//	tau=1.442695*tau; // half-life to lifetime. useless but accidentally used for 1248.
	//	cout<<tau/CLHEP::ns<<G4endl;
	ioncharge = 0. * CLHEP::eplus; // don't change

	//	Excitation_recoil=1248.9836*CLHEP::keV; // an mean-max correction in EMG function
	//	Excitation_recoil=2235.0743*CLHEP::keV; // an mean-max correction in EMG function
	//	Excitation_recoil = 6391.7431*CLHEP::keV; // an mean-max correction in EMG function
	//Excitation_recoil = 7335.17 * CLHEP::keV; // Eg low = 7331.20 keV
	Excitation_recoil = 7337.17 * CLHEP::keV; // Eg medium = 7333.20 keV
	//Excitation_recoil = 7339.17 * CLHEP::keV; // Eg high = 7335.20 keV
	//Excitation_recoil = 7341.17 * CLHEP::keV; // Eg high2 = 7337.20 keV

		
	int AngularDistribution = 1;
	if (AngularDistribution == 1) // slower than AD = 0
	{
		ad = new TF1("ad", "[0]+[1]*1./2.*(3.*x*x-1.)+[2]*1./8.*(35.*x*x*x*x-30.*x*x+3.)", -1.0, 1.0); // x means costheta
		ad->SetParameter(0, 1.0); // set value of parameter 0 (a0=1 always)
		ad->SetParameter(1, -0.8); // set value of parameter 1 (a2=0 means isotropic; a2>0 means forward-backward enhancement; a2=-1 means forward-backward suppression)
		ad->SetParameter(2, 0.0); // set value of parameter 2 (a4)
		costheta_p1 = ad->GetRandom(0.79, 1.0); // starting point, if angular distribution is needed.
	}

	if (AngularDistribution == 0)
	{
		costheta_p1 = CLHEP::RandFlat::shoot(0.79, 1.0); // alpha particles emitted at forward angles along z-axis. starting point!
		//(0.50,1.) = <60 deg, (0.57,1.) = <55 deg (theta alpha 6390 31S), (0.71,1.) = <45 deg, (0.78,1.) = <39 deg, (0.90,1.) = <25.8 deg, (0.94,1.) = <20 deg for final DSL1 restuls, (0.97,1.) = <14 deg, (0.979,1.) = <11.6 deg, (-1.,1.) 180 deg
		//0.71 for 31S 6390, 0.79 for 23Mg 7787
	}
	//single particle isotropic emission
	phi_p1 = CLHEP::RandFlat::shoot(0., 2. * 3.14159);//isotropy or not, both use this statement
	theta_p1 = acos(costheta_p1);
	//G4cout<<"------------ phi="<<phi_p1<<' '<<"costheta="<<costheta_p1<<G4endl;
	sintheta_p1 = sqrt(1.0 - costheta_p1 * costheta_p1);//isotropy
	dirx = sintheta_p1 * cos(phi_p1);//isotropy
	diry = sintheta_p1 * sin(phi_p1);//isotropy
	dirz = costheta_p1;//isotropy
	//calculate Eejectile from selected theta_p1, here it should be "+" sign before sqrt
	Eejectile = (sqrt(Abeam * Aejectile * Ebeam) / (Arecoil + Aejectile) * costheta_p1 + sqrt(((Arecoil - Abeam) / (Arecoil + Aejectile) + Abeam * Aejectile / ((Arecoil + Aejectile) * (Arecoil + Aejectile)) * (costheta_p1 * costheta_p1)) * Ebeam + Arecoil / (Arecoil + Aejectile) * Qvalue)) * (sqrt(Abeam * Aejectile * Ebeam) / (Arecoil + Aejectile) * costheta_p1 + sqrt(((Arecoil - Abeam) / (Arecoil + Aejectile) + Abeam * Aejectile / ((Arecoil + Aejectile) * (Arecoil + Aejectile)) * (costheta_p1 * costheta_p1)) * Ebeam + Arecoil / (Arecoil + Aejectile) * Qvalue));
	//G4cout<<"++++++++++++  Ealpha=	"<<Eejectile/CLHEP::MeV<<"	MeV	theta_p1=	"<<theta_p1/CLHEP::deg<<"	deg"<<G4endl; // formula verified
	G4ParticleDefinition* particle = G4IonTable::GetIonTable()->GetIon(Zejectile, Aejectile, Excitation_ejectile);
	//G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("alpha");
	//G4cout<<"++++++++++++  x0="<<x0/CLHEP::mm<<"  y0="<<y0/CLHEP::mm<<"  z0="<<z0/CLHEP::mm<<G4endl;
	position = G4ThreeVector(x0 * CLHEP::mm, y0 * CLHEP::mm, z0 * CLHEP::mm);// 2D beam spot
	//position=G4ThreeVector(0.*CLHEP::mm,0.*CLHEP::mm,0*CLHEP::mm);// point source, usually for check, validation and test
	momentumDirection = G4ThreeVector(dirx, diry, dirz);//isotropy
	//momentumDirection = G4ThreeVector(0,0,+1);//(0,0,+1) unidirectional toward Z+ axis, usually for check, validation and test
	//Eejectile = 20 * CLHEP::MeV; // fixed energy for test
	fParticleGun->SetParticleDefinition(particle);
	fParticleGun->SetParticleEnergy(Eejectile);
	fParticleGun->SetParticlePosition(position);
	fParticleGun->SetParticleMomentumDirection(momentumDirection);
	fParticleGun->SetParticleCharge(ioncharge);
	//fParticleGun->SetParticleTime(1000*CLHEP::ns);//meaningless, the generation time of particle
	fParticleGun->GeneratePrimaryVertex(anEvent);









	// *** for the second particle emitted in the same event *** In this case, it's recoiling 31S
	particle = G4IonTable::GetIonTable()->GetIon(Zrecoil, Arecoil, Excitation_recoil); // the final state is determined by the /data/PhotonEvaporation3.2/z16.a31 file, the second gamma ray will only be emitted after the recoil stops. Gean4 can't handle the Doppler shift for the second gamma in a cascade.
	particle->SetPDGStable(false); // for Doppler
	particle->SetPDGLifeTime(tau); // this is lifetime τ = 1.443*T1/2 // for Doppler

	Erecoil = Ebeam + Qvalue - Eejectile; // Conservation of total energy. Get Erecoil from Eejectile.
	//G4cout << "Erecoil=	" << Erecoil / CLHEP::MeV << "	MeV. " << "Eejectile=	" << Eejectile / CLHEP::MeV << "	MeV. " << G4endl;
	Pejectile = sqrt((Eejectile / (Aejectile * atomic_mass_unit) + 1) * (Eejectile / (Aejectile * atomic_mass_unit) + 1) - 1) * (Aejectile * atomic_mass_unit); // momentum in units of MeV/c
	Precoil = sqrt((Erecoil / (Arecoil * atomic_mass_unit) + 1) * (Erecoil / (Arecoil * atomic_mass_unit) + 1) - 1) * (Arecoil * atomic_mass_unit); // momentum in units of MeV/c
	Pbeam = sqrt((Ebeam / (Abeam * atomic_mass_unit) + 1) * (Ebeam / (Abeam * atomic_mass_unit) + 1) - 1) * (Abeam * atomic_mass_unit); // momentum in units of MeV/c
	//sintheta_recoil=sqrt(2*Aejectile*Eejectile)*sqrt(1-costheta_p1*costheta_p1)/sqrt(2*Arecoil*Erecoil); // Conservation of momentum
	sintheta_recoil = Pejectile * sintheta_p1 / Precoil; // Conservation of momentum.  Get theta_recoil from theta_ejectile.
	//theta_recoil=-0.12150112*acos(costheta_p1)*acos(costheta_p1) + 0.32702559*acos(costheta_p1) - 0.00048110; // approximation test
	costheta_recoil = sqrt(1.0 - sintheta_recoil * sintheta_recoil);
	theta_recoil = asin(sintheta_recoil);
	phi_recoil = CLHEP::RandFlat::shoot(0., 2. * 3.14159);//isotropy
	//G4cout<<"------------ phi="<<phi<<' '<<"costheta="<<costheta<<G4endl;
	//sintheta_recoil=sqrt(1.0-costheta_recoil*costheta_recoil);//isotropy
	dirx = sintheta_recoil * cos(phi_recoil);//isotropy
	diry = sintheta_recoil * sin(phi_recoil);//isotropy
	dirz = costheta_recoil;//isotropy
	//calculate Erecoil from selected theta_recoil, here it should be "-" sign before sqrt
	//Erecoil=(sqrt(Abeam*Arecoil*Ebeam)/(Aejectile+Arecoil)*costheta_recoil-sqrt(((Aejectile-Abeam)/(Aejectile+Arecoil)+Abeam*Arecoil/((Aejectile+Arecoil)*(Aejectile+Arecoil))*(costheta_recoil*costheta_recoil))*Ebeam+Aejectile/(Aejectile+Arecoil)*Qvalue))*(sqrt(Abeam*Arecoil*Ebeam)/(Aejectile+Arecoil)*costheta_recoil-sqrt(((Aejectile-Abeam)/(Aejectile+Arecoil)+Abeam*Arecoil/((Aejectile+Arecoil)*(Aejectile+Arecoil))*(costheta_recoil*costheta_recoil))*Ebeam+Aejectile/(Aejectile+Arecoil)*Qvalue)); // check
// 	G4cout<<"E_p1=	"<<Eejectile/CLHEP::MeV<<"	MeV	theta_p1=	"<<theta_p1/CLHEP::deg<<"	deg	P_p1=	"<<Pejectile<<"	MeV/c"<<G4endl; // formula verified
//  	G4cout<<"E_recoil=	"<<Erecoil/CLHEP::MeV<<"	MeV	theta_recoil=	"<<theta_recoil/CLHEP::deg<<"	deg	P_recoil=	"<<Precoil<<"	MeV/c"<<G4endl; // formula verified
//	G4cout<<Erecoil/CLHEP::MeV<<"	MeV	"<<theta_recoil/CLHEP::deg<<"	deg	"<<Precoil<<"	MeV/c	"<<Eejectile/CLHEP::MeV<<"	MeV	"<<theta_p1/CLHEP::deg<<"	deg	"<<Pejectile<<"	MeV/c"<<G4endl; // formula verified

	//position=G4ThreeVector(x0*CLHEP::mm,y0*CLHEP::mm,z0*CLHEP::mm);// 2D beam spot
	//position=G4ThreeVector(0.*CLHEP::mm,0.*CLHEP::mm,0.*CLHEP::mm);// point source, usually for check, validation and test
	momentumDirection = G4ThreeVector(dirx, diry, dirz);//isotropy
	//momentumDirection = G4ThreeVector(0,0,+1);//(0,0,+1) unidirectional toward Z+ axis, usually for check, validation and test
	//Erecoil = 50 * CLHEP::MeV; // for test
	fParticleGun->SetParticleDefinition(particle);
	fParticleGun->SetParticleEnergy(Erecoil);
	fParticleGun->SetParticlePosition(position);//recoil uses the same position as projectile
	fParticleGun->SetParticleMomentumDirection(momentumDirection);
	fParticleGun->SetParticleCharge(ioncharge);
	//fParticleGun->SetParticleTime(1000*CLHEP::ns);//meaningless, the generation time of particle
	fParticleGun->GeneratePrimaryVertex(anEvent);// if you do not need the second particle in the same event, comment this statement out
}

