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
#include <ctime>
#include <cstdlib>
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
void sortary(float*,int);
void display(float*,int);
void avScore(float*,int);
int *fillAry(int);
int *fillMod(int,int);
void prntAry(int *,int,int);
void markSrt(int *,int);
int *mode(int *,int,int,int);
int findMax (int*,int);
void prntMod(int *,int);
int numMode(int *,int,int);
int *freqF(int*,int,int);
float median(int*,int);
float mean(int*,int);


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
        cout<<"Type 4 to Display Gaddis_8thEd_Chap9_Prob7"<<endl;
        cout<<"Type 5 to Display Gaddis_8thEd_Chap9_Prob7"<<endl;
        cout<<"Type 6 to Display Mean Median and Mode Problem"<<endl;
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
     //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare and allocate the array
    int size=50;
    int mod=10;
    int *array=fillMod(size,mod);
    //Creating frequency array
    int *freq=freqF(array,mod,size);
    //Find the max Frequency
    int max=findMax(freq,mod);
    //Find the number of modes
    int nModes=numMode(freq,mod,max);
    //Find the modes
    int *modes=mode(freq,mod,max,nModes);
    //Display the random array
    cout<<"The Original Array"<<endl;
    prntAry(array,size,10);
    //Sort the Random Array
    markSrt(array,size);
    //Display the Sorted array
    cout<<"The Sorted Random Array"<<endl;
    prntAry(array,size,10);
    //Display Max frequency and Number of modes
    cout<<"Max frequency: "<<max<<" "<<endl;
    cout<<"Number of Modes: "<<nModes<<endl;
    if (nModes>1){
        cout<<"The modes are: ";
    }else
        cout<<"The mode is ";
    //Print Mode
    prntAry(modes,nModes,10);
    //Display Median
    cout<<"The median is ";
    float medianF=median(array,size);
    //Display Mean
    cout<<"\nThe mean of this set is ";
    float meanF=mean(array,size);
    cout<<meanF;

    //Deallocate Memory
    delete []array;
    delete []freq;
    delete []modes;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Print Array
//Inputs
//     n->Size of the array
//     a->Array
//Output
//     a->The sorted array
////////////////////////////////////////////////////////////////////////////////
void markSrt(int *a,int n){
    for(int pos=0;pos<n-1;pos++){
        for(int row=pos+1;row<n;row++){
            if(*(a+pos)>*(a+row)){
                *(a+pos)=*(a+pos)^*(a+row);
                a[row]=a[pos]^a[row];
                *(a+pos)=*(a+pos)^*(a+row);
            }
        }
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Print Array
//Inputs
//     n->Size of the array
//     a->Array
//     perLine->Number of integers to display per row
////////////////////////////////////////////////////////////////////////////////
void prntAry(int *a,int n,int perLine){
    //Output the Array
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                Fill Array
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with 2 digit integers
////////////////////////////////////////////////////////////////////////////////
int *fillMod(int size,int mod){
    //Declare and allocate memory
    int *a=new int[size];
    //Loop and fill with 2 digit numbers
    for(int i=0;i<size;i++){
        *(a+i)=rand()%mod;
    }
    //return the pointer
    return a;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                Print Mode
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with 2 digit integers
////////////////////////////////////////////////////////////////////////////////
int *mode(int *freq,int size,int max,int nModes){
    //Declare and allocate memory
    int *a=new int[nModes];
    int index=0;
    for (int i=0;i<size;i++){
        if (freq[i]==max){
            a[index]=i;
            index++;
        }
    }
    //return the pointer
    return a;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                              Find Max Frequency
////////////////////////////////////////////////////////////////////////////////
int findMax (int *a,int size){
    int max=0;
    for (int i=0;i<size;i++){
        if (a[i]>max)
            max=a[i];
    }
    return max;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                              Number of Modes
////////////////////////////////////////////////////////////////////////////////
int numMode(int *a,int size,int max){
    int counter=0;
    for (int i=0;i<size;i++){
        if (a[i]==max)
            counter++;
    }
    return counter;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                              Frequency Array Creation
////////////////////////////////////////////////////////////////////////////////
int *freqF(int *array,int mod,int size){
    int *freq=new int[mod];
    for (int i=0;i<mod;i++){
        freq[i]=0;
    }//loop from 0 to size
    for (int i=0;i<size;i++){
        freq[array[i]]++;
    }
    return freq;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                              Median Calculation
//Inputs: n--> size
//
//Outputs: median position
////////////////////////////////////////////////////////////////////////////////
float median(int *array,int n){
    float median;
    if (n%2==0){
        cout<<array[n/2];
    }else
        cout<<array[(n/2)-1];
    return median;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                              Median Calculation
////////////////////////////////////////////////////////////////////////////////
float mean(int *array,int n){
    float sum=0,mean;
    for(int i=0;i<n;i++){
        sum+=*(array+i);
    }
    mean=sum/n;
    return mean;
}
