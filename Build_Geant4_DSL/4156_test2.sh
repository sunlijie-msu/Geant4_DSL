num1=1
num2=30
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele_1fs
 mv Test/ExG4_1fs.root Test/S31_Gamma4156_Eg4155.84_Tau1.0_SP1.00_AD0.0_Gepull100mm_No${i}.root
 done
rm -f Test/S31_Gamma4156_Eg4155.84_Tau1.0_SP1.00_AD0.0_Gepull100mm_DSL2.root
hadd Test/S31_Gamma4156_Eg4155.84_Tau1.0_SP1.00_AD0.0_Gepull100mm_DSL2.root Test/S31_Gamma4156_Eg4155.84_Tau1.0_SP1.00_AD0.0_Gepull100mm_No*.root
