/* 
 * File:   main.cpp
 * Author: Kayla
 * Title: Numbers Class
 * Problem: Gaddis_8thEd_Chap14_Prob1
 * Created on April 27, 2016, 10:48 PM
 */
//System Libraries
#include <iostream>
#include <string>
using namespace std;
//User Libraries
#include "Numbers.h"
int main(int argc, char** argv) {
    //declare variables
    int number;
    Numbers numInfo;
    //input number to be written in its English word form
    cout<<"Enter a number between 0-10000 ";
    cin>>number;
    numInfo.print(number);
    return 0;
}

