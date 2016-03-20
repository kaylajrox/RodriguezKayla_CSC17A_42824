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
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void display(int*,int&);
int *inputI(int&); //Input integers function

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size; //Number of donations to be put into an array
    
    //Input the number of donations and each donation value
    int *intgr=inputI(size);
    
    //Display the Array of randomly generated integers
    cout<<"The randomly generated array "<<endl;
    display(intgr,size);
    //Exit Stage Right
    delete[] intgr;
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                   Fill Array with Randomly Generated Integers
//Inputs
//     size->Size of the array
////////////////////////////////////////////////////////////////////////////////
int *inputI(int &size){
    int *array;
    cout<<"What is the number of elements you would like to allocate?"<<endl;
    cin>>size;
    array= new int[size];
    for (int i=0;i<size;i++){
         *(array+i)=rand()%10; //Numbers between [1,10]
    }
    return array;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                  Display Integer Array
void display(int *array,int &size){
    for(int i=0;i<size;i++){
        cout<<*(array+i)<<" ";
    }
}