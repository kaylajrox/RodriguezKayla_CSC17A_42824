/*midterm Problem 2_V1*/

//System Libraries
#include <bits/stdc++.h>
using namespace std;

//User Libraries
struct empInfo{
    string name;//customer name
    string address;//address
    int hours;//hours worked
    float rate;//rate of pay
};
//Function Prototypes
void empInput(empInfo *,int);
float calcPay(empInfo *,float &);
void amtToStr();
//Execution Begins Here
int main(int argc, char** argv){
    //Declare Variables
    empInfo *emplys;//all customers
    int size=0; //how many customers
    float totPayG; //total gross pay
    //Dynamic Allocation
    cout<<"How many employees are there? "<<endl;
    cin>>size;
    emplys= new empInfo[size];
    cout<<"Enter information for each employee"<<endl;
    for(int i=0;i<size;i++){
        //Input
        empInput(emplys,size);
        //calculate pay
    float grsPay=calcPay(emplys,totPayG);
    //Output Paycheck
    cout<<"Paycheck"<<endl<<"Company\n"<<emplys->address<<endl;
    cout<<"Name: "<<emplys->name<<setw(2)<<"Amount: "<<totPayG<<endl;
    amtToStr();
    cout<<"Signature:"<<endl; 
    }
    //free memory
    delete[] emplys;
    
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Employee Input Function                             */
/******************************************************************************/
void empInput(empInfo *emplys,int size){
        for (int i=0;i<size;i++){
        cout<<"Input employee name"<<endl;
        cin.ignore();
        getline(cin,emplys->name);
        cout<<"Input address"<<endl;
        getline(cin,emplys->address);
        do{
            cout<<"Input employee hours"<<endl;
            cin>>(emplys->hours);
            if(emplys->hours<0)
                cout<<"You cannot have negative hours"<<endl;
        }while(emplys->hours<0);
        do{
            cout<<"Input employee rate of pay"<<endl;
            cin>>emplys->rate;
            if(emplys->rate<0)
                cout<<"You cannot have a negative rate of pay"<<endl;
        }while(emplys->rate<0);
    }
    for(int i=0;i<size;i++){
        cout<<emplys->name;
        cout<<(emplys->hours);
        cout<<emplys->rate;
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                              Calculation                                   */
/******************************************************************************/
float calcPay(empInfo *emplys,float &totPayG){ 
    if (emplys->hours<=40){
        totPayG=(emplys->hours)*(emplys->rate);//Calculation
        //Output
        cout<<"Your Gross pay is "<<"$"<<totPayG<<endl;
    }else if (emplys->hours>40&&emplys->hours<50){
        //Calculation
        totPayG=40*emplys->rate+(emplys->rate*2.0f)*(emplys->hours-40); 
        //Output
        cout<<"Your Gross pay is "<<"$"<<totPayG<<endl;
    }else{
        //Calculation
        totPayG=40*emplys->rate+(emplys->rate*2.0f)*50+(emplys->rate*3.0f)*
                (emplys->hours-50);
        //Output
        cout<<"Your Gross pay is "<<"$"<<totPayG<<endl;
    }
    return totPayG;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                    Convert Numerical Amounts to Strings                    */
/******************************************************************************/
//Amount Conversion
void amtToStr(){
    unsigned char n1000s,n100s,n10s,n1s;//Number of 10^x's
     unsigned int amount;                //amount transacted
    //Calculate the number of 1000's,100's,10's,1's
    n1000s=(amount-amount%1000)/1000;//Number of 1000's
    amount=(amount-n1000s*1000);     //Subtract off 1000's
    n100s =(amount-amount%100)/100;  //Number of 100's
    amount=(amount-n100s*100);       //Subtract off 100's
    n10s  =(amount-amount%10)/10;    //Number of 10's
    n1s   =(amount-n10s*10);         //Subtract off 10's to get 1's
    
    //Output the 100's
    switch(n100s){
        case 9:  cout<<"Nine Hundred ";break; 
        case 8:  cout<<"Eight Hundred ";break;
        case 7:  cout<<"Seven Hundred ";break;
        case 6:  cout<<"Six Hundred ";break;
        case 5:  cout<<"Five Hundred ";break;
        case 4:  cout<<"Four Hundred ";break;
        case 3:  cout<<"Three Hundred ";break;
        case 2:  cout<<"Two Hundred ";break;
        case 1:  cout<<"One Hundred ";break;
    }

    //Output the 10's
    switch(n10s){
        case 9:  cout<<"Ninety ";break;
        case 8:  cout<<"Eighty ";break;
        case 7:  cout<<"Seventy ";break;
        case 6:  cout<<"Sixty ";break;
        case 5:  cout<<"Fifty ";break;
        case 4:  cout<<"Forty ";break;
        case 3:  cout<<"Thirty ";break;
        case 2:  cout<<"Twenty ";break;
        case 1:  cout<<"Ten ";break;
    }

    //Output the 1's
    switch(n1s){
        case 9:  cout<<"Nine ";break;
        case 8:  cout<<"Eight ";break;
        case 7:  cout<<"Seven ";break;
        case 6:  cout<<"Six ";break;
        case 5:  cout<<"Five ";break;
        case 4:  cout<<"Four ";break;
        case 3:  cout<<"Three ";break;
        case 2:  cout<<"Two ";break;
        case 1:  cout<<"One ";break;
    }
}