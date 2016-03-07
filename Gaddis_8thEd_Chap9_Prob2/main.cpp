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
#include <vector>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void sortary(float*,int);
void display(float*,int);
void avScore(float*,int);
//Execution Begins Here
int main(int argc, char** argv) {
 int size; //Number of test scores
 float *score;   //test score
  cout<<fixed<<setprecision(1);
    //Input
    cout<<"How many test scores do you have? ";
    cin>>size;
    score = new float[size];
    cout<<"Enter the test scores. After each new test score, press enter."<<endl;
    for(int i=0;i<size;i++){
        do{ 
            cout<<"Enter score "<<(i+1)<<endl;
            cin>>*(score+i);
        }while (*(score+i)<0);
    }
    //Sort the Scores
    sortary(score,size);
    //Display the Scores
    cout<<"The scores from highest to lowest are: "<<endl;
    display(score,size);
    avScore(score,size);
    
    //free memory
    delete[] score;
    //Exit stage right
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                 Sort the Scores/ Selection Sort                            */
/******************************************************************************/
void sortary(float *score,int size){
    int minI,minVal;
     for (int i=0;i<size;i++){
        minI=i;
        minVal = *(score+i);
        for (int j=i+1;j<size;j++){
            if (*(score+j)>minVal){
                minVal=*(score+j);
                minI=j;
            }
        }
        score[minI]=score[i];
        score[i]=minVal;
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Display Scores                                      */
/******************************************************************************/
void display(float *score,int size){
     for(int i=0;i<size;i++){
        cout<<*(score+i)<<" ";
        cout<<endl;
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                          Average the Scores                                */
/******************************************************************************/
void avScore(float *score,int size){
    float sum=0;
    for(int i=0;i<size;i++){
        sum+=*(score+i);
    }
    cout<<"The average test score was "<<(sum/size)<<endl<<endl;    
}