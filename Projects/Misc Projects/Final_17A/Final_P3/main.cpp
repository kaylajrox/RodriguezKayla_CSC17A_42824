/* 
 * File:   main.cpp
 * Author: Kayla
 Problem 3 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Prob3TableInherited.h"

//Global Constants
int cols=6;

//Function ProtoTypes
void sumTbleCol(int table[][cols],int);
void sumTbleCol(int table[][cols],int);

//execution begins here
int main(int argc, char** argv) {
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    cout<<"Table Before\n";
    for(int i=0;i<rows;i++)
    {
            for(int j=0;j<cols;j++)
            {
                cout<<naugT[i*cols+j]<<" ";
            }
            cout<<endl;
    }

    cout<<endl;
    const int *augT=tab.getAugTable();
    cout<<"Augmented Table\n";
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
        {
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                         Sum Table Columns                                  */
/******************************************************************************/
void sumTbleCol(int table[][cols],int num){
    //Total Sum of Columns
    for(int i=0;i<num;i++){
        for(int j=0;j<cols-2;j++){
            table[num-1][i]+=table[j][i];
        }
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                           Sum Table Rows                                   */
/******************************************************************************/
void sumTbleRow(int table[][cols],int num){
    //Total Sum of Rows
    for(int i=0;i<cols-1;i++){
        for(int j=0;j<cols-1;j++){
            table[i][cols-1]+=table[i][j];
        }
    }     
}