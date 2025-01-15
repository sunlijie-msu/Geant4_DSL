DSL1 and DSL2 simulation
VMware:

godsl
cd /home/sun/app/Geant4_DSL-build

1) cmd
cmake -DGeant4_DIR=/home/sun/app/geant4.10.02-install/lib/Geant4-10.2.3 /mnt/hgfs/Geant4_DSL

2) make

3) ./tele vis


fishtank:

source /mnt/analysis/triumf_s2193/sun/G4data/geant4_mydata.sh

source /usr/opt/jessie.sh

source /etc/profile.d/module.sh

lsb_release -a

Distributor ID:	Debian
Description:	Debian GNU/Linux 8.11 (jessie)
Release:	8.11
Codename:	jessie

module avail
module load gnu/gcc/4.9
module load root/gnu/6.06.02

gcc -v
4.9.2

root-config --version
6.06.02

cmake --version
3.6.3

godsl2
cd /mnt/analysis/triumf_s2193/sun/Build_Geant4_DSL_Jan2025

rm -rf CM*; rm -rf cm*

cmake -DGeant4_DIR=/mnt/simulations/proton_detector/Geant4/geant4.10.2-install/lib/Geant4-10.2.2 /mnt/analysis/triumf_s2193/sun/Geant4_DSL_Jan2025

make

pike:Build_Geant4_DSL_Jan2025> env|grep G4
G4LEVELGAMMADATA=/mnt/analysis/triumf_s2193/sun/G4data/PhotonEvaporation3.2
G4NEUTRONXSDATA=/mnt/simulations/proton_detector/Geant4/geant4.10.2-install/share/Geant4-10.2.2/data/G4NEUTRONXS1.4
G4LEDATA=/mnt/simulations/proton_detector/Geant4/geant4.10.2-install/share/Geant4-10.2.2/data/G4EMLOW6.48
G4NEUTRONHPDATA=/mnt/simulations/proton_detector/Geant4/geant4.10.2-install/share/Geant4-10.2.2/data/G4NDL4.5
G4ENSDFSTATEDATA=/mnt/simulations/proton_detector/Geant4/geant4.10.2-install/share/Geant4-10.2.2/data/G4ENSDFSTATE1.2.3
G4RADIOACTIVEDATA=/mnt/analysis/triumf_s2193/sun/G4data/RadioactiveDecay4.3.2
G4ABLADATA=/mnt/simulations/proton_detector/Geant4/geant4.10.2-install/share/Geant4-10.2.2/data/G4ABLA3.0
G4PIIDATA=/mnt/simulations/proton_detector/Geant4/geant4.10.2-install/share/Geant4-10.2.2/data/G4PII1.3
G4SAIDXSDATA=/mnt/simulations/proton_detector/Geant4/geant4.10.2-install/share/Geant4-10.2.2/data/G4SAIDDATA1.1
G4REALSURFACEDATA=/mnt/simulations/proton_detector/Geant4/geant4.10.2-install/share/Geant4-10.2.2/data/RealSurface1.0

