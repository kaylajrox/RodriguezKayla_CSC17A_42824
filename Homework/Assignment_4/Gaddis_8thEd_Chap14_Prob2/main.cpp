/* 
 * File:   main.cpp
 * Author: Kayla Rodriguez
 * Problem: Gaddis_8thEd_Chap14_Prob2
 * Title: Day of the Year 
 */

#include <iostream>

#include "DayOfYear.h"
using namespace std;

int main(int argc, char** argv) {
    //declare variables
    int day;
    char leapQ; //leap year question
    DayOfYear info;
    //input day
    do{
        cout<<"Is it a leap year this year? Type y if yes, n if no "<<endl;
        cin>>leapQ;
        leapQ=tolower(leapQ);
        if(leapQ!='y'&&leapQ!='n')
            cout<<"Invalid answer"<<endl;
    }while(leapQ!='y'&&leapQ!='n');
    cout<<"Enter a day of the year (out of 365)"<<endl;
    cin>>day;
    if(leapQ=='y')
        info.leapYear(day);
    else
        info.print(day);
    return 0;
}

