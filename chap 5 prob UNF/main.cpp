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
    unsigned int nOrg; //starting number or organisms
    float percGro;
    unsigned int days;
    unsigned int popSize; //population size
    
    //Input
    do{
    cout<<"What is the starting number of organisms?"<<endl;
    cout<<"Enter a number greater than 2."<<endl;
    cin>>nOrg;
    }while (nOrg>=2);
        cout<<"What is their average population increase (in percentage)? "<<endl;
        cin>>percGro;
        cout<<"What is the number of days they will multiply?"<<endl;
        cin>>days;

        //Loop to generate the population for each new day
        cout<<"Day   Population Size"<<endl;
        for(int nDays=1;nDays<=days;nDays++){
            //Calculate
            unsigned int popSize=(nOrg+(percGro*nOrg/100))*nDays;
            //Display
            cout<<nDays<<"\t"<<popSize<<endl;
            }     
    //Exit stage right
    return 0;
}