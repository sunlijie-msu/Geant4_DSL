num1=1
num2=50
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele_Em_Tau200
 mv Em/ExG4_Em.root Em/S31_Gamma1248_Eg1248.40_Tau200.0_SP1.00_AC0.0_No${i}.root
 done
rm -f Em/S31_Gamma1248_Eg1248.40_Tau200.0_SP1.00_AC0.0_all.root
hadd Em/S31_Gamma1248_Eg1248.40_Tau200.0_SP1.00_AC0.0_all.root Em/S31_Gamma1248_Eg1248.40_Tau200.0_SP1.00_AC0.0_No*.root
