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
void arrSelectSort(int*,int);
void showArray(const int[],int);
void showArrPtr(int*,int);
void input(int,int*);

//Execution Begins Here
int main(int argc, char** argv) {
    int nDon; //Number of donations to be put into an array
    int *donVal;//An Array containing the donation amounts
    //An array of pointers to int
  //  int *arrPtr[nDon]={0};

    //Each element of arrPtr is a pointer to int. Make each
    //element point to an element in the donations array
    for(int count=0;count<nDon;count++)
        arrPtr[count]=&donVal[count];

    //Sort the elements of the array of pointers
    arrSelectSort(arrPtr,nDon);

    //Display the donations using the array of pointers. This
    //will display them in sorted order
    showArrPtr(arrPtr,nDon);

    //Display the donations in their original order
    cout<<"The donations, in their orignal order are: \n";
    showArray(donVal,nDon);
    delete[]donVal;
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
void arrSelectSort(int *arr,int size){
    int startScan,minIndex;
    int *minElem;

    for(startScan=0;startScan<(size-1);startScan++){
        minIndex=startScan;
        minElem=arr[startScan];
        for (int index=startScan+1;index<size;index++){
            if(*(arr[index])<*minElem){
                minElem=arr[index];
                minIndex=index;
            }
        }
        arr[minIndex]=arr[startScan];
        arr[startScan]=minElem;
    }
}
//******************************************************************************
// Input function
// This function allows the user to input any set of donations
// instead of the same donations written in as a constant
//******************************************************************************
void input(int &nDon, int *donVal){
    cout<<"How many donations do you have? ";
    cin>>nDon;
    for(int i=0;i<nDon;i++){
        do{

        }while(*(donVal+i)<0)
    }
}
//******************************************************************************
// Definition of function showArray
// This function displays the contents of the arr. size is the
// number of elements.
//******************************************************************************

void showArray(const int arr[],int size){
    for(int count=0;count<size;count++)
        cout<<arr[count]<<" ";
    cout<<endl;
}

//******************************************************************************
// Definition of function showArrPtr
// This function displays the contents of the array pointed to
// by arr. size is the number of elements.
//******************************************************************************

void showArrPtr(int *arr,int size){
    for(int count=0;count<size;count++)
        cout<<*(arr[count])<<" ";
    cout<<endl;
}
