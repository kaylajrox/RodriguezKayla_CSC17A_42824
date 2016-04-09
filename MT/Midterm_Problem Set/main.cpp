/*midterm problem set*/

//Library includes Here
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

//Global Constants 

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
struct empInfo{
    string name;//customer name
    string address;//address
    int hours;//hours worked
    float rate;//rate of pay
};
struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};
//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2(bool);
void problem3();
void problem4();
void problem5();
void problem6();
void input(Cstmr*);
float chkCalc(Cstmr*);
float depCalc(Cstmr*);
bool empInput(empInfo *,int,bool);
float calcPay(empInfo *,float &);
string amtToStr(int);
void decrypt(char *,int,unsigned char,unsigned char,unsigned char,unsigned char);
void encrypt(char *,int,unsigned char,unsigned char,unsigned char,unsigned char);
void prntAry(int *,int);
void markSrt(int *,int);
statsResult printStat(int*,int,statsResult*);
statsResult *avgMedMode(int*,int);
void isvalid();
bool empIn(empInfo *,int size,bool);
//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    bool reDsply=true;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2(reDsply);break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   {def(inN);
                    reDsply=false;}
        }
    }while(reDsply);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
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
    cout<<"In problem # 1"<<endl<<endl;
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
        float newBal=(cInfo->balB)-checkTot+deposTot;
        cout<<"Your New balance is $"<<newBal<<endl;
        if(newBal<0){
            cout<<"You have overdrawn. You will be charged and extra $15."<<endl;
            cout<<"Your new balance including this fee is "<<(newBal-15)<<endl;
        }    
    }
    //free memory
    delete[] cInfo;    
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
void problem2(bool reDsply){
    cout<<"In problem # 2"<<endl<<endl;
    //Declare Variables
    empInfo *emplys;//all customers
    int size=0; //how many customers
    float totPayG; //total gross pay
    string company;
    bool isvalid=true;
    //Dynamic Allocation
    cout<<"How many employees are there? "<<endl;
    cin>>size;
    emplys= new empInfo[size];
    cout<<"What is the company name?"<<endl;
    cin>>company;
    cout<<"If you enter a negative number for hours or pay rate then the"<<endl;
    cout<<"program will end."<<endl;
    cout<<"\nEnter information for each employee"<<endl;
    
    for(int i=0;i<size;i++){
        //Input
        bool valid=empInput(emplys,size,isvalid);
        if(valid==false)
            return;
        bool valid2=empIn(emplys,size,isvalid);
        if(valid2==false)
            return;
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
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Employee Input Function                             */
/******************************************************************************/
bool empInput(empInfo *emplys,int size,bool isvalid){
    cout<<"Input employee name"<<endl;
    cin.ignore();
    getline(cin,emplys->name);
    cout<<"Input address"<<endl;
    getline(cin,emplys->address);
    cout<<"Input employee hours"<<endl;
    cin>>(emplys->hours);
    //flag the incorrect hours number
    if(emplys->hours<0){
        cout<<"You cannot have negative hours"<<endl;
        cout<<"Exiting the program."<<endl;
        isvalid=false;
    }else
        isvalid=true;
    return isvalid;
 }
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                   Employee Input Function COntinued                            */
/******************************************************************************/
bool empIn(empInfo *emplys,int size,bool isvalid){
   cout<<"Input employee rate of pay"<<endl;
    cin>>emplys->rate;
    if(emplys->rate<0){
        cout<<"You cannot have a negative rate of pay"<<endl;
        cout<<"Exiting the program."<<endl;
        isvalid=false;
    }else
        isvalid=true;
    return isvalid; 
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
void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    //Declare and allocate the array
    statsResult *data;
    int *numbers;
    int sizeIn=0; 
    //int *array;
    //Dynamic allocation and fill the array Input
    cout<<"fill the array"<<endl;
    cout<<"Enter the size of the array"<<endl;
    cin>>sizeIn;
    numbers=new int[sizeIn];
    cout<<"Input the numbers to put in the array"<<endl;
    for(int i=0;i<sizeIn;i++){
        cin>>numbers[i];
    }
    //sort the array of numbers
    markSrt(numbers, sizeIn);
    //Average Median and mode function -->Does Calculations
    data = avgMedMode(numbers,sizeIn);
    //print and display the results
    printStat(numbers,sizeIn,data);
    //free memory
    delete[] numbers;
    delete[] data;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Sort the Array
//Inputs
//     n->Size of the array
//     a->Array
//Output
//     a->The sorted array
////////////////////////////////////////////////////////////////////////////////
void markSrt(int *a,int n){
    for(int pos=0;pos<n-1;pos++){
        for(int row=pos+1;row<n;row++){
            if(*(a+pos)>*(a+row)){
                *(a+pos)=*(a+pos)^*(a+row);
                a[row]=a[pos]^a[row];
                *(a+pos)=*(a+pos)^*(a+row);
            }
        }
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Print Array
//Inputs
//     n->Size of the array
//     a->Array
////////////////////////////////////////////////////////////////////////////////
void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Print Statistics on the Array
////////////////////////////////////////////////////////////////////////////////
 statsResult printStat(int *array,int size,statsResult *data) {
    //Display Max frequency and Number of modes
    cout<<"\nMax frequency: "<<data->maxFreq<<" "<<endl;
    cout<<"Number of Modes: "<<data->nModes<<endl;
    if (data->nModes>1){
        cout<<"The modes are: ";
    }else 
        cout<<"The mode is ";
    //Print Mode
    prntAry(data->mode,data->nModes);
    //Display Median
    cout<<"The median is ";
    cout<<data->median;
    //Display Mean
    cout<<"\nThe mean of this set is ";
    cout<<data->avg;
    //free memory
    delete []array;    
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Median/Mean/Mode Calculation
////////////////////////////////////////////////////////////////////////////////
statsResult *avgMedMode(int *a,int size){
    statsResult *aMedMde = new statsResult;
    //freqF function
    int *freq=new int[size];
    for (int i=0;i<size;i++){
        freq[i]=0;
    }//loop from 0 to size
    for (int i=0;i<size;i++){
        freq[a[i]]++;
    }
    //find max function
    //find the max frequency
    int max=0;
    for (int i=0;i<size;i++){
        if (freq[i]>max)
            max=freq[i];
    }
    aMedMde->maxFreq=max;
    //num mode function
     //Find the number of modes
    aMedMde->nModes=0;
    for (int i=0;i<size;i++){
        if (freq[i]== aMedMde->maxFreq)
            aMedMde->nModes++;
    }
    //Find the modes
    //mode function
    //Declare and allocate memory
    int *modeAry=new int[aMedMde->nModes];
    int index=0;
    for (int i=0;i<size;i++){
        if (freq[i]==aMedMde->maxFreq){
            modeAry[index]=i;
            index++;
        }
    }
    modeAry=aMedMde->mode;
    //mean function
    //calculate mean
    float sum=0;
    for(int i=0;i<size;i++){
        sum+=*(a+i);
    }
    aMedMde->avg=sum/size;
    //median function
    //calculate median
    markSrt(a,size);
    if (size%2==0){
        aMedMde->median=a[size/2];
    }else
        aMedMde->median=a[(size/2)-1];
    //free memory
    delete []freq;
    return aMedMde;
}
void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    //declare variables
    unsigned char  n1000s,n100s,n10s,n1s;//Number of 10^x's
    char *digits;
    int size=10;
    bool reDsply4=true;    //Exit program when false
    digits = new char[size];
    char nSoltn;//Problem Solution to display
    do{
        //Input problem to display, i.e. Menu
        cout<<"Encryption and Decryption"<<endl;
        cout<<"Type 1 to decrypt a number"<<endl;
        cout<<"Type 2 to encrypt a number"<<endl;
        cout<<"Type anything else to exit "<<endl<<endl;
        cin>>nSoltn;
        //Solutions to all the problems
        switch(nSoltn){
            case 49:{decrypt(digits,size,n1000s,n100s,n10s,n1s);break;}
            case 50:{encrypt(digits,size,n1000s,n100s,n10s,n1s);break;}
            default:{
                cout<<"Exiting the Program"<<endl;
                reDsply4=false;
            }
        }
    }while(reDsply4);
    //free memory
    delete[] digits;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Decryption Function                            */
/******************************************************************************/
void encrypt(char *digits,int size,unsigned char n1000s,unsigned char n100s,
        unsigned char n10s,unsigned char n1s){
    do{ 
        do{
            cout<<"Enter the digits to be encrypted."<<endl;
            cin>>digits;//fix to validate the length of four
            if(strlen(digits)!=4)
                cout<<"Must enter four digits."<<endl;
        }while(strlen(digits)!=4);
        int number=atoi(digits);
        //Calculate the number of 1000's,100's,10's,1's
        n1000s=(number-(number%1000))/1000;//Number of 1000's
        number=(number-n1000s*1000);     //Subtract off 1000's
        n100s =(number-(number%100))/100;  //Number of 100's
        number=(number-n100s*100);       //Subtract off 100's
        n10s  =(number-(number%10))/10;    //Number of 10's
        n1s   =(number-n10s*10);         //Subtract off 10's to get 1's
        if(n1000s==9||n1000s==8||n100s==9||n100s==8||n10s==9||n10s==8||n1s==9
                ||n1s==8){
            cout<<"No digit can be an 8 or 9"<<endl;
            cout<<"Enter a new digit."<<endl;
        }
    }while(n1000s==9||n1000s==8||n100s==9||n100s==8||n10s==9||n10s==8||n1s==9||
            n1s==8);
    
    //calculation-change digit values
    n1000s=(n1000s+5)%8;
    n100s=(n100s+5)%8;
    n10s=(n10s+5)%8;
    n1s=(n1s+5)%8; 
    //Switch place holders 1 and 2 and 3 and 4
    cout<<"Encrypted"<<endl<<static_cast<int>(n100s)<<static_cast<int>(n1000s);
    cout<<static_cast<int>(n1s)<<static_cast<int>(n10s)<<endl;  
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                              Encryption Function                           */
/******************************************************************************/
void decrypt(char *digits,int size,unsigned char n1000s,unsigned char n100s,
        unsigned char n10s,unsigned char n1s){
    do{
        cout<<"Enter the digits to be decrypted."<<endl;
        cin>>digits;//fix to validate the length of four
        if(strlen(digits)!=4)
            cout<<"Must enter four digits."<<endl;
    }while(strlen(digits)!=4);
    int number=atoi(digits);
    //Calculate the number of 1000's,100's,10's,1's
    n1000s=(number-(number%1000))/1000;//Number of 1000's
    number=(number-n1000s*1000);     //Subtract off 1000's
    n100s =(number-(number%100))/100;  //Number of 100's
    number=(number-n100s*100);       //Subtract off 100's
    n10s  =(number-(number%10))/10;    //Number of 10's
    n1s   =(number-n10s*10);         //Subtract off 10's to get 1's
              
    //calculation-change digit values
    n1000s=(n1000s+3)%8;
    n100s=(n100s+3)%8;
    n10s=(n10s+3)%8;
    n1s=(n1s+3)%8;
    //Switch place holders 1 and 2 and 3 and 4
    cout<<"Decrypted"<<endl<<static_cast<int>(n100s)<<static_cast<int>(n1000s);
    cout<<static_cast<int>(n1s)<<static_cast<int>(n10s)<<endl;  
}
void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    cout<<"Part a "<<endl;   
    cout<<"2.125 converted to binary is 000 10.0010"<<endl;
    cout<<"in octal is 2.1"<<endl;
    cout<<"in base hex 2.2"<<endl; 
    cout<<"0.1328125 in binary is .0010010"<<endl;-
    cout<<"in octal is .104"<<endl;
    cout<<"in hex .22"<<endl;
    cout<<"Part b "<<endl;
    cout<<"Part c "<<endl;
    cout<<"46666601 converted to decimal representation is 46.6666"<<endl;
    cout<<"46666602 converted to decimal representation is 4.66666"<<endl;
    cout<<"B9999AFE converted to decimal representation is -.2333330"<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}