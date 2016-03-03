/* 
 * File:   main.cpp
 * Author: Kayla Rodriguez
 * Created on January 4, 2016, 10:18 AM
 * Purpose: Rain or Shine
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
const int COLS=30;
//Function prototypes
void readfle(char[][COLS],int,ifstream&);
void display(char[][COLS],int);
//Execution Begins Here
int main(int argc, char** argv) {
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
    return 0;
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