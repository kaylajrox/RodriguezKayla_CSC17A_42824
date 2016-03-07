/*
    File:   main.cpp
    Author: Kayla Rodriguez
    Created on February 3, 2016, 8:35 PM
    Purpose:  Menu
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned short nSoltn;//Problem Solution to display
    bool reDsply=true;    //Exit program when false

    //Menu to Display Solution
    do{
        //Input problem to display, i.e. Menu
        cout<<"\nAssignment 2 Problem Set"<<endl;
        cout<<"Type 1 to Display Gaddis_8thEd_Chap9_Prob2"<<endl;
        cout<<"Type 2 to Display Gaddis_8thEd_Chap9_Prob6"<<endl;
        cout<<"Type 3 to Display Gaddis_8thEd_Chap9_Prob7"<<endl;       
        cout<<"Type anything else to exit "<<endl<<endl;
        cin>>nSoltn;
        //Solutions to all the problems
        switch(nSoltn){
            case 1:{problem1();break;}
            case 2:{problem2();break;}
            case 3:{problem3();break;}
            case 4:{problem4();break;}
            case 5:{problem5();break;}
            case 6:{problem6();break;}
            case 7:{problem7();break;}
            case 8:{problem8();break;}
            case 9:{problem8();break;}
            case 10:{problem8();break;}
            default:{
                cout<<"Exiting the Program"<<endl;
                reDsply=false;
            }
        }
    }while(reDsply);

    //Exit stage right
    return 0;
}
/******************************************************************************/
/************************** Problem 1 *****************************************/
/******************************************************************************/
void problem1(){
    cout<<endl<<"Solution to Gaddis_8thEd_Chap9_Prob2"<<endl;
    cout<<endl<<"Test Scores #1"<<endl<<endl;
    
}
/******************************************************************************/
/************************** Problem 2 *****************************************/
/******************************************************************************/
void problem2(){
    //The problem to solve
    cout<<endl<<"Solution to Gaddis_8thEd_Chap9_Prob6"<<endl;
    cout<<endl<<"Case Study Modification #1"<<endl<<endl;
   
}
/******************************************************************************/
/************************** Problem 3 *****************************************/
/******************************************************************************/
void problem3(){
    //The problem to solve
    cout<<endl<<"Solution to Gaddis_8thEd_Chap9_Prob7"<<endl;
    cout<<endl<<"Case Study Modification #2"<<endl<<endl;
   
}/******************************************************************************/
/************************** Problem 4 *****************************************/
/******************************************************************************/
void problem4(){
   cout<<endl<<""<<endl;
   cout<<endl<<""<<endl<<endl;
   
}
/******************************************************************************/
/************************** Problem 5 *****************************************/
/******************************************************************************/
void problem5(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;
  
}
/******************************************************************************/
/************************** Problem 6 *****************************************/
/******************************************************************************/
void problem6(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;
    
}

/******************************************************************************/
/************************** Problem 7 *****************************************/
/******************************************************************************/
void problem7(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;
    
}

/******************************************************************************/
/**************************  Problem 8  ***************************************/
/******************************************************************************/
void problem8(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;
}
/******************************************************************************/
/**************************  Problem 9  ***************************************/
/******************************************************************************/
void problem9(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;
}
/******************************************************************************/
/**************************  Problem 10 ***************************************/
/******************************************************************************/
void problem10(){
    cout<<endl<<""<<endl;
    cout<<endl<<""<<endl<<endl;
}