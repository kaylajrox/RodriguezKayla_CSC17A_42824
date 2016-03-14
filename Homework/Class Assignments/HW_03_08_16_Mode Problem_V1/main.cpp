/* 
 * File:   main.cpp
 * Author: Kayla Rodriguez
 * Created on March 7, 2016, 12:41 PM
 * Purpose: Homework Assignment 03/08/16

  Write a program that dynamically allocates an array and uses a function to 
  return the mode of the array
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void fillAry(int*,int); //fill the array with inputted values function
void selSrt(int*,int);  //sort the values in the array function
void DsplyMd(int*,int); //Display Mode function
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the seed
    srand(static_cast<unsigned int>(time(0)));   
    //Declare Variables
    int size; //Number of test scores
    int *set;//test score
    //Input
    cout<<"How many numbers do you want in your set? This will be filled "<<endl;
    cout<<"randomly generated numbers."<<endl;
    cin>>size;
    set = new int[size];
    //Fill the Array with Inputted Numbers
    fillAry(set,size);
    //Sort the Array
    selSrt(set,size);
    //Display the Mode of the Set
    
    //free memory
    delete[] set;
    //Exit stage right
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                    Fill the Array with Inputted Numbers                    */
/******************************************************************************/
void fillAry(int *set,int size){
    cout<<"Enter the numbers in your set "<<endl;
    for(int i=0;i<size;i++){
        cout<<"Number "<<(i+1)<<": ";
        cin>>*(set+i);
    }  
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Selection Sort
//Inputs:
//  set->Array or List
//  size->Size of List
//Outputs:
//  set->Sorted Array
//******************************************************************************
void selSrt(int *set,int size){
    //Find smallest in each successive list
    //From the beginning of the list to the end
    //Outside Element of the list
    for(int i=0;i<size-1;i++){
        int val=set[i],pos=i;
        //Inside List above the Element
        for(int j=i+1;j<size;j++){
            //Swap
            if(val>set[j]){
                val=set[j];pos=j;
            }
        }
        //Swap
        set[pos]=set[i];
        set[i]=val;
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Display and return the mode                         */
/******************************************************************************/
void DsplyMd(int *set,int size){
    int counter=0;
    for (int j=0;j<size;j++){ 
        for(int i=0;i<size;i++){
            if(*(set+i)=*(set+j)){
                counter++;
            }
        }
    } 
    for (int i=0;i<size;i++){
        cout<<set[i]<<" Appeared "<<counter<<" times."<<endl;
    }
}
