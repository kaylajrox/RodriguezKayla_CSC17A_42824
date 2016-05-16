/* 
 * File:   main.cpp
 * Author: Kayla
 * Title: Day of the Year Modification
 * Created on May 12, 2016, 2:31 PM   
 */

#include <iostream>
#include "DayOfYear2.h"
using namespace std;

int main(int argc, char** argv) {
//declare variables
    int day;
    char leapQ; //leap year question
    DayOfYear2 info;
    //input day
    do{
        cout<<"Is it a leap year this year? Type y if yes, n if no "<<endl;
        cin>>leapQ;
        leapQ=tolower(leapQ);
        if(leapQ!='y'&&leapQ!='n')
            cout<<"Invalid answer"<<endl;
    }while(leapQ!='y'&&leapQ!='n');
    do{
        cout<<"Enter a day of the year (out of 365)"<<endl;
        cin>>day;
        info.setDay(day);
    }while(day>366&&day<1);
    if(leapQ=='y')
        info.leapYear();
    else
        info.print();
    
    cout<<"\nOriginal Day: ";
    info.print();
    ++info;
    cout<<"\nAfter Incremented Day: ";
    info.print();
    cout<<"\nThe previous day: ";
    --info;
    --info;
    info.print();
    return 0;
}

