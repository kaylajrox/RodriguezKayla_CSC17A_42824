/* 
 * File:   Numbers.cpp
 * Author: Kayla
 * 
 * Created on April 27, 2016, 10:49 PM
 */

#include "Numbers.h"
#include <string>
using namespace std;
Numbers::Numbers() {
    number=0;
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
        case 9:  result+="Nine Thousand";break; 
        case 8:  result+="Eight Thousand ";break;
        case 7:  result+="Seven Thousand ";break;
        case 6:  result+="Six Thousand ";break;
        case 5:  result+="Five Thousand ";break;
        case 4:  result+="Four Thousand ";break;
        case 3:  result+="Three Thousand ";break;
        case 2:  result+="Two Thousand ";break;
        case 1:  result+="One Thousand ";break;
    }
    //Output the 100's
    switch(n100s){
        case 9:  result+="Nine Hundred ";break; 
        case 8:  result+="Eight Hundred ";break;
        case 7:  result+="Seven Hundred ";break;
        case 6:  result+="Six Hundred ";break;
        case 5:  result+="Five Hundred ";break;
        case 4:  result+="Four Hundred ";break;
        case 3:  result+="Three Hundred ";break;
        case 2:  result+="Two Hundred ";break;
        case 1:  result+="One Hundred ";break;
    }

    //Output the 10's
    switch(n10s){
        case 9:  result+="Ninety ";break;
        case 8:  result+="Eighty ";break;
        case 7:  result+="Seventy ";break;
        case 6:  result+="Sixty ";break;
        case 5:  result+="Fifty ";break;
        case 4:  result+="Forty ";break;
        case 3:  result+="Thirty ";break;
        case 2:  result+="Twenty ";break;
        case 1:  {if(n10s==1&&n1s==0) result+="Ten ";
        if(n10s==1&&n1s==1) result+="Eleven ";
        if(n10s==1&&n1s==2) result+="Twelve ";
        if(n10s==1&&n1s==3) result+="Thirteen ";
        if(n10s==1&&n1s==4) result+="Fourteen";
        if(n10s==1&&n1s==5) result+="Fifteen ";
        if(n10s==1&&n1s==6) result+="Sixteen ";
        if(n10s==1&&n1s==7) result+="Seventeen ";
        if(n10s==1&&n1s==8) result+="Eighteen ";
        if(n10s==1&&n1s==9) result+="Nineteen ";
        break;}
    }

    //Output the 1's
    switch(n1s){
        if(n10s==0){
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

