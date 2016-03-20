/*
 * File:   main.cpp
 * Author: Kayla Rodriguez
 * Created on January 4, 2016, 10:18 AM
 * Purpose: Test Scores #2
 * Gaddis_8thEd_Chap9_Prob4:
 *
Modify the program of Programming Challenge 2 to allow the user to enter 
name-score pairs. For each student taking a test, the user types the student’s 
name followed by the student’s integer test score. Modify the sorting function 
so it takes an array holding the student names and an array holding the student 
test scores. When the sorted list of scores is displayed, each student’s name 
should be displayed along with his or her score. In stepping through the arrays, 
use pointers rather than array subscripts. 
Problems: Cannot get the string array sorted with the integer
array. The name given for the highest score should be sorted
in that way
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
void sortary(int*,int,string*);
void display(int*,int,string*);
void avScore(int*,int);
//Execution Begins Here
int main(int argc, char** argv) {
    int size; //Number of test scores
    int *score;  //test score
    string *names; //student names
    cout<<fixed<<setprecision(1);
    //Input
    cout<<"How many test scores do you have? ";
    cin>>size;
    score = new int[size];
    names = new string[size];
    cout<<"What are the names of all the students who took the class?"<<endl;
    for (int i=0;i<size;i++){
        cout<<"What is the name of student "<<(i+1)<<" ?"<<endl;
        cin>>*(names+i);
    }
    cout<<"Enter the test scores. After each new test score, press enter."<<endl;
    for(int i=0;i<size;i++){
        do{ 
            cout<<"Enter score for "<<*(names+i)<<endl;
            cin>>*(score+i);
        }while (*(score+i)<0);
    }
    //Sort the Scores
    sortary(score,size,names);
    //Display the Scores
    cout<<"The scores from highest to lowest are: "<<endl;
    display(score,size,names);
    avScore(score,size);
    
    //free memory
    delete[] score;
    delete[] names;
    //Exit stage right
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                 Sort the Scores/ Selection Sort                            */
/******************************************************************************/
void sortary(int *score,int size,string *names){
    int temp;
    string tempNme;
     for (int i=1;i<size;i++){
        for (int j=i+1;j<size;j++){
            if (*(score+j)<score[j+1]){
                //Swap Scores
                temp=score[j];
                score[j]=score[j+1];
                score[j+1]=temp;
                //Swap Names
                tempNme=names[j];
                names[j]=names[j+1];
                names[j+1]=tempNme;
            }
        }        
//        score[temp]=score[i];
//        names[tempNme]=*(names+i);
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Display Scores                                      */
/******************************************************************************/
void display(int *score,int size,string *names){
    for(int i=0;i<size;i++){
        cout<<*(names+i)<<" "<<*(score+i)<<" ";
        cout<<endl;
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                          Average the Scores                                */
/******************************************************************************/
void avScore(int *score,int size){
    float sum=0;
    for(int i=0;i<size;i++){
        sum+=*(score+i);
    }
    float av=sum/size;
    cout<<"The average test score was "<<av<<"%"<<endl<<endl;    
}