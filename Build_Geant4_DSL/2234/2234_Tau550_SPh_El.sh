num1=1
num2=55
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele2234_El_Tau550
 mv El/ExG4_El.root El/S31_Gamma2234_Eg2231.97_Tau550.0_SP1.20_AC0.0_No${i}.root
 done
rm -f El/S31_Gamma2234_Eg2231.97_Tau550.0_SP1.20_AC0.0_all.root
hadd El/S31_Gamma2234_Eg2231.97_Tau550.0_SP1.20_AC0.0_all.root El/S31_Gamma2234_Eg2231.97_Tau550.0_SP1.20_AC0.0_No*.root
