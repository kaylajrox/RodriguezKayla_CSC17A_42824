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
  string Numbers::thousand= "thousand";
  string Numbers::hundred= "hundred";
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
    
    
    for(int i=0;i<SIZE;i++){
        result+=lessThan20[i];
    }
    result+=" "+thousand;
        
    //Output the 100's
    for(int i=1;i<SIZE;i++){
        if(i==n100s)
            result+=lessThan20[i];
     }
    result+=" "+hundred;
//    cout<<result;
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
                result+=lessThan20[number]; 
        break;}
   
    if(n10s==0){
        //Output the 1's
        result+=lessThan20[number];         
    }
cout << result << endl;
 }
 }
