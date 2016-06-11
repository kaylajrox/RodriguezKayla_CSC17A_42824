/* 
 * File:   SavingsAccount.cpp
 * Implementation File
 */

#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(float x){
    if(x>0){
        Balance=x;
       
    }else{
        cout<<"WithDraw not Allowed\n";
        Balance=0;
    }
    int   FreqWithDraw=0;                 
    int   FreqDeposit=0;
}             
void  SavingsAccount::Transaction(float a){
    if(a>0){
        Balance+=a;
        FreqDeposit++;
    }else if (a<0){
        if(a<(-Balance)){
            cout<"WithDraw not Allowed\n";
        }else{
            Balance+=a;
            FreqWithDraw++;
        }
    }
        
}        
float SavingsAccount::Total(float savint,int time){
    float ttl=Balance;
    for(int i=0;i<time;i++){
        ttl=ttl*(1+savint);
    }
    return ttl;
}	 
float SavingsAccount::TotalRecursive(float savint,int time){
    float total=Balance;
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