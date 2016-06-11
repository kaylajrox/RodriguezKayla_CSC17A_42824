/* Author: Kayla
 * Final */
//Library includes Here
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

//Global Constants 

//User Libraries
#include "Prob3TableInherited.h"

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    bool reDsply=true;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break; 
        case 6:    problem6();break;
        default:   {def(inN);
                    reDsply=false;}
        }
    }while(reDsply);
    return 0;
}

void Menu(){
    cout<<"\nMenu for Final"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}
void problem1(){
    
}

void problem2(){
   
}
void problem3(){
    cout<<"Entering Problem 3"<<endl;
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
}

void problem4(){
    
}
void problem5(){
    
}
void problem6(){
    
}
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}