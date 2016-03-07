/*
    File:   main.cpp
    Author: Kayla Rodriguez
    Created on February 3, 2016, 8:35 PM
    Purpose:  Menu
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
void sortary(float*,int);
void display(float*,int);
void avScore(float*,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned short nSoltn;//Problem Solution to display
    bool reDsply=true;    //Exit program when false

    //Menu to Display Solution
    do{
        //Input problem to display, i.e. Menu
        cout<<"\nAssignment 2 Problem Set"<<endl;
        cout<<"Type 1 to Display Gaddis_8thEd_Chap9_Prob2"<<endl;
        cout<<"Type 2 to Display Gaddis_8thEd_Chap9_Prob6"<<endl;
        cout<<"Type 3 to Display Gaddis_8thEd_Chap9_Prob7"<<endl;
        cout<<"Type anything else to exit "<<endl<<endl;
        cin>>nSoltn;
        //Solutions to all the problems
        switch(nSoltn){
            case 1:{problem1();break;}
            case 2:{problem2();break;}
            case 3:{problem3();break;}
            case 4:{problem4();break;}
            case 5:{problem5();break;}
            case 6:{problem6();break;}
            case 7:{problem7();break;}
            case 8:{problem8();break;}
            case 9:{problem8();break;}
            case 10:{problem8();break;}
            default:{
                cout<<"Exiting the Program"<<endl;
                reDsply=false;
            }
        }
    }while(reDsply);

    //Exit stage right
    return 0;
}
/******************************************************************************/
/************************** Problem 1 *****************************************/
/******************************************************************************/
void problem1(){
    cout<<endl<<"Solution to Gaddis_8thEd_Chap9_Prob2"<<endl;
    cout<<endl<<"Test Scores #1"<<endl<<endl;
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
/******************************************************************************/
/************************** Problem 2 *****************************************/
/******************************************************************************/
void problem2(){
    //The problem to solve
    cout<<endl<<"Solution to Gaddis_8thEd_Chap9_Prob6"<<endl;
    cout<<endl<<"Case Study Modification #1"<<endl<<endl;

}
/******************************************************************************/
/************************** Problem 3 *****************************************/
/******************************************************************************/
void problem3(){
    //The problem to solve
    cout<<endl<<"Solution to Gaddis_8thEd_Chap9_Prob7"<<endl;
    cout<<endl<<"Case Study Modification #2"<<endl<<endl;

}/******************************************************************************/
/************************** Problem 4 *****************************************/
/******************************************************************************/
void problem4(){
   cout<<endl<<""<<endl;
   cout<<endl<<""<<endl<<endl;

}
/******************************************************************************/
/************************** Problem 5 *****************************************/
/******************************************************************************/
void problem5(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;

}
/******************************************************************************/
/************************** Problem 6 *****************************************/
/******************************************************************************/
void problem6(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;

}

/******************************************************************************/
/************************** Problem 7 *****************************************/
/******************************************************************************/
void problem7(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;

}

/******************************************************************************/
/**************************  Problem 8  ***************************************/
/******************************************************************************/
void problem8(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;
}
/******************************************************************************/
/**************************  Problem 9  ***************************************/
/******************************************************************************/
void problem9(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;
}
/******************************************************************************/
/**************************  Problem 10 ***************************************/
/******************************************************************************/
void problem10(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;
}
