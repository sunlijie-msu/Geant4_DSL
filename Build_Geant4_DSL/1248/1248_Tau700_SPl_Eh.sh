num1=1
num2=50
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele_Eh_Tau700
 mv Eh/ExG4_Eh.root Eh/S31_Gamma1248_Eg1248.60_Tau700.0_SP0.80_AC0.0_No${i}.root
 done
rm -f Eh/S31_Gamma1248_Eg1248.60_Tau700.0_SP0.80_AC0.0_all.root
hadd Eh/S31_Gamma1248_Eg1248.60_Tau700.0_SP0.80_AC0.0_all.root Eh/S31_Gamma1248_Eg1248.60_Tau700.0_SP0.80_AC0.0_No*.root
