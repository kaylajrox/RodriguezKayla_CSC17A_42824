/* 
 * File:   main.cpp
 * Author: Kayla
 * Title: NumDays Class
 * Gaddis_8thEd_Chap14_Prob4
 * Created on May 18, 2016, 1:23 PM
 */

/*Problem:Design a class called NumDays. The class’s purpose is to store a value 
that represents a number of work hours and convert it to a number of days. 
For example, 8 hours would be converted to 1 day, 12 hours would be converted to 
1.5 days, and 18 hours would be converted to 2.25 days. The class should have a 
constructor that accepts a number of hours, as well as member functions for 
storing and retrieving the hours and days. The class should also have the 
following overloaded operators:
+ Addition operator. When two NumDays objects are added together, the overloaded
+ operator should return the sum of the two objects’ hours members.
− Subtraction operator. When one NumDays object is subtracted from another,
the overloaded − operator should return the difference of the two objects’ hours
members.
++ Prefix and postfix increment operators. These operators should increment the
number of hours stored in the object. When incremented, the number of days
should be automatically recalculated.
−− Prefix and postfix decrement operators. These operators should decrement the
number of hours stored in the object. When decremented, the number of days
should be automatically recalculated. */
//System Libraries
#include <iostream>
using namespace std;
//User Libraries
#include "NumDays.h"
int main(int argc, char** argv) {
    //declare variables
    float hours,hours1,hours2;
    NumDays hrsToDays,hrsToDays1,hrsToDays2;
    //input
    cout<<"This program converts number of hours to number of days"<<endl;
    do{
        cout<<"Enter the number hours to be converted "<<endl;
        cin>>hours;
    }while(hours<0);
    hrsToDays.setHours(hours);
    cout<<"The number of days this is: ";
    hrsToDays.getDays();
    cout<<" days."<<endl;
    cout<<"This part of the program demonstrates overloaded operators"<<endl;
    cout<<"Adding Days"<<endl;
    //Adding Days
    do{
        cout<<"Enter the number hours to be converted "<<endl;
        cin>>hours1;
    }while(hours1<0);
    hrsToDays1.setHours(hours1);
    do{
        cout<<"Enter the number hours to be converted "<<endl;
        cin>>hours2;
    }while(hours2<0);
    hrsToDays2.setHours(hours2);
    hrsToDays1.getDays();
    hrsToDays2.getDays();
    cout<<"The added amount of days is ";
    float combined=hrsToDays1+hrsToDays2; //combined days of both inputs
    cout<<combined;
    cout<<"Incrementing Days (Prefix operator)"<<endl;
    float incre1pre = ++hrsToDays1;//increment days of first input(prefix)
    float incre2pre = ++hrsToDays2;//increment days of second input(prefix)
    cout<<"For first input: "<<incre1pre<<endl;
    cout<<"For second input: "<<incre2pre<<endl;
    cout<<"Incrementing Days (Postfix operator)"<<endl;
    float incre1pst = hrsToDays1++; //incrementing days of first input(postfix)
    float incre2pst = hrsToDays2++;//incrementing days of second input(postfix)
    cout<<"For first input: "<<incre1pst<<endl;
    cout<<"For second input: "<<incre2pst<<endl;
    cout<<"Decrementing Days"<<endl;
    return 0;
}

