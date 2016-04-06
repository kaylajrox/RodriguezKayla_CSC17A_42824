/*midterm Problem 1_V3
 works....for now
 */

//System Libraries
#include <bits/stdc++.h>
using namespace std;

//User Libraries
struct Cstmr{
    string name;//customer name
    string address;//address
    string accNum; //account number
    float balB;//balance at the beginning of the month
    int checks;//number of checks
    float ckAmt[]; //check amounts
    int depos;//number of deposits
    float depsAmt[];//deposit amounts
};
//Function Prototypes
void input(Cstmr*);
float chkCalc(Cstmr*);
float depCalc(Cstmr*);
//Execution Begins Here
int main(int argc, char** argv){
    //Declare Variables
    Cstmr *cInfo;//all customer information
    int size=0; //how many customers
    //Dynamic Allocation
    cout<<"How many customers are there? "<<endl;
    cin>>size;
    cInfo= new Cstmr[size];
    for(int i=0;i<size;i++){
        //Input Customer Information
        input(cInfo);
        //Calculate Total Check Amounts
        float checkTot=chkCalc(cInfo); //total money spent in checks
        //Calculate Total Deposits
        float deposTot=depCalc(cInfo); //total money spent in checks
        //Calculate New Balance
        float newBal=cInfo->balB-checkTot+deposTot;
        cout<<"Your New balance is $"<<newBal<<endl;
        if(newBal<0){
            cout<<"You have overdrawn. You will be charged and extra $15."<<endl;
            cout<<"Your new balance including this fee is "<<(newBal-15)<<endl;
        }    
    }
    //free memory
    delete[] cInfo;
    
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                         Input information                                  */
/******************************************************************************/
void input(Cstmr *cInfo){ 
    cout<<"Please enter your name"<<endl;
    cin.ignore();
    getline(cin,cInfo->name);
    cout<<"Enter your address"<<endl;
    getline(cin,cInfo->address);
    do{
    cout<<"Enter your account number "<<endl;
    cin>>cInfo->accNum;
        if(cInfo->accNum.length()!=5){
            cout<<"Your account number needs to be five digits"<<endl;
        }
    }while(cInfo->accNum.length()!=5);
    cout<<"Enter your balance at the beginning of the month "<<endl;
    cin>>cInfo->balB;
    cout<<"Enter the number of checks you wrote this month"<<endl;
    cin>>cInfo->checks;
    cout<<"Enter these amounts here and press enter "<<endl;
    for(int i=0;i<cInfo->checks;i++)
        cin>>cInfo->ckAmt[i];
    cout<<"Enter the number of deposits you made this month "<<endl;
    cin>>cInfo->depos;
    cout<<"Enter these amounts here and press enter after each"<<endl;
    for(int i=0;i<cInfo->depos;i++)
        cin>>cInfo->depsAmt[i];
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                         Calculation of total check amount                  */
/******************************************************************************/
float chkCalc(Cstmr *cInfo){
    float sum=0;
    for(int i=0;i<cInfo->checks;i++)
        sum+=cInfo->ckAmt[i]; //Sum all the checks
    return sum;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                         Calculation of totals                              */
/******************************************************************************/
float depCalc(Cstmr *cInfo){
    float sum=0;
    for(int i=0;i<cInfo->depos;i++)
        sum+=cInfo->depsAmt[i]; //Sum all the checks
    return sum;
}