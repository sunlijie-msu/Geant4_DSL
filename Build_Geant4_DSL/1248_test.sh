num1=1
num2=50
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele
 mv Test/ExG4.root Test/S31_Gamma1248_Eg1248.40_Tau1100.0_SP1.00_AC0.0_No${i}.root
 done
rm -f Test/S31_Gamma1248_Eg1248.40_Tau1100.0_SP1.00_AC0.0_all.root
hadd Test/S31_Gamma1248_Eg1248.40_Tau1100.0_SP1.00_AC0.0_all.root Test/S31_Gamma1248_Eg1248.40_Tau1100.0_SP1.00_AC0.0_No*.root
