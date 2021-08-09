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
	:  G4VUserPrimaryGeneratorAction(),
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
	//pFile=new TFile("/mnt/hgfs/HPGe/S27_pz.root","read");
	//pFile=new TFile("/mnt/hgfs/HPGe/P26_pz.root","read");
	//pFile=new TFile("/mnt/hgfs/HPGe/Si25_pz.root","read");
	//pFile=new TFile("/mnt/hgfs/HPGe/Al22_pz.root","read");
	//pFile=new TFile("/mnt/hgfs/HPGe/S27simulate.root","read");
	//fout = fopen ("out.txt", "w");

	numpeaks=1;//23 or 53 for 29Na, 46 or 88 for 30Na. with Doppler, 62 for 29Na, 1 for test
	branch_lit_tot=0;
	//fin=fopen ("/mnt/hgfs/HPGe/Gamma30Naprecursor.dat","r");
	wheretorun=3;
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
	// 	px_impl = new TH1F("px_impl","px_impl", 50,-25,25);//unit mm, this statement cannot be eliminated, the new TH1F cannot be named the same as the TH1F in the input root
	// 	py_impl = new TH1F("py_impl","py_impl", 50,-25,25);//unit mm, this statement cannot be eliminated, the new TH1F cannot be named the same as the TH1F in the input root
	// 	pz_impl = new TH1D("pz_impl","pz_impl", 100,0,100);//unit um, this statement cannot be eliminated, the new TH1F cannot be named the same as the TH1F in the input root
	G4cout<<"1$ before run, by run, ExG4PrimaryGeneratorAction::ExG4PrimaryGeneratorAction()"<<G4endl;
}

ExG4PrimaryGeneratorAction::~ExG4PrimaryGeneratorAction()
{
	G4cout<<"8$ after run, by run, ExG4PrimaryGeneratorAction::~ExG4PrimaryGeneratorAction()"<<G4endl;
	//pFile->Close();
	//fclose(fout);
	//	fclose(fin);//VMware
	delete fParticleGun;
}

