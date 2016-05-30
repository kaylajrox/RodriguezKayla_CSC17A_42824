/*midterm Problem 4_V4
 * cannot properly convert back numbers

-*/

//System Libraries
#include <bits/stdc++.h>
using namespace std;
//function prototypes
void decrypt(char *,int,unsigned char,unsigned char,unsigned char,unsigned char);
void encrypt(char *,int,unsigned char,unsigned char,unsigned char,unsigned char);
//execution
int main(int argc, char** argv){
    //declare variables
    unsigned char  n1000s,n100s,n10s,n1s;//Number of 10^x's
    char *digits;
    int size=10;
    bool reDsply=true;    //Exit program when false
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
                reDsply=false;
            }
        }
    }while(reDsply);
    //free memory
    delete[] digits;
    return 0;
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
    cout<<"Original Input"<<endl<<static_cast<int>(n1000s)<<static_cast<int>(n100s);
    cout<<static_cast<int>(n10s)<<static_cast<int>(n1s)<<endl;
    //calculation-change digit values
    n1000s=(n1000s+5)%8;
    n100s=(n100s+5)%8;
    n10s=(n10s+5)%8;
    n1s=(n1s+5)%8;
    //Switch place holders 1 and 2 and 3 and 4
    cout<<"Encrypted"<<endl<<static_cast<int>(n100s)<<static_cast<int>(n1000s);
    cout<<static_cast<int>(n1s)<<static_cast<int>(n100s)<<endl;  
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
           
    cout<<"Original"<<endl<<static_cast<int>(n1000s)<<static_cast<int>(n100s);
    cout<<static_cast<int>(n10s)<<static_cast<int>(n1s)<<endl;
    //calculation-change digit values
   
    if(n1000s<3)
    n1000s=(n1000s%8+8)-5;
    if(n100s<3)
    n100s=(n100s%8+8)-5;
    if(n10s<3)
    n10s=(n10s%8+8)-5;
    if(n1s<3)
    n1s=(n1s%8+8)-5;

    n1000s=(n1000s%8+8)-5;
    n100s=(n100s%8+8)-5;
    n10s=(n10s%8+8)-5;
    n1s=(n1s%8+8)-5;

    //Switch place holders 1 and 2 and 3 and 4
    cout<<"Decrypted"<<endl<<static_cast<int>(n100s)<<static_cast<int>(n1000s);
    cout<<static_cast<int>(n1s)<<static_cast<int>(n100s)<<endl;  
}