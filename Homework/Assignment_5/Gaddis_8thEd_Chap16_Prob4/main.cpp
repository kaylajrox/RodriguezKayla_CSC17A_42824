/* 
 * File:   main.cpp
 * Author: Kayla
 * Problem: Absolute Value Template
 * Created on May 30, 2016, 9:40 PM
 */

/* Write a function template that accepts an argument and returns its absolute 
 * value. The absolute value of a number is its value with no sign. For example, 
 * the absolute value of 5 is 5, and the absolute value of 2 is 2. Test the 
 * template in a simple driver program. */

#include <iostream>

#include "AbsValue.h"
using namespace std;

int main(int argc, char** argv) {
    //declare variables
    float number;
    AbsValue <float> num;
    
    cout<<"Enter a number to have the absolute value taken of "<<endl;
    cin>>number;
    num.setAbs(number);
    
    cout<<num.findAbs();
    
    return 0;
}

