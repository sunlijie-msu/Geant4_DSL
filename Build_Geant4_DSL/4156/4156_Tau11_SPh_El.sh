num1=1
num2=40
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele4156_El_Tau11
 mv El/ExG4_El.root El/S31_Gamma4156_Eg4155.53_Tau11.0_SP1.20_AC0.0_No${i}.root
 done
rm -f El/S31_Gamma4156_Eg4155.53_Tau11.0_SP1.20_AC0.0_all.root
hadd El/S31_Gamma4156_Eg4155.53_Tau11.0_SP1.20_AC0.0_all.root El/S31_Gamma4156_Eg4155.53_Tau11.0_SP1.20_AC0.0_No*.root
