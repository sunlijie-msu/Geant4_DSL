num1=23
num2=25
 #num1<num2
cd /mnt/hgfs/Geant4_DSL/Build_Geant4_DSL
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele7333_Em_AD-0.9_Tau7
 mv ExG4-09.root Mg23_Gamma7333_Eg7333.20_Tau7.0_SP1.00_AD-0.9_No${i}.root
 mv Mg23_Gamma7333_Eg7333.20_Tau7.0_SP1.00_AD-0.9_No${i}.root /mnt/hgfs/out/
 done
cd /mnt/hgfs/out/
rm -f Mg23_Gamma7333_Eg7333.20_Tau7.0_SP1.00_AD-0.9_all.root
hadd Mg23_Gamma7333_Eg7333.20_Tau7.0_SP1.00_AD-0.9_all.root Mg23_Gamma7333_Eg7333.20_Tau7.0_SP1.00_AD-0.9_No*.root
