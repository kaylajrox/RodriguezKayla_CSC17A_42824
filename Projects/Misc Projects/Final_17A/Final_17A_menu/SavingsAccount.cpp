/* 
 * File:   SavingsAccount.cpp
 * Implementation File
 */

#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(float x){
    if(x<0){
       cout<<"WithDraw not Allowed\n";
       Balance=0;
    }else{
        Balance=x;
    }
    FreqWithDraw=0;                 
    FreqDeposit=0;
}             
void  SavingsAccount::Transaction(float a){
    if(a>0){
        Balance=a+Balance;
        Deposit(Balance);
    }else if (Balance+a>0){
        if(a<Balance){
            Balance+=Withdraw(Balance);
        }else{
            cout<<"WithDraw not allowed\n";
        }
    }
        
}    
float SavingsAccount::Withdraw(float a){
  FreqWithDraw++;
  return a;
}
float SavingsAccount::Deposit(float a){
  FreqDeposit++;
  return a;
}
float SavingsAccount::Total(float savint,int time){
    float ttl=Balance;
    for(int i=0;i<time;i++){
        ttl=ttl*(1+savint);
    }
    return ttl;
}	 
float SavingsAccount::TotalRecursive(float savint,int time){
    float total;
    Balance=total;
    float interest=0.0;
    for(int i=0;i<time;i++){
        interest=total*savint;
        total+=interest;
    }
    return total;
}
void  SavingsAccount::toString(){
    cout<<"Balance="<<Balance<<endl;
    cout<<"WithDraws="<<FreqWithDraw<<endl;
    cout<<"Deposit="<<FreqDeposit<<endl;
}  