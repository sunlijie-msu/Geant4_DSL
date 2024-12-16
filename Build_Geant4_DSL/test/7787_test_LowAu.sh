num1=1
num2=25
 #num1<num2
 for((i=${num1};i<=${num2};i+=1));
 do
 echo Procesing file_No${i} ....
 ./tele_10fs_LowAu
 mv Test/ExG4_LowAu.root Test/Mg23_Gamma7787_Eg7791.00_Tau10.0_SP1.00_AD1.0_LowAu_No${i}.root
 done
rm -f Test/Mg23_Gamma7787_Eg7791.00_Tau10.0_SP1.00_AD1.0_LowAu.root
hadd Test/Mg23_Gamma7787_Eg7791.00_Tau10.0_SP1.00_AD1.0_LowAu.root Test/Mg23_Gamma7787_Eg7791.00_Tau10.0_SP1.00_AD1.0_LowAu_No*.root
