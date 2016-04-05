/*Author: Kayla Rodriguez
 Title: Corporate Sales Data Output
 * Gaddis_8thEd_Chap12_Prob11
 Problem 11:  
  Write a program that uses a structure to store the following data on 
  a company division:    
  Division Name (such as East, West, North, or South)  
  Quarter (1, 2, 3, or 4)    
  Quarterly Sales   
  The user should be asked for the four quarters’ sales figures for the East, 
  West, North, and South divisions. The data for each quarter for each division 
  should be written to a file. Input Validation: Do not accept negative 
  numbers for any sales figures.     */

//System Libraries
#include <bits/stdc++.h>
using namespace std;
//User Libraries
 struct Company{
        string name; //name of division
        int qrtr; //the number of quarter
        unsigned short qrtrSles; //quarter sales      
    };
//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv){   
    //Declare Variables
    const int SIZE=4;
    Company divNme[SIZE][SIZE];
    string fleNme;//file name
    ofstream out; //outfile name
    //input data for file
    cout<<"Enter a name to store the quarter sales "<<endl;
    cin.ignore();
    getline(cin,fleNme); 
    out.open(fleNme.c_str());
    //get user input for a file name
    

  
    
    return 0;
}