/* 
 * File:   main.cpp
 * Author: Kayla Rodriguez
 * Created on January 4, 2016, 10:18 AM
 * Purpose: Test Scores #1
 * Gaddis_8thEd_Chap9_Prob6:
 * 
  Modify Program 9-19(the United Cause case study program) so it can be used 
  with any set of donations. The program should dynamically allocate the 
  donations array and ask the user to input its values.

 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void arrSelectSort(int*[],int);
void showArray(const int[],int);
void showArrPtr(int*[],int);

//Execution Begins Here
int main(int argc, char** argv) {
    const int NUM_DON=15; //Number of donations
    
    //An Array containing the donation amounts
    int donations[NUM_DON]={5, 100,5, 25,10,
                            5, 25, 5, 5, 100,
                            10,15, 10,5, 10};
    //An array of pointers to int
    int *arrPtr[NUM_DON]={nullptr,nullptr,nullptr,nullptr,nullptr,
                          nullptr,nullptr,nullptr,nullptr,nullptr,
                          nullptr,nullptr,nullptr,nullptr,nullptr};
    
    //Each element of arrPtr is a pointer to int. Make each
    //element point to an element in the donations array
    for(int count=0;count<NUM_DON;count++)
        arrPtr[count]=&donations[count];
    
    //Sort the elements of the ar
    return 0;
}
