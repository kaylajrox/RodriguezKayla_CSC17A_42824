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
}
  //initialize static members
  string Numbers::thousand= "Thousand";
  string Numbers::hundred= "Hundred";
  string Numbers::lessThan20[SIZE]= {"zero", "one","two","three","four","five",
    "six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen",
    "fifteen","sixteen","seventeen","eighteen", "nineteen"}; 
  //print number function
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
    
    
   //Output the 1000's
    switch(n1000s)
    {
        case 9:  result+="Nine "+thousand+" ";break;
        case 8:  result+="Eight "+thousand+" ";break;
        case 7:  result+="Seven "+thousand+" ";break;
        case 6:  result+="Six "+thousand+" ";break;
        case 5:  result+="Five "+thousand+" ";break;
        case 4:  result+="Four "+thousand+" ";break;
        case 3:  result+="Three "+thousand+" ";break;
        case 2:  result+="Two "+thousand+" ";break;
        case 1:  result+="One "+thousand+" ";break;
     }
    
    //Output the 100's
    switch(n100s)
    {
        case 9:  result+="Nine "+hundred+" ";break;
        case 8:  result+="Eight "+hundred+" ";break;
        case 7:  result+="Seven "+hundred+" ";break;
        case 6:  result+="Six "+hundred+" ";break;
        case 5:  result+="Five "+hundred+" ";break;
        case 4:  result+="Four "+hundred+" ";break;
        case 3:  result+="Three "+hundred+" ";break;
        case 2:  result+="Two "+hundred+" ";break;
        case 1:  result+="One "+hundred+" ";break;
    }

    //Output the 10's
    switch(n10s)
    {
        case 9:  result+="Ninety ";break;
        case 8:  result+="Eighty ";break;
        case 7:  result+="Seventy ";break;
        case 6:  result+="Sixty ";break;
        case 5:  result+="Fifty ";break;
        case 4:  result+="Forty ";break;
        case 3:  result+="Thirty ";break;
        case 2:  result+="Twenty ";break;          
        case 1:  result+="";break;
        case 0:  result+="";break;
    }
    if(n10s==1){
        for(int j=1;j<9;j++){
            if(n1s==j)
                result+=lessThan20[j+10];
        }
    }
    cout<<result;
    if(n10s!=1)
    {
        for(int i=0;i<10;i++)
        {
            if(n1s==i)
               cout << lessThan20[i];
        }   
    }
 }

