/*midterm Problem 2_V3
 had me input 4 names and only outptted 2 checks when the size was two*/

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
string amtToStr(int);
//Execution Begins Here
int main(int argc, char** argv){
    //Declare Variables
    empInfo *emplys;//all customers
    int size=0; //how many customers
    float totPayG; //total gross pay
    string company;
    //Dynamic Allocation
    cout<<"How many employees are there? "<<endl;
    cin>>size;
    emplys= new empInfo[size];
    cout<<"What is the company name?"<<endl;
    cin>>company;
    cout<<"Enter information for each employee"<<endl;
    for(int i=0;i<size;i++){
        //Input
        empInput(emplys,size);
        //calculate pay
        float grsPay=calcPay(emplys,totPayG);
        //Output Paycheck
        cout<<"******************************************************"<<endl;
        cout<<"Paycheck"<<endl<<company<<endl<<emplys->address<<endl;
        cout<<"Name: "<<emplys->name<<"\t"<<" Amount: "<<grsPay<<endl;
        int dollars=floor(grsPay);
        float cents=(grsPay-dollars)*100;
        if(cents==0){
            string temp=amtToStr(dollars)+"dollars ";
            cout<<temp<<endl;
        }
        else{
            string temp=amtToStr(dollars)+"dollars "+amtToStr(cents)+"cents";
            cout<<temp<<endl;
        }
        cout<<"Signature:\n"<<emplys->name<<endl;
        cout<<"******************************************************"<<endl;
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
string amtToStr(int dollars){
    int n10000s,n1000s,n100s,n10s,n1s;//Number of 10^x's
    unsigned int amount=dollars;                //amount transacted
    //Calculate the number of 1000's,100's,10's,1's
    n1000s=dollars/1000;//Number of 1000's
    amount=(amount-n1000s*1000);     //Subtract off 1000's
    n100s =amount/100;  //Number of 100's
    amount=(amount-n100s*100);       //Subtract off 100's
    n10s  =amount/10;    //Number of 10's
    amount=(amount-n10s*10);
    n1s=amount;
    string result="";
    
    switch(n1000s){
        case 9:  result+="Nine Thousand";break; 
        case 8:  result+="Eight Thousand ";break;
        case 7:  result+="Seven Thousand ";break;
        case 6:  result+="Six Thousand ";break;
        case 5:  result+="Five Thousand ";break;
        case 4:  result+="Four Thousand ";break;
        case 3:  result+="Three Thousand ";break;
        case 2:  result+="Two Thousand ";break;
        case 1:  result+="One Thousand ";break;
    }
    //Output the 100's
    switch(n100s){
        case 9:  result+="Nine Hundred ";break; 
        case 8:  result+="Eight Hundred ";break;
        case 7:  result+="Seven Hundred ";break;
        case 6:  result+="Six Hundred ";break;
        case 5:  result+="Five Hundred ";break;
        case 4:  result+="Four Hundred ";break;
        case 3:  result+="Three Hundred ";break;
        case 2:  result+="Two Hundred ";break;
        case 1:  result+="One Hundred ";break;
    }

    //Output the 10's
    switch(n10s){
        case 9:  result+="Ninety ";break;
        case 8:  result+="Eighty ";break;
        case 7:  result+="Seventy ";break;
        case 6:  result+="Sixty ";break;
        case 5:  result+="Fifty ";break;
        case 4:  result+="Forty ";break;
        case 3:  result+="Thirty ";break;
        case 2:  result+="Twenty ";break;
        case 1:  result+="Ten ";break;
    }

    //Output the 1's
    switch(n1s){
        case 9:  result+="Nine ";break;
        case 8:  result+="Eight ";break;
        case 7:  result+="Seven ";break;
        case 6:  result+="Six ";break;
        case 5:  result+="Five ";break;
        case 4:  result+="Four ";break;
        case 3:  result+="Three ";break;
        case 2:  result+="Two ";break;
        case 1:  result+="One ";break;
    }
    return result;
}
