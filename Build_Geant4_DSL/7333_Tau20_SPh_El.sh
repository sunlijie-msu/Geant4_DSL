num1=1
num2=25
 #num1<num2
cd /home/sun/app/Build_Geant4_DSL
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele7333_El_Tau20
 mv El/ExG4.root El/Mg23_Gamma7333_Eg7331.20_Tau20.0_SP1.10_AC0.0_No${i}.root
 mv El/Mg23_Gamma7333_Eg7331.20_Tau20.0_SP1.10_AC0.0_No${i}.root /mnt/hgfs/out/
 done
cd /mnt/hgfs/out/
rm -f Mg23_Gamma7333_Eg7331.20_Tau20.0_SP1.10_AC0.0_all.root
hadd Mg23_Gamma7333_Eg7331.20_Tau20.0_SP1.10_AC0.0_all.root Mg23_Gamma7333_Eg7331.20_Tau20.0_SP1.10_AC0.0_No*.root