void ExG4PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)
{
	//G4cout<<"(1)$ before event, by event, ExG4PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)"<<G4endl;

	//px_impl=(TH1F*)pFile->Get("himpl40px");//Get("hx2");//from implantation root for DSSD2 modify
	//py_impl=(TH1F*)pFile->Get("himpl40py");//Get("hy2");//from implantation root for DSSD2 modify
	//pz_impl=(TH1D*)pFile->Get("himpl40pz");//Get("hz2");//from implantation root for DSSD2 modify
	//	px_impl=(TH1F*)pFile->Get("himpl304px");//Get("hx2");//from implantation root for Target modify
	//	py_impl=(TH1F*)pFile->Get("himpl304py");//Get("hy2");//from implantation root for Target modify
	//	pz_impl=(TH1D*)pFile->Get("himpl304pz");//Get("hz2");//from implantation root for Target modify
	//	x0=px_impl->GetRandom()*CLHEP::mm;//from implantation root for both DSSD2\3
	//	y0=py_impl->GetRandom()*CLHEP::mm;//from implantation root for both DSSD2\3
	//	z0=pz_impl->GetRandom()*0.001*CLHEP::mm;//from implantation root for both DSSD2\3
	//G4cout<<"++++++++++++  x0="<<x0<<"  y0="<<y0<<"  z0="<<z0/CLHEP::mm<<G4endl;
	//	for(;x0>49.5/2||x0<-49.5/2;){x0=px_impl->GetRandom()*CLHEP::mm;}//from implantation root for both DSSD2\3. To ensure an appropriate x0.
	//	for(;y0<-49.5/2||y0>49.5/2;){y0=py_impl->GetRandom()*CLHEP::mm;}//from implantation root for both DSSD2\3. To ensure an appropriate y0.
	//if(x0>49.5/2||x0<-49.5/2||y0<-49.5/2||y0>49.5/2)fprintf(fp, "%f%s%f\n", x0," ",y0); 
	//for(;z0>0.04;){z0=pz_impl->GetRandom()*0.001*CLHEP::mm;};To ensure an appropriate DSSD2 z0.
	//z0=0-0.040/2.0+z0;//from implantation root for DSSD2 modify.
	//	z0=19-0.304/2.0+z0;//from implantation root for Target modify
	//x0=G4UniformRand();
	//x0=0; y0=0; z0=0*CLHEP::mm;//fixed point
	//G4cout<<pz300->GetMean()<<G4endl;
	//G4cout<<"yangbiao test : RMS of h1 is "<<((TH1F*)pFile->Get("h1"))->GetMean()<<G4endl;

//	branch_integ=CLHEP::RandFlat::shoot(0.0,branch_lit_tot);

	//EMG response function
// 	TF1 *EMGf1=new TF1("EMGf1","[0]*[3]/[1]*1.253314137*TMath::Exp(0.5*([3]*[3]/[1]/[1])+(x-[2])/[1])*TMath::Erfc(1/1.41421356*([3]/[1]+(x-[2])/[3]))",ExcitationE-50,ExcitationE+50);//Glassman_PRC2019
// 	EMGf1->SetNpx(5000);//Set the number of points used to draw the function. [0]-N, [1]-τ, [2]-μ, [3]-σ,
// 	// normalized cumulative Probability Density Function
// 	TF1 *EMGf2=new TF1("EMGf2","[0]/2*(TMath::Exp((0.5*[3]*[3]-[1]*[2]+[1]*x)/([1]*[1]))*TMath::Erfc(1/1.41421356*([3]/[1]+(x-[2])/[3]))-TMath::Erfc((x-[2])/(1.41421356*[3])))+1",ExcitationE-50,ExcitationE+50);//Glassman_PRC2019
// 	EMGf2->SetNpx(5000);//Set the number of points used to draw the function.
// 
// 	emg_sigp1= 0.00011508152;
// 	emg_sigp0= 1.142295;
// 	emg_taup1= 0.000823321;
// 	emg_taup0= -0.354105;
//	emg_sig = emg_sigp1*ExcitationE + emg_sigp0;
// 	emg_tau = emg_taup1*ExcitationE + emg_taup0;
// 
// 	EMGf2->SetParameter(0,1.);//N
// 	EMGf2->SetParameter(1,emg_tau);//τ
// 	EMGf2->SetParameter(2,ExcitationE);//μ
// 	EMGf2->SetParameter(3,emg_sig);//σ
// 	ExcitationE = EMGf2->GetX(G4RandFlat::shoot(0.0,1.0), ExcitationE-50,ExcitationE+50);//After this, ExcitationE is the experimentally detected gamma energy
	//G4cout<<"ExcitationE = "<<ExcitationE<<G4endl;
	//G4cout<<"rundomnumber = "<<G4UniformRand()<<G4endl;
	//G4cout<<"rundomnumber = "<<G4RandFlat::shoot(0.0,1.0)<<G4endl;
	


// 	if (branch_integ<branch_lit_integ[0])
// 	{
// 		ExcitationE=Eg_lit[0]*CLHEP::keV;
// 		Erecoil=En_lit[0]*Aejectile/(Arecoil+Aejectile)*CLHEP::keV;
// 		tau=1.443*Halflife_lit[0]*CLHEP::ns;
// 	} 	
// 	for(int ii=1;ii<numpeaks;ii++)
// 	{
// 		if(branch_integ>=branch_lit_integ[ii-1]&&branch_integ<branch_lit_integ[ii])
// 		{
// 			ExcitationE=Eg_lit[ii]*CLHEP::keV;
// 			Erecoil=En_lit[ii]*Aejectile/(Arecoil+Aejectile)*CLHEP::keV;
// 			tau=1.443*Halflife_lit[ii]*CLHEP::ns;
// 		}
// 	}
//	tau=0.01*CLHEP::ns;//this is lifetime τ = 1.443*T1/2; 1 ps = 0.001 ns; 10 fs = 0.00001 ns //simplified test
//	Erecoil=200*CLHEP::keV; ExcitationE=2000*CLHEP::keV; tau=0.000010*CLHEP::ns;//simplified test
//	resolution=1.010473*pow(ExcitationE/CLHEP::keV,-0.888665);//resolution becomes better for high energy gamma
//	if(ExcitationE<122*CLHEP::keV)
//	{
//		ExcitationE=G4RandGauss::shoot(ExcitationE,0.001414/2.355*ExcitationE);//sigma resolution, 0.01/2.355 means 1%//slow down the speed by a factor of 10
//		//G4cout<<ExcitationE/CLHEP::keV<<"	"<<resolution<<G4endl;
//	}
//	ExcitationE width should be added in PrimaryGeneratorAction.cc, while detector resolution should be added in EventAction.cc
//	ExcitationE=G4RandGauss::shoot(ExcitationE,resolution/2.355*ExcitationE);//sigma resolution, 0.01/2.355 means 1%//slow down the speed by a factor of 10
//	Erecoil=G4RandGauss::shoot(Erecoil,0.01/2.355*Erecoil);
	
	//G4ParticleDefinition* particle = G4IonTable::GetIonTable()->GetIon(12,26,0); //28Mg: GetIon(12,28,0); 
	//G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("proton");
	//G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
	//G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("e+");
	//particle->SetProperTime(0.0);// seems useless

	//	G4cout<<"------- Er="<<Erecoil/CLHEP::keV<<" keV"<<"	branch_integ="<<branch_integ<<"	Eg=	"<<ExcitationE/CLHEP::keV<<"	T=	"<<0.69315*particle->GetPDGLifeTime()/CLHEP::ns<<"	ns"<<G4endl;
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
	Ebeam=128*CLHEP::MeV;
//	Ebeam=CLHEP::RandGauss::shoot(127.1,0.8/3.0);//Energy loss in gold foil
//	Ebeam=CLHEP::RandGauss::shoot(119.7,8.0/3.0);//Energy loss in gold foil

	atomic_mass_unit = 931.49410242; // MeV/c2
	Zrecoil=16;
	Zejectile=2;
	Abeam=32; // 32S
	Atarget=3; // 3He
	Arecoil=31; // 31S
	Aejectile=4; // 4He
	Qvalue=5.5333*CLHEP::MeV; // gs Q-value
	ExcitationE=1.2484*CLHEP::MeV; //1248.4 MeV;
	Qvalue = Qvalue - ExcitationE; // 1st Q-value
	ExcitationE=1.24898*CLHEP::MeV; //for a weird mean-max correction in EMG function;
	ioncharge = 0.*CLHEP::eplus;
	
	
	//single particle isotropic emission
	costheta_p1=CLHEP::RandFlat::shoot(0.71,1.);//alpha particles emitted at forward angles along z-axis. starting point!
	//(0.71,1.) = <45 deg, (0.97,1.) = <14 deg
	phi_p1=CLHEP::RandFlat::shoot(0.,2.*3.14159);//isotropy
	theta_p1=acos(costheta_p1);
	//G4cout<<"------------ phi="<<phi<<' '<<"costheta="<<costheta<<G4endl;
	sintheta_p1=sqrt(1.0-costheta_p1*costheta_p1);//isotropy
	dirx=sintheta_p1*cos(phi_p1);//isotropy
	diry=sintheta_p1*sin(phi_p1);//isotropy
	dirz=costheta_p1;//isotropy
	//calculate Eejectile from selected theta_p1, here it should be "+" sign before sqrt
	Eejectile=(sqrt(Abeam*Aejectile*Ebeam)/(Arecoil+Aejectile)*costheta_p1+sqrt(((Arecoil-Abeam)/(Arecoil+Aejectile)+Abeam*Aejectile/((Arecoil+Aejectile)*(Arecoil+Aejectile))*(costheta_p1*costheta_p1))*Ebeam+Arecoil/(Arecoil+Aejectile)*Qvalue))*(sqrt(Abeam*Aejectile*Ebeam)/(Arecoil+Aejectile)*costheta_p1+sqrt(((Arecoil-Abeam)/(Arecoil+Aejectile)+Abeam*Aejectile/((Arecoil+Aejectile)*(Arecoil+Aejectile))*(costheta_p1*costheta_p1))*Ebeam+Arecoil/(Arecoil+Aejectile)*Qvalue));
	//G4cout<<"++++++++++++  Ealpha=	"<<Eejectile/CLHEP::MeV<<"	MeV	theta_p1=	"<<acos(costheta_p1)<< " rad"<<G4endl; // formula verified
	G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("alpha");
	//G4cout<<"++++++++++++  x0="<<x0/CLHEP::mm<<"  y0="<<y0/CLHEP::mm<<"  z0="<<z0/CLHEP::mm<<G4endl;
	//position=G4ThreeVector(x0*CLHEP::mm,y0*CLHEP::mm,z0*CLHEP::mm);// 2D beam spot
	position=G4ThreeVector(0.*CLHEP::mm,0.*CLHEP::mm,0.*CLHEP::mm);// point source, usually for check, validation and test
	momentumDirection = G4ThreeVector(dirx,diry,dirz);//isotropy
	//momentumDirection = G4ThreeVector(0,0,-1);//(0,0,+1) unidirectional toward Z+ axis, usually for check, validation and test
	fParticleGun->SetParticleDefinition(particle);
	fParticleGun->SetParticleEnergy(Eejectile);
	fParticleGun->SetParticlePosition(position);
	fParticleGun->SetParticleMomentumDirection(momentumDirection);
	fParticleGun->SetParticleCharge(ioncharge);
	//fParticleGun->SetParticleTime(1000*CLHEP::ns);//meaningless, the generation time of particle
	fParticleGun->GeneratePrimaryVertex(anEvent);









	// *** for the second particle emitted in the same event *** In this case, it's recoiling 31S
	tau=0.0005*CLHEP::ns;
	particle = G4IonTable::GetIonTable()->GetIon(Zrecoil,Arecoil,ExcitationE);
	particle->SetPDGStable(false); // for Doppler
	particle->SetPDGLifeTime(tau); // this is lifetime τ = 1.443*T1/2 // for Doppler

	Erecoil=Ebeam+Qvalue-Eejectile; // Conservation of total energy. Get Erecoil from Eejectile.
	Pejectile=sqrt((Eejectile/(Aejectile*atomic_mass_unit)+1)*(Eejectile/(Aejectile*atomic_mass_unit)+1)-1)*(Aejectile*atomic_mass_unit); // momentum in units of MeV/c
	Precoil=sqrt((Erecoil/(Arecoil*atomic_mass_unit)+1)*(Erecoil/(Arecoil*atomic_mass_unit)+1)-1)*(Arecoil*atomic_mass_unit); // momentum in units of MeV/c
	Pbeam=sqrt((Ebeam/(Abeam*atomic_mass_unit)+1)*(Ebeam/(Abeam*atomic_mass_unit)+1)-1)*(Abeam*atomic_mass_unit); // momentum in units of MeV/c
	//sintheta_recoil=sqrt(2*Aejectile*Eejectile)*sqrt(1-costheta_p1*costheta_p1)/sqrt(2*Arecoil*Erecoil); // Conservation of momentum
	sintheta_recoil=Pejectile*sintheta_p1/Precoil; // Conservation of momentum.  Get theta_recoil from theta_ejectile.
	//theta_recoil=-0.12150112*acos(costheta_p1)*acos(costheta_p1) + 0.32702559*acos(costheta_p1) - 0.00048110; // approximation test
	costheta_recoil=sqrt(1.0-sintheta_recoil*sintheta_recoil);
	theta_recoil=asin(sintheta_recoil);
	phi_recoil=CLHEP::RandFlat::shoot(0.,2.*3.14159);//isotropy
	//G4cout<<"------------ phi="<<phi<<' '<<"costheta="<<costheta<<G4endl;
	//sintheta_recoil=sqrt(1.0-costheta_recoil*costheta_recoil);//isotropy
	dirx=sintheta_recoil*cos(phi_recoil);//isotropy
	diry=sintheta_recoil*sin(phi_recoil);//isotropy
	dirz=costheta_recoil;//isotropy
	//calculate Erecoil from selected theta_recoil, here it should be "-" sign before sqrt
	//Erecoil=(sqrt(Abeam*Arecoil*Ebeam)/(Aejectile+Arecoil)*costheta_recoil-sqrt(((Aejectile-Abeam)/(Aejectile+Arecoil)+Abeam*Arecoil/((Aejectile+Arecoil)*(Aejectile+Arecoil))*(costheta_recoil*costheta_recoil))*Ebeam+Aejectile/(Aejectile+Arecoil)*Qvalue))*(sqrt(Abeam*Arecoil*Ebeam)/(Aejectile+Arecoil)*costheta_recoil-sqrt(((Aejectile-Abeam)/(Aejectile+Arecoil)+Abeam*Arecoil/((Aejectile+Arecoil)*(Aejectile+Arecoil))*(costheta_recoil*costheta_recoil))*Ebeam+Aejectile/(Aejectile+Arecoil)*Qvalue)); // check
// 	G4cout<<"++++++++++++  Ealpha=	"<<Eejectile/CLHEP::MeV<<"	MeV	theta_p1=	"<<theta_p1/CLHEP::deg<<"	deg	Palpha=	"<<Pejectile<<"	MeV/c"<<G4endl; // formula verified
// 	G4cout<<"++++++++++++  E31S=	"<<Erecoil/CLHEP::MeV<<"	MeV	theta_recoil=	"<<theta_recoil/CLHEP::deg<<"	deg	P31S=	"<<Precoil<<"	MeV/c"<<G4endl; // formula verified
	
	//position=G4ThreeVector(x0*CLHEP::mm,y0*CLHEP::mm,z0*CLHEP::mm);// 2D beam spot
	position=G4ThreeVector(0.*CLHEP::mm,0.*CLHEP::mm,0.*CLHEP::mm);// point source, usually for check, validation and test
	momentumDirection = G4ThreeVector(dirx,diry,dirz);//isotropy
	//momentumDirection = G4ThreeVector(0,0,-1);//(0,0,+1) unidirectional toward Z+ axis, usually for check, validation and test
	fParticleGun->SetParticleDefinition(particle);
	fParticleGun->SetParticleEnergy(Erecoil);
	fParticleGun->SetParticlePosition(position);
	fParticleGun->SetParticleMomentumDirection(momentumDirection);
	fParticleGun->SetParticleCharge(ioncharge);
	//fParticleGun->SetParticleTime(1000*CLHEP::ns);//meaningless, the generation time of particle
	fParticleGun->GeneratePrimaryVertex(anEvent);// if you do not need the second particle in the same event, comment this statement out
}

