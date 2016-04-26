/* 
 * File:   main.cpp
 * Author: Kayla Rodriguez
 * Title: Date
 * Problem: Gaddis_8thEd_Chap13_Prob1
 * Created on April 25, 2016, 3:39 PM
 */
//system libraries
#include <iostream>
using namespace std;
//function prototypes
#include "Date.h"
int main(int argc, char** argv) {
    //declare variables
    int day;//day to enter
    int month; //month to enter
    int year; //year to enter
    Date dateInfo; //date information to be stored in the class
    //input
    do{
        cout<<"Input the month ";
        cin>>month;
        if(month>12||month<1)
            cout<<"Invalid month entry."<<endl;
    }while(month>12||month<1);
    dateInfo.setMonth(month);
    do{
        cout<<"Input the day ";
        cin>>day;
        if(day>31||day<1)
            cout<<"Invalid day entry."<<endl;
    }while(day>31||day<1);
    dateInfo.setDay(day);
    cout<<"Input the year ";
    cin>>year;
    dateInfo.setYear(year);
    cout<<"The date in its three forms: "<<endl;
    dateInfo.slashForm(); //slash form of the date
    dateInfo.cmaForm(); //comma form of the date
    dateInfo.mlaForm(); //formal MLA style of the date
    return 0;
}

