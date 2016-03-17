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
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void arrSelectSort(int*,int);
void showArray(int*,int);
int *input(int &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int nDon; //Number of donations to be put into an array
    int *donVal;//An Array containing the donation values

    //Input the number of donations and each donation value
    donVal=input(nDon);

    //Display the donations in their original order
    cout<<"The donations, in their original order are: \n";
    showArray(donVal,nDon);

    //Sort the elements of the array of pointers
    arrSelectSort(donVal,nDon);

    //Display the sorted array
    cout<<"The sorted donations are "<<endl;
    showArray(donVal,nDon);
    //Exit Stage Right
    delete[] donVal;
    return 0;
}
//******************************************************************************
// Definition of function arrSelectSort
// This function performs aan ascending order selection sort on
// arr, which is an array of pointers. Each elements of array
// points to an element of a second array. After the sort,
// arr will point to the elements of the second array in
// ascending order
//******************************************************************************
void arrSelectSort(int *arr,int nDon){
    //Declare Variables
    int strScan, mini, minval;
    for (strScan=0;strScan < (nDon-1); strScan++){
        mini=strScan;
        minval = arr[strScan];
        for (int i=strScan+1;i<nDon;i++){
            if (arr[i]<minval){
                minval=arr[i];
                mini=i;
            }
        }
        arr[mini]=arr[strScan];
        arr[strScan]=minval;
    }
}
//******************************************************************************
// Input function
// This function allows the user to input any set of donations
// instead of the same donations written in as a constant
//******************************************************************************
int *input(int &nDon){
    int *donVal;
    cout<<"How many donations do you have? ";
    cin>>nDon;
    donVal= new int[nDon];
    for(int i=0;i<nDon;i++){
        do{
            cout<<"Enter Donation "<<(i+1)<<endl;
            cin>>donVal[i];
        }while(*(donVal+i)<0);
    }
    return donVal;
}
//******************************************************************************
// Definition of function showArray
// This function displays the contents of the array
//******************************************************************************

void showArray(int *arr,int nDon){
    for(int count=0;count<nDon;count++)
        cout<<*(arr+count)<<" ";
    cout<<endl;
}
