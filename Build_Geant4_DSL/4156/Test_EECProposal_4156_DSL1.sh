num1=21
num2=100
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele_DSL1
 mv Em/ExG4_Em_DSL1.root Em/S31_Gamma4156_Eg4155.84_Tau1.0_SP1.00_AC0.0_DSL1_No${i}.root
 done
rm -f Em/S31_Gamma4156_Eg4155.84_Tau1.0_SP1.00_AC0.0_all_DSL1.root
# hadd Em/S31_Gamma4156_Eg4155.84_Tau1.0_SP1.00_AC0.0_all_DSL1.root Em/S31_Gamma4156_Eg4155.84_Tau1.0_SP1.00_AC0.0_DSL1_No*.root
