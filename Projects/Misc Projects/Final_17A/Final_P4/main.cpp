/*Problem 4*/
//just set everything using the constructor no need to ask user
//System Libraries
#include <iostream>
using namespace std;

#include "SavingsAccount.h"

//Execution Begins Here
int main(int argc, char** argv) {
    //declare variables
    SavingsAccount accInfo; //variable to hold all the account info
    float balance;
    char transChoice;//transaction choice
    float deposit;
    
    //input account information
    cout<<"Welcome to your Savings Account!\n";
    cout<<"What is your balance?"<<endl;
    cin>>balance;
    accInfo.SavingsAccount(balance);
    do{
        cout<<"What is the transaction you would like to make? (deposit or withdraw)";
        cout<<" press d for deposit and w for withdraw"<<endl;
        cin>>transChoice;
        transChoice=tolower(transChoice);
    }while(transChoice!='d'&&transChoice!='w');
    if(transChoice=='d'){
        cout<<"What is the amount you would like to deposit into your account?\n";
        cin>>deposit;
    }
    return 0;
}

