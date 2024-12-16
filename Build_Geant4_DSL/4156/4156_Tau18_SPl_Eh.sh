num1=1
num2=40
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele4156_Eh_Tau18
 mv Eh/ExG4_Eh.root Eh/S31_Gamma4156_Eg4156.15_Tau18.0_SP0.60_AC0.0_No${i}.root
 done
rm -f Eh/S31_Gamma4156_Eg4156.15_Tau18.0_SP0.60_AC0.0_all.root
hadd Eh/S31_Gamma4156_Eg4156.15_Tau18.0_SP0.60_AC0.0_all.root Eh/S31_Gamma4156_Eg4156.15_Tau18.0_SP0.60_AC0.0_No*.root
