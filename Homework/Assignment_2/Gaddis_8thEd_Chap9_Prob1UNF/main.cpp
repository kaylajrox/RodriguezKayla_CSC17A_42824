/*
 * File:   main.cpp
 * Author: Kayla Rodriguez
 * Created on January 4, 2016, 10:18 AM
 * Purpose: Test Scores #1
 * Gaddis_8thEd_Chap9_Prob1:
 *
 Write a function that dynamically allocates an array of integers. The function should
 accept an integer argument indicating the number of elements to allocate. The function
 should return a pointer to the array. 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void arrSelectSort(int*,int&);
void showArray(int*,int&);
void inputI(int*,int); //Input integers function

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int size; //Number of donations to be put into an array
    int *intgr;//An Array containing the donation values
    
    //Input the number of donations and each donation value
    inputI(intgr,size);
    
    //Display the donations in their original order
    cout<<"The donations, in their original order are: \n";
    showArray(intgr,size);
    
    //Sort the elements of the array of pointers
    arrSelectSort(intgr,size);
    
    //Display the sorted array
    cout<<"The sorted donations are "<<endl;
    showArray(intgr,size);
    //Exit Stage Right
    delete[] size;
    return 0;
}
void inputI(int *array,int nDon){
    
}
