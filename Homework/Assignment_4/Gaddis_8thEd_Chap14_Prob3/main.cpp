/* 
 * File:   main.cpp
 * Author: Kayla
 * Title: Day of the Year Modification
 * Created on May 12, 2016, 2:31 PM
    Modify the DayOfYear class, written in Programming Challenge 2, to add a constructor
    that takes two parameters: a string object representing a month and an integer in
    the range 0 through 31 representing the day of the month. The constructor should then
    initialize the integer member of the class to represent the day specified by the month
    and day of month parameters. The constructor should terminate the program with an
    appropriate error message if the number entered for a day is outside the range of days
    for the month given. 
     ++ prefix and postfix increment operators. These operators should modify the
    DayOfYear object so that it represents the next day. If the day is already the end
    of the year, the new value of the object will represent the first day of the year.
    −− prefix and postfix decrement operators. These operators should modify the
    DayOfYear object so that it represents the previous day. If the day is already the
    first day of the year, the new value of the object will represent the last day of the
    year. 
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
    }while(day>366&&day<1);
    if(leapQ=='y')
        info.leapYear(day);
    else
        info.print(day);
    return 0;
}

