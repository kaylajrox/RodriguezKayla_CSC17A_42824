/* 
 * File:   main.cpp
 * Author: Kayla
 Problem 3 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Prob3Table.h"

//Global Constants


//Function ProtoTypes

//execution begins here
int main(int argc, char** argv) {
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
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
