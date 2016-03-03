/* 
 * File:   main.cpp
 * Author: Kayla Rodriguez
 * Created on January 4, 2016, 10:18 AM
 * Purpose: Example Modification Search
 * Gaddis 8thEd Chap8 Prob7
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void selectS(string[],int);
void shArray(string[],int);
int binaryS(string[],int,string);
//Execution Begins Here
int main(int argc, char** argv) {
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
    cout<<"Enter in form: LastName,FirstName."<<endl;
    getline(cin,sNames);
    //Sort the values
    selectS(names,NAMES);
    search=binaryS(names,NAMES,sNames);
    if (search == -1)
        cout << "Student not in class. \n";
    else{
        cout << "Student in class."<<endl;
    } 


    //Exit stage right
    return 0;
}
//******************************************************************************
//Definition of Selection Sort
//
//
//******************************************************************************
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
    }/

    cout<<endl;
}
//******************************************************************************
//Definition of function Binary Sort
//shArray
//
//******************************************************************************
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