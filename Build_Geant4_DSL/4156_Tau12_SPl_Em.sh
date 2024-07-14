num1=1
num2=40
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele4156_Em_Tau12
 mv Em/ExG4_Em.root Em/S31_Gamma4156_Eg4155.84_Tau12.0_SP0.60_AC0.0_No${i}.root
 done
rm -f Em/S31_Gamma4156_Eg4155.84_Tau12.0_SP0.60_AC0.0_all.root
hadd Em/S31_Gamma4156_Eg4155.84_Tau12.0_SP0.60_AC0.0_all.root Em/S31_Gamma4156_Eg4155.84_Tau12.0_SP0.60_AC0.0_No*.root
