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
    cout<<"This program converts number of work hours to number of days"<<endl;
    cout<<"And demonstrates different overloaded operators."<<endl;
    do{
        cout<<"Enter the number hours to be converted "<<endl;
        cin>>hours;
    }while(hours<0);
    hrsToDays.setHours(hours);
    cout<<"The number of days this is: \n";
    cout<<hrsToDays.getDays();
    cout<<"\nThis part of the program demonstrates overloaded operators"<<endl;
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
    cout<<"\nThe added amount of days is ";
    NumDays combined=hrsToDays1+hrsToDays2; //combined days of both inputs
    cout<<combined.getDays();
    cout<<"\nThe subtracted days is:";
    NumDays combine=hrsToDays1-hrsToDays2; //combined days of both inputs
    cout<<combine.getDays();
    cout<<"\nIncrementing Days (Prefix operator)"<<endl;
    NumDays incre1pre = ++hrsToDays1;//increment days of first input(prefix)
    NumDays incre2pre = ++hrsToDays2;//increment days of second input(prefix)
    cout<<"For first input: "<<incre1pre.getDays()<<endl;
    cout<<"For second input: "<<incre2pre.getDays()<<endl;
    cout<<"Incrementing Days (Postfix operator)"<<endl;
    NumDays incre1pst = hrsToDays1++; //incrementing days of first input(postfix)
    NumDays incre2pst = hrsToDays2++;//incrementing days of second input(postfix)
    cout<<"For first input: "<<incre1pst.getDays()<<endl;
    cout<<"For second input: "<<incre2pst.getDays()<<endl;
    cout<<"Decrementing Days (prefix)"<<endl;
    NumDays decr1pre = --hrsToDays1;//decrement days of first input(prefix)
    NumDays decr2pre = --hrsToDays2;//decrement days of second input(prefix)
    cout<<"For first input: "<<decr1pre.getDays()<<endl;
    cout<<"For second input: "<<decr2pre.getDays()<<endl;
    cout<<"Decrementing Days (postfix)"<<endl;
    NumDays decr1pst = hrsToDays1--;//decrement days of first input(postfix)
    NumDays decr2pst = hrsToDays2--;//decrement days of second input(postfix)
    cout<<"For first input: "<<decr1pst.getDays()<<endl;
    cout<<"For second input: "<<decr2pst.getDays()<<endl;
    return 0;
}

