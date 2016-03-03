/* 
    File:   main.cpp
    Author: Kayla Rodriguez
    Created on February 3, 2016, 8:35 PM
    Purpose:  Assignment 1 Menu
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
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

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned short nSoltn;//Problem Solution to display
    bool reDsply=true;    //Exit program when false
    
    //Menu to Display Solution
    do{
        //Input problem to display, i.e. Menu
        cout<<"Assignment 1 Problem Set"<<endl;
        cout<<"Type 1 to Display Gaddis 8thEd Chap3 Prob12"<<endl;
        cout<<"Type 2 to Display Gaddis 8thEd Chap3 Prob13"<<endl;
        cout<<"Type 3 to Display Gaddis 8thEd Chap4 Prob10"<<endl;
        cout<<"Type 4 to Display Gaddis 8thEd Chap5 Prob11"<<endl;
        cout<<"Type 5 to Display Gaddis 8thEd Chap8 Prob5"<<endl;
        cout<<"Type 6 to Display Gaddis 8thEd Chap8 Prob6"<<endl;
        cout<<"Type 7 to Display Gaddis 8thEd Chap8 Prob7"<<endl;
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
    cout<<endl<<"Solution to Gaddis 8thEd Chap3 Prob12"<<endl;
    cout<<endl<<"ACelsius to Fahrenheit Conversion"<<endl<<endl;
    //Declare and initialize variables
    float c; //Celsius variable 
    //Input 
    cout<<"Please type in a Celsius temperature to be converted to Fahrenheit: ";
    cin>>c;
    
    //Calculation
    float f=9*c/5+32; //Fahrenheit calculation
    
    //Output
    cout<<"The Fahrenheit conversion is "<<f<<" degrees."<<endl;   
}
/******************************************************************************/
/************************** Problem 2 *****************************************/
/******************************************************************************/
void problem2(){
    //The problem to solve
    cout<<endl<<"Solution to Gaddis 8thEd Chap3 Prob13"<<endl;
    cout<<endl<<"Currency"<<endl<<endl;
    //Declare and initialize variables
    float usDlr; //Us Dollar Amount 
    //Input 
    cout<<"Please type in a U.S dollar amount to be converted to Japanese yen ";
    cout<<"and to euros. "<<endl;
    cin>>usDlr;
    
    //Calculation
    float yen=usDlr*98.93f;
    float euros=usDlr*0.74f;
     
    //Output
    cout<<fixed<<setprecision(2);
    cout<<"In Japanese yen your amount is "<<yen<<" yen."<<endl;
    cout<<"The euros conversion is "<<euros<<" euros."<<endl;

}
/******************************************************************************/
/************************** Problem 3 *****************************************/
/******************************************************************************/
void problem3(){
    //The problem to solve
    cout<<endl<<"Solution to Gaddis 8thEd Chap4 Prob10"<<endl;
    cout<<endl<<"Leap Year"<<endl<<endl;
    //Declare and initialize variables
    int year;
    int month;
    cout<<"This program calculates whether a year is a leap year and outputs ";
    cout<<endl<<"the number of days. "<<endl;
    //Input 
    do{
    cout<<"Enter a month (1-12): ";
    cin>>month;
    }while (!(month>0&&month<=12));
    cout<<"Enter a year: ";
    cin>>year;
    
    //Calculation and Output 
    if (year%400==0){
        cout<<"29 days"<<endl;
    }
    else if (year%100!=0&&year%4==0){
        cout<<"29 days"<<endl;
    }else{
        cout<<"28 days"<<endl;
    }     
}

/******************************************************************************/
/************************** Problem 4 *****************************************/
/******************************************************************************/
void problem4(){
   cout<<endl<<"Solution to Gaddis 8thEd Chap5 Prob11"<<endl;
   cout<<endl<<"POpulation Sizes"<<endl<<endl;
    //Declare variables
    unsigned int nOrg; //number of organisms
    float percGro;     //percentage organisms would grow
    unsigned int days; //number of days allowed to grow
    //Introduction
    cout<<"This program allows you to input an initial population amount"<<endl;
    cout<<"and outputs a table of the increase in population per day. "<<endl;
    //Input
    do{
    cout<<"What is the starting number of organisms?"<<endl;
    cout<<"Enter a number greater than or equal to 2."<<endl;
    cin>>nOrg;
    }while (!(nOrg>=2));
        cout<<"What is their average population increase (in percentage) per day? "<<endl;
        cin>>percGro;
        cout<<"What is the number of days they will multiply?"<<endl;
        cin>>days;

        //Loop to generate the population for each new day
        cout<<"Day   Population Size"<<endl;
        for(int i=1;i<=days;i++){          
            //Calculate
            unsigned int popSize=(nOrg+(percGro*nOrg/100))*i;
            //Display
             cout<<i<<"\t"<<popSize<<endl;
            }       
}
/******************************************************************************/
/************************** Problem 5 *****************************************/
/******************************************************************************/
void problem5(){
    cout<<endl<<"Solution to Gaddis 8thEd Chap8 Prob5"<<endl;
    cout<<endl<<"Rainfall Modification"<<endl<<endl; 
    
}
/******************************************************************************/
/************************** Problem 6 *****************************************/
/******************************************************************************/
void problem6(){
    cout<<endl<<"Solution to Gaddis 8thEd Chap8 Prob6"<<endl;
    cout<<endl<<"Example Modification"<<endl<<endl; 
    
}
void problem7(){
    cout<<endl<<"Solution to Gaddis 8thEd Chap8 Prob7"<<endl;
    cout<<endl<<"Example Modification Search"<<endl<<endl; 
   
}

