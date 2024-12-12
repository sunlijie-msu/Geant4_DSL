num1=1
num2=25
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele_1fs_EMGTauH
 mv Test/ExG4_TauH.root Test/Mg23_Gamma7787_Eg7787.00_Tau1.0_SP1.00_AD0.0_EMGTauH_No${i}.root
 done
rm -f Test/Mg23_Gamma7787_Eg7787.00_Tau1.0_SP1.00_AD0.0_EMGTauH.root
hadd Test/Mg23_Gamma7787_Eg7787.00_Tau1.0_SP1.00_AD0.0_EMGTauH.root Test/Mg23_Gamma7787_Eg7787.00_Tau1.0_SP1.00_AD0.0_EMGTauH_No*.root
