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
        int qrtrSles; //quarter sales      
    };
//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv){   
    //Declare Variables
    const int SIZE=2;
    Company divNme[SIZE][SIZE];
    string fleNme;//file name
    ofstream out; //output file name
    //Introduction
    cout<<"This Program stores quarterly sells for divisions of a company\n";
    cout<<"and outputs the results onto a text file.\n";
            
    //input data for file
    cout<<"Enter a file name to store the quarter sales "<<endl;
    getline(cin,fleNme); 
    out.open(fleNme.c_str());
    //get user input for a file name
    for(int i=0;i<SIZE;i++){
        cout<<"Input division Name"<<endl;
        cin>>divNme[i][i].name;
        for(int j=0;j<SIZE;j++){
            cout<<"Input quarter number "<<endl;
            cin>>divNme[i][j].qrtr;
            do{
                cout<<"Input quarter sales"<<endl;
                cin>>divNme[i][j].qrtrSles;
                if(divNme[i][j].qrtrSles<0)
                    cout<<"No negative sales."<<endl;
            }while(divNme[i][j].qrtrSles<0);  
        }
    }
    cout<<endl;
    //output information to a file
    for(int i=0;i<SIZE;i++){
        out<<"Division Name: "<<endl;
        out<<divNme[i][i].name<<endl;
        for(int j=0;j<SIZE;j++){
            out<<"Quarter: "<<endl;
            out<<divNme[i][j].qrtr<<endl;
            out<<"Quarterly Sales "<<endl;
            out<<divNme[i][j].qrtrSles<<endl;           
        }
        out<<endl;
    }
    out<<endl;
    return 0;
}