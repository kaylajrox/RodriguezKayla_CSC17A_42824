/* 
 * File:   main.cpp
 * Author: Kayla Rodriguez
 * Created on January 4, 2016, 10:18 AM
 * Purpose: Test Scores #1
 * Gaddis_8thEd_Chap9_Prob2:
 * 
  Write a program that dynamically allocates an array large enough to hold user
  defined number of test scores. Once all the scores are entered, the array 
  should be passed to a function that sorts them in ascending order. Another 
  function should be called that calculates the average score. The program
  should display the sorted list of scores and averages the appropriate headings.
  Use pointer notation rather than the array notation whenever possible.
 * DO NOT ACCEPT NEGATIVE NUMBERS FOR TEST SCORES
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
 int nTstSre; //Number of test scores
 int *score;   //test score
    //Input
    cout<<"How many test scores do you have? ";
    cin>>nTstSre;
    do{
    cout<<"Enter the test scores. After each new test score, press enter."<<endl;
    cin>>*score;
    }while (!score>=0);

    //Exit stage right
    return 0;
}