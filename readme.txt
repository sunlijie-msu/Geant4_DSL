DSL1 and DSL2 simulation
VMware can use these files.

cdd
cd /home/sun/app/HPGe_DSL-build

1) cmd
cmake -DGeant4_DIR=/home/sun/app/geant4.10.02-install/lib/Geant4-10.2.3 /mnt/hgfs/HPGe_DSL

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