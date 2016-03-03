/* 
 * Author: Kayla Rodriguez
 * Created on March 2, 2016, 1:11 PM
 * Purpose: Celsius to Fahrenheit Conversion table
 * of first 20 temperatures
 * Chapter 6 Problem 7
 */
 
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
 
//User Libraries
 
//Global Constant

//Function Prototypes
float celsius(int);
//Execution Begins Here
int main(int argc, char** argv) { 
    cout<<"Fahrenheit\tCelsius"<<endl;
    for (int f=1;f<=20;f++){        
        cout<<f<<"\t\t"<<celsius(f)<<endl;
    }
    //Exit stage right  
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                                   Celsius                                  */
/******************************************************************************/
float celsius(int f){
    float c=0;
    //Calculation
    cout<<fixed<<setprecision(1);
    c=5*((float)f-32)/9; //Celsius calculation
    return c;    
}
