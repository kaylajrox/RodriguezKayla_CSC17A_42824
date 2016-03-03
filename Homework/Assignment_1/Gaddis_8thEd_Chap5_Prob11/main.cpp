/* 
    File:   main.cpp
    Author: Kayla Rodriguez
    Created on January 20, 2016, 10:35 AM
    Purpose:  Population Sizes
 */

//System Libraries
#include <iostream> //I/O
#include <iomanip>  //Formatting
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
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
    //Exit stage right
    return 0;
}