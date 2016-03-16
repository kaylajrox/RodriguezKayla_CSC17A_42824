/*Author: Kayla Rodriguez
 * Purpose: Sorting names from a file
 Comments/Concerns:
 This program is a work in progress and has not yet been finished
 I need to first remove the errors

 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function Prototypes
void selSort(string,const int);
void rdfile(string,const int,ifstream);
void display(string,const int);
//Execution Begins Here
int main(int argc, char** argv){
    //Declare Variables to open files
    ifstream infile;
    ofstream out;
    const int nNames=3;
    string names[nNames];
    
    //Open Files
    infile.open("Input Names.txt");
    out.open("Output.txt");
    
    //Read the file
    rdfile(names,nNames,infile);
    
    //Sort the Names using selection sort function
    selSort(names,nNames);
    
    //Display and Output the sorted names
    display(names,nNames);
    
    //Close the files
    infile.close;
    out.close;
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Selection Sort
//Inputs:
//  a->Array or List
//  n->Size of List
//Outputs:
//  a->Sorted Array
//******************************************************************************
void selSort(int a[],const int n){
    for(int i=0;i<n-1;i++){
        int val=a[i],pos=i;
        //Inside List above the Element
        for(int j=i+1;j<n;j++){
            //Swap
            if(val>a[j]){
                val=a[j];pos=j;
            }
        }
        //Swap
        a[pos]=a[i];
        a[i]=val;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Read the file
//******************************************************************************
void rdfile(string names,const int size,ifstream &infile){
    for(int i=0;i<size;i++){
        infile>>names[i];
    }    
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                           Display
//******************************************************************************
void display(string names,const int size){
    for(int i=0;i<size;i++){
       cout<<names[i]; 
    }   
}
