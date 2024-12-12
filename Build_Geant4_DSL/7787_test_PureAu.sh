num1=1
num2=25
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele_10fs_PureAu
 mv Test/ExG4_PureAu.root Test/Mg23_Gamma7787_Eg7791.00_Tau10.0_SP1.00_AD1.0_PureAu_No${i}.root
 done
rm -f Test/Mg23_Gamma7787_Eg7791.00_Tau10.0_SP1.00_AD1.0_PureAu.root
hadd Test/Mg23_Gamma7787_Eg7791.00_Tau10.0_SP1.00_AD1.0_PureAu.root Test/Mg23_Gamma7787_Eg7791.00_Tau10.0_SP1.00_AD1.0_PureAu_No*.root
