/* 
 * Author: Kayla Rodriguez
 * Created on March 2, 2016, 1:27 PM
 * Purpose: Currency
 */
 
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
 
//User Libraries
 
//Global Constant

//Function Prototypes
 
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    float usDlr; //Us Dollar Amount 
    //Input 
    cout<<"Please type in a U.S dollar amount to be converted to Japanese yen ";
    cout<<"and to euros. "<<endl;
    cin>>usDlr;
    
    //Calculation
    float yen=usDlr*98.93f;
    float euros=usDlr*0.74f;
     
    //Output
    cout<<fixed<<setprecision(2);
    cout<<"In Japanese yen your amount is "<<yen<<" yen."<<endl;
    cout<<"The euros conversion is "<<euros<<" euros."<<endl;
    //Exit stage right
    return 0;
}