/* 
 * File:   Numbers.cpp
 * Author: Kayla
 * 
 * Created on April 27, 2016, 10:49 PM
 */

//system libraries
#include <string>
#include <iostream>
using namespace std;
//user libraries
#include "Numbers.h"
//do we still have to initialize even if we have set a value to it?
  Numbers::Numbers() {
    number = 0;  
//    hundred="";
//    thousand="";
//    lessThan20[SIZE] = {"", "","","","","",
//    "","","","","","","","","",
//    "","","","", ""}; 
//    SIZE=0;
}
void Numbers::print(int amount){
    number=amount;
    int n10000s,n1000s,n100s,n10s,n1s;//Number of 10^x's
    //Calculate the number of 1000's,100's,10's,1's
    n1000s=amount/1000;//Number of 1000's
    amount=(amount-n1000s*1000);     //Subtract off 1000's
    n100s =amount/100;  //Number of 100's
    amount=(amount-n100s*100);       //Subtract off 100's
    n10s  =amount/10;    //Number of 10's
    amount=(amount-n10s*10);
    n1s=amount;
    string result="";
    
    switch(n1000s){
        for(int i=1;i<=10;i++){
        lessThan20[i]; 
        if (i=n1000s)
            result+=lessThan20[i]; 
        result+=thousand;
        }
    }
    //Output the 100's
    switch(n100s){
        for(int i=1;i<=10;i++){
        lessThan20[i]; 
        if (i=n100s)
            result+=lessThan20[i]; 
        result+=hundred;
        }
    }
    switch(n10s){
        case 9:  result+="Ninety ";break;
        case 8:  result+="Eighty ";break;
        case 7:  result+="Seventy ";break;
        case 6:  result+="Sixty ";break;
        case 5:  result+="Fifty ";break;
        case 4:  result+="Forty ";break;
        case 3:  result+="Thirty ";break;
        case 2:  result+="Twenty ";break;
        case 1: {
            for(int i=10;i<=SIZE;i++){
                lessThan20[i]; 
                if (i=n1s)
                    result+=lessThan20[i]; 
            }
        }
        break;}
   
    if(n10s==0){
        //Output the 1's
        switch(n1s){
            case 9:  result+="Nine ";break;
            case 8:  result+="Eight ";break;
            case 7:  result+="Seven ";break;
            case 6:  result+="Six ";break;
            case 5:  result+="Five ";break;
            case 4:  result+="Four ";break;
            case 3:  result+="Three ";break;
            case 2:  result+="Two ";break;
            case 1:  result+="One ";break;
            }
    }
    
}
