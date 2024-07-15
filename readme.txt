DSL1 and DSL2 simulation
VMware can use these files.

cdd
cd /home/sun/app/Geant4_DSL-build

1) cmd
cmake -DGeant4_DIR=/home/sun/app/geant4.10.02-install/lib/Geant4-10.2.3 /mnt/hgfs/Geant4_DSL

2) make

3) ./tele vis


bashrc:
source /home/sun/app/geant4.10.02-install/bin/geant4.sh
source /home/sun/app/root6/bin/thisroot.sh
export ROOTSYS=/home/sun/app/root6
export PATH=$ROOTSYS/bin:$PATH
export LD_LIBRARY_PATH=$ROOTSYS/lib:$LD_LIBRARY_PATH

ROOT version 6.06.08
cmake version 3.16.3
gcc version 9.4.0

As of 20240515,
23Mg Ex=7336; DSSD 75um; Tau=5

source /usr/opt/jessie.sh
source /etc/profile.d/module.sh
lsb_release -a
Distributor ID:	Debian
Description:	Debian GNU/Linux 8.11 (jessie)
Release:	8.11
Codename:	jessie
module avail
gcc -v
4.9.2
root-config --version
6.06.02
cmake --version
3.6.3

godsl2
cd 
rm -rf CM*; rm -rf cm*
cmake -DGeant4_DIR=/mnt/simulations/proton_detector/Geant4/geant4.10.2-install/lib/Geant4-10.2.2 /mnt/analysis/triumf_s2193/sun/Geant4_DSL_Jul2024

