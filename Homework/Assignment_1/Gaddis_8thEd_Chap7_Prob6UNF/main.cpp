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
    for(int i=0;i<ROWS-1;i++){
        for(int j=0;j<COLS-1;j++){
            infile>>weather[i][j];
        }
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                                 Display                                    */
/******************************************************************************/
void display(char weather[][COLS],const int ROWS){
int sun = 0;
int rain = 0;
int cloudy = 0;
int totalS,totalR,totalC;
for (int i=0;i<ROWS;i++){
    for (int row=0;row<COLS;row++){
        for (int col=0;col<COLS;col++){
            switch (weather[row][col]){
                case 'S' : sun++;
                break;
                case 'R' : rain++;
                break;
                case 'C' : cloudy++;
                break;
            }
        }
        // Display monthly numbers
        cout << "\nFor the month of ";
        if (row == 0)
                cout << "June."<<endl;
        else if (row == 1)
                cout << "July."<<endl;
        else if (row == 2)
                cout << "August."<<endl;
        }
    cout<<"Rainy : "<<rain<<endl;
    cout<<"Sunny : "<<sun<<endl;
    cout<<"Cloudy: "<<cloudy<<endl;
    totalS+=sun;
    totalR+=rain;
    totalC+=cloudy;   
    }

cout<<"Rainy total "<<totalR<<endl;
cout<<"Sunny total "<<totalS<<endl;
cout<<"Cloudy total "<<totalC<<endl;
    
}

