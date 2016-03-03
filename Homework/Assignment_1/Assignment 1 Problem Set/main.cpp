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
const int COLS=30;

//Function prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void readfle(char[][COLS],int,ifstream&);
void display(char[][COLS],int);
float celsius(int);
void selectS(string[],int);
void shArray(string[],int);
int binaryS(string[],int,string);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned short nSoltn;//Problem Solution to display
    bool reDsply=true;    //Exit program when false

    //Menu to Display Solution
    do{
        //Input problem to display, i.e. Menu
        cout<<"\nAssignment 5 Problem Set"<<endl;
        cout<<"Type 1 to Display Gaddis_8thEd_Chap3_Prob12"<<endl;
        cout<<"Type 2 to Display Gaddis_8thEd_Chap3_Prob13"<<endl;
        cout<<"Type 3 to Display Gaddis_8thEd_Chap4_Prob10"<<endl;
        cout<<"Type 4 to Display Gaddis_8thEd_Chap5_Prob11"<<endl;
        cout<<"Type 5 to Display Gaddis_8thEd_Chap6_Prob7"<<endl;
        cout<<"Type 6 to Display Gaddis_8thEd_Chap7_Prob6"<<endl;
        cout<<"Type 7 to Display Gaddis_8thEd_Chap8_Prob7"<<endl;
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
    cout<<endl<<"Solution to Gaddis_8thEd_Chap3_Prob12"<<endl;
    cout<<endl<<"Celsius/Fahrenheit"<<endl<<endl;
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
    cout<<endl<<"Solution to Gaddis_8thEd_Chap3_Prob13"<<endl;
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
    cout<<endl<<"Solution to Gaddis_8thEd_Chap4_Prob10"<<endl;
    cout<<endl<<"Days in a Month"<<endl<<endl;
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
}/******************************************************************************/
/************************** Problem 4 *****************************************/
/******************************************************************************/
void problem4(){
   cout<<endl<<"Solution to Gaddis_8thEd_Chap5_Prob11"<<endl;
   cout<<endl<<"Population Sizes"<<endl<<endl;
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
    cout<<endl<<"Solution to Gaddis_8thEd_Chap6_Prob7"<<endl;
    cout<<endl<<"Temperature Table"<<endl<<endl;
    cout<<"Fahrenheit\tCelsius"<<endl;
    for (int f=1;f<=20;f++){
        cout<<f<<"\t\t"<<celsius(f)<<endl;
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                                   Celsius                                  */
/******************************************************************************/
float celsius(int f){
    float c=0;
    //Calculation
    cout<<fixed<<setprecision(1);
    c=5*((float)f-32)/9; //Celsius calculation
    return c;
}
/******************************************************************************/
/************************** Problem 6 *****************************************/
/******************************************************************************/
void problem6(){
    cout<<endl<<"Solution to Gaddis_8thEd_Chap7_Prob6"<<endl;
    cout<<endl<<"Rain Or Shine"<<endl<<endl;
    //Declare and initialize variables
    const int ROWS=3;
    char weather[ROWS][COLS];

    //Open the file
    ifstream infile;
    infile.open("RainOrShine.txt");

    //Read the file
    readfle(weather,ROWS,infile);

    //Display Results
    display(weather,ROWS);

    //Exit stage right
    infile.close();
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Read the File                                  */
/******************************************************************************/
void readfle(char weather[][COLS],const int ROWS,ifstream& infile){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            infile>>weather[i][j];
        }
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                                 Display                                    */
/******************************************************************************/
void display(char weather[][COLS],const int ROWS){
string month[]={"June","July","August"};
int sun = 0;
int rain = 0;
int cloudy = 0;
int totalS=0,totalR=0,totalC=0;
for (int i=0;i<ROWS;i++){
    for (int j=0;j<COLS;j++){
        switch (weather[i][j]){
            case 'S' : sun++;
            break;
            case 'R' : rain++;
            break;
            case 'C' : cloudy++;
            break;
        }
    }
    cout<<month[i]<<endl;
    cout<<"Rainy : "<<rain<<endl;
    cout<<"Sunny : "<<sun<<endl;
    cout<<"Cloudy: "<<cloudy<<endl<<endl;
    totalS+=sun;
    totalR+=rain;
    totalC+=cloudy;
    sun=rain=cloudy=0;
}
cout<<"Totals"<<endl;
cout<<"Rainy total "<<totalR<<endl;
cout<<"Sunny total "<<totalS<<endl;
cout<<"Cloudy total "<<totalC<<endl;

}
/******************************************************************************/
/************************** Problem 7 *****************************************/
/******************************************************************************/
void problem7(){
    cout<<endl<<"Solution to Gaddis_8thEd_Chap8_Prob7"<<endl;
    cout<<endl<<"Name Sorting"<<endl<<endl;
    //Define an array with unsorted values
    const int NAMES=20;
    string names[NAMES]={"Collins,Bill","Smith,Bart","Allen,Jim",
    "Griffin,Jim","Stamey Marty","Rose,Geri","Taylor,Terri","Johnson,Jill",
    "Allison,Jeff","Looney,Joe","Wolfe,Bill","James,Jean","Weaver,Jim,",
    "Pore,Bob","Rutherford,Greg","Javens,Renee","Harrison,Rose","Setzer,Cathy",
    "Pike,Gordon","Holland,Beth" };
    string sNames;
    int search;

    //Display the values
    cout<<"Which student would you like to find in the class? "<<endl;
    cout<<"Enter in form: LastName,FirstName with no spaces."<<endl;
    cin>>sNames;
    //Sort the values
    selectS(names,NAMES);
    search=binaryS(names,NAMES,sNames);
    if (search == -1)
        cout << "Student not in class. \n";
    else{
        cout << "Student in class."<<endl;
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Selection Sort                                 */
/******************************************************************************/
void selectS(string names[],int NAMES){
    //Declare Variables
    int strScan, mini;
    string minval;
    for (strScan=0;strScan < (NAMES-1); strScan++){
        mini=strScan;
        minval = names[mini];
        for (int i=strScan+1;i<NAMES;i++){
            if (names[i]<minval){
                minval=names[i];
                mini=i;
            }
        }
        string temp=names[strScan];
        names[strScan]=minval;
        names[mini]=temp;
    }
    cout<<endl;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Binary Sort                                */
/******************************************************************************/
int binaryS(string names[],int NAMES,string sNames){
    int pos = -1,first = 0,last = (NAMES-1);
    int middle;
    bool found = false;    // Flag

    while (!found && first <= last){
        middle = (first + last) / 2; // Calculate midpoint
        if (names[middle] == sNames){ // If value is found at mid
            pos = middle;
            found = true;
        }
        else if (names[middle] > sNames){ // If value is in lower half
            last = middle - 1;
        }
        else{
            first = middle + 1; // If value is in upper half
        }
    }
    return pos;
}
