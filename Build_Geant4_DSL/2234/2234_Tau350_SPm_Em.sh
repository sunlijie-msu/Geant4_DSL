num1=1
num2=55
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele2234_Em_Tau350
 mv Em/ExG4_Em.root Em/S31_Gamma2234_Eg2233.97_Tau350.0_SP1.00_AC0.0_No${i}.root
 done
rm -f Em/S31_Gamma2234_Eg2233.97_Tau350.0_SP1.00_AC0.0_all.root
hadd Em/S31_Gamma2234_Eg2233.97_Tau350.0_SP1.00_AC0.0_all.root Em/S31_Gamma2234_Eg2233.97_Tau350.0_SP1.00_AC0.0_No*.root
