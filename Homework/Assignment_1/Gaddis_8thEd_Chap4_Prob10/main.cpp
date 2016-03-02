/* 
 * Author: Kayla Rodriguez
 * Created on March 2, 2016, 1:27 PM
 * Purpose: Days in a Month
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
    int year;
    int month;
    cout<<"This program calculates whether a year is a leap year and outputs ";
    cout<<endl<<"the number of days. "<<endl;
    //Input 
    do{
    cout<<"Enter a month (1-12): ";
    cin>>month;
    }while (!(month>0&&month<=12));
    cout<<"Enter a year: ";
    cin>>year;
    
    //Calculation and Output 
    if (year%400==0){
        cout<<"29 days"<<endl;
    }
    else if (year%100!=0&&year%4==0){
        cout<<"29 days"<<endl;
    }else{
        cout<<"28 days"<<endl;
    }
    
    //Exit stage right
    return 0;
}