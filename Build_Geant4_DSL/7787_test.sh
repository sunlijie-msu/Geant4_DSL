num1=1
num2=100
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele_pull200mm_1fs
 mv Test/ExG4_pull20cm_1fs.root Test/Mg23_Gamma7787_Eg7787.00_Tau1.0_SP1.00_AD0.0_Gepull200mm_No${i}.root
 done
rm -f Test/Mg23_Gamma7787_Eg7787.00_Tau1.0_SP1.00_AD0.0_Gepull200mm_DSL2.root
hadd Test/Mg23_Gamma7787_Eg7787.00_Tau1.0_SP1.00_AD0.0_Gepull200mm_DSL2.root Test/Mg23_Gamma7787_Eg7787.00_Tau1.0_SP1.00_AD0.0_Gepull200mm_No*.root
