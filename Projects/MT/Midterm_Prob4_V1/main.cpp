/*midterm Problem 4_V1
 not outputting what the encrypted values are 
 not sure why*/

//System Libraries
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main(int argc, char** argv){
    unsigned char  n1000s,n100s,n10s,n1s;//Number of 10^x's
    int digits;  
    cout<<"Enter the digits to be encrypted."<<endl;
    cin>>digits;//fix to validate the length of four
    //Calculate the number of 1000's,100's,10's,1's
        n1000s=(digits-digits%1000)/1000;//Number of 1000's
        digits=(digits-n1000s*1000);     //Subtract off 1000's
        n100s =(digits-digits%100)/100;  //Number of 100's
        digits=(digits-n100s*100);       //Subtract off 100's
        n10s  =(digits-digits%10)/10;    //Number of 10's
        n1s   =(digits-n10s*10);         //Subtract off 10's to get 1's

        //Output the number and it's components
        cout<<"The number of 1000's  = "<<static_cast<int>(n1000s)<<endl;
        cout<<"The number of 100's   = "<<static_cast<int>(n100s)<<endl;
        cout<<"The number of 10's    = "<<static_cast<int>(n10s)<<endl;
        cout<<"The number of 1's     = "<<static_cast<int>(n1s)<<endl;

        if(n1000s==9||n1000s==8){
            cout<<"No digit can be an 8, or 9"<<endl;
            cout<<"Enter a new digit."<<endl;
            cin>>digits;
        }
        if(n100s==9||n100s==8){
            cout<<"No digit can be an 8, or 9"<<endl;
            cout<<"Enter a new digit."<<endl;
            cin>>digits;
        }
        if(n10s==9||n10s==8){
            cout<<"No digit can be an 8, or 9"<<endl;
            cout<<"Enter a new digit."<<endl;
            cin>>digits;
        }
        if(n1s==9||n1s==8){
            cout<<"No digit can be an 8, or 9"<<endl;
            cout<<"Enter a new digit."<<endl;
            cin>>digits;
        } 
    
        //calculation-change digit values
        n1000s=(n1000s+5)%8;
        n100s=(n100s+5)%8;
        n10s=(n10s+5)%8;
        n1s=(n1s+5)%8;
        cout<<"Original"<<endl<<n1000s<<n100s<<n10s<<n1s<<endl;
        cout<<"Encrypted"<<endl<<n100s<<n1000s<<n1s<<n10s<<endl;
    return 0;
}

