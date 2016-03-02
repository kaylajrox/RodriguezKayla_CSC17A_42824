/* 
 * Author: Kayla Rodriguez
 * Created on March 2, 2016, 1:11 PM
 * Purpose: Celsius to Fahrenheit Conversion
 */
 
//System Libraries
#include <iostream>
using namespace std;
 
//User Libraries
 
//Global Constant

//Function Prototypes
 
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    float c; //Celsius variable 
    //Input 
    cout<<"Please type in a Celsius temperature to be converted to Fahrenheit: ";
    cin>>c;
    
    //Calculation
    float f=9*c/5+32; //Fahrenheit calculation
    
    //Output
    cout<<"The Fahrenheit conversion is "<<f<<" degrees."<<endl;
    //Exit stage right
    return 0;
}