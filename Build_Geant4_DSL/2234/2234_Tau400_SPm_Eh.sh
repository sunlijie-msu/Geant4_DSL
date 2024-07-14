num1=1
num2=55
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele2234_Eh0.2keV_Tau400
 mv Eh/ExG4.root Eh/S31_Gamma2234_Eg2234.17_Tau400.0_SP1.00_AC0.0_No${i}.root
 done
rm -f Eh/S31_Gamma2234_Eg2234.17_Tau400.0_SP1.00_AC0.0_all.root
hadd Eh/S31_Gamma2234_Eg2234.17_Tau400.0_SP1.00_AC0.0_all.root Eh/S31_Gamma2234_Eg2234.17_Tau400.0_SP1.00_AC0.0_No*.root
