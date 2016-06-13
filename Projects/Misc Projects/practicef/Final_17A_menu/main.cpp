/* Author: Kayla
 * Final */
/*Issues: 
 * problem 2 stops when it gets to column sort
 * Not sure if the output for number 4 is correct
 */
//Library includes Here
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

//Global Constants 

//User Libraries
#include "Prob3TableInherited.h"
#include "Employee.h"
#include "SavingsAccount.h"
#include "Prob1Random.h"
#include "Prob2Sort.h"

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
    cout<<"Now Entering Problem 1"<<endl;
    char n=5;
    char rndseq[]={16,34,57,79,126};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
        cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

void problem2(){
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt", ios::in);
    char *ch2 = new char[10*17];
    char *ch2p = ch2;
    int i=0;
    while (infile.get(ch2[i])) {cout<<ch2[i];ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc = rc.sortArray(ch2p, 10, 17, column, ascending);
    for (int i=0;i<10;i++) {
        for (int j=0; j<17;j++) {
            cout<<zc[i*17+j];
        }
    }
    delete []zc;
    cout<<endl;

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
    cout<<"Now Entering problem 4\n";
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.TotalRecursive((float)(0.10),7)
            <<" Recursive Calculation "<<endl;
}
void problem5(){
    cout<<"Problem 5 "<<endl;
    cout<<"Employee information\n"<<endl;
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
            Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(60));
    Mary.toString();
}
void problem6(){
    cout<<"Problem 6\n";
    cout<<"3.75"<<endl;
    cout<<"Base 2: 0011.1100"<<endl;
    cout<<"Octal: 3.6"<<endl;
    cout<<"Hex: 3.C"<<endl;
    cout<<"Float Representation: 78000002 "<<endl;
    cout<<"IEEE 754 : 40700000"<<endl;
    cout<<"power=1, power goes in the beginning after the signed/unsigned bit\n";
    cout<<"\n.7"<<endl;
    cout<<"Base 2: .10110011001 (repeating 0011)"<<endl;
    cout<<"Octal: .5463146 (repeating 3146)"<<endl;
    cout<<"Hex: .B333 (repeating 3)"<<endl;
    cout<<"Float representation: 59999900 "<<endl;
    cout<<"IEEE 754: 3F333333"<<endl;
    cout<<"power= -1, power goes in the beginning after the signed/unsigned bit\n";
    cout<<"\n89.9"<<endl;
    cout<<"Base 2: 1011001.111001"<<endl;
    cout<<"Octal: 131.71463"<<endl;
    cout<<"Hex: 59.E666 (repeating 6)"<<endl;
    cout<<"Float representation: 5BCCCC07"<<endl;
    cout<<"IEEE 754: 42B3CCCD"<<endl;
    cout<<"power=6, power goes in the beginning after the signed/unsigned bit\n";
}
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}