num1=1
num2=55
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele2234_Eh_Tau150
 mv Eh/ExG4_Eh.root Eh/S31_Gamma2234_Eg2235.97_Tau150.0_SP0.80_AC0.0_No${i}.root
 done
rm -f Eh/S31_Gamma2234_Eg2235.97_Tau150.0_SP0.80_AC0.0_all.root
hadd Eh/S31_Gamma2234_Eg2235.97_Tau150.0_SP0.80_AC0.0_all.root Eh/S31_Gamma2234_Eg2235.97_Tau150.0_SP0.80_AC0.0_No*.root
