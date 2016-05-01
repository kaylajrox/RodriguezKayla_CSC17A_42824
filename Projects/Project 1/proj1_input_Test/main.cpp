//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream> //File I/O
#include <iomanip> //Formatting
#include <vector>
using namespace std;
 
//User Libraries
struct UserColor{
    string color;
    int spot;
};
//function prototypes
void input(UserColor[],string*,const int,string[]);

int main(int argc, char** argv) {
    const int SIZE=4;
    UserColor clrPick[SIZE];  //User Inputs
    string order[SIZE]={"first","second","third","fourth"}; //User Order Inputs
    string options[8]={"Red","Green","Blue","Brown","Black","Yellow","Orange","White"};
    
    input(clrPick,order,SIZE,options);
    for(int i=0;i<SIZE;i++){
        cout<<clrPick[i].color<<" ";
    }
    return 0;
}
   

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Input colors Function                                */
/******************************************************************************/
void input(UserColor clrPick[],string *order,const int SIZE,string options[]){
    for (int i=0;i<SIZE;i++){
        //i want to have a validation here to make sure its of the colors in list
        //also I want to make sure any form of capitial/lowercase is acceptable
        cout<<"Pick your "<<*(order+i)<<" color"<<endl;      
        getline(cin,clrPick[i].color);
    }   
}