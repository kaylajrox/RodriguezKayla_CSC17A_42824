/* 
 * File:   main.cpp
 * Author: Kayla
 * Title: Date Exceptions
 * Created on May 30, 2016, 10:14 PM
 */

/*
 * Problem: 
 * Modify the  Date  class you wrote for Programming Challenge 1 of Chapter 13. 
 * The class should implement the following exception classes:   
 * InvalidDay   
 * -Throw when an invalid day (< 1 or > 31) is passed to the class.   
 * InvalidMonth  
 * - Throw when an invalid month (< 1 or > 12) is passed to the class.  
 */
//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Date.h"

//Execution Begins Here
int main(int argc, char** argv) {
//declare variables
    int day;//day to enter
    int month; //month to enter
    string year; //year to enter
    bool valid=true; //validation
    Date dateInfo; //date information to be stored in the class
    //input
    do{
        cout<<"Input the month ";
        cin>>month;
        if(month>12||month<1)
            cout<<"Invalid month entry."<<endl;
    }while(month>12||month<1);
    dateInfo.setMonth(month);
    cout<<"Input the day ";
    cin>>day;
    while(valid){
        try{
            dateInfo.setDay(day);
            valid=false;
        }catch(Date::EmpClass){
            cout<<"Invalid Entry. Input Day"<<endl;
            cin>>day;
        }
    }
    do{
        cout<<"Input the year ";
        cin>>year;
    }while(year.length()!=4);
    dateInfo.setYear(year);
    cout<<"The date in its three forms: "<<endl;
    dateInfo.slashForm(); //slash form of the date
    dateInfo.cmaForm(); //comma form of the date
    dateInfo.mlaForm(); //formal MLA style of the date
    return 0;
}

