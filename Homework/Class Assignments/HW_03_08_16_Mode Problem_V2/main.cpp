/* 
 * Author: Kayla Rodriguez
 * Created on March 9, 2016, 1:09 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *fillAry(int);
int *fillMod(int,int);
void prntAry(int *,int,int);
void markSrt(int *,int);
int *mode(int *,int,int,int);
int findMax (int*,int);
void prntMod(int *,int);
int numMode(int *,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare and allocate the array
    int size=50;
    int mod=10;
    int *array=fillMod(size,mod);
    int *freq=new int[mod];
    
    
    for (int i=0;i<mod;i++){
        freq[i]=0;
    }//loop from 0 to size
    for (int i=0;i<size;i++){
        freq[array[i]]++;
    }

    //Find the max Frequency
    int max=findMax(freq,mod);
    //Find the number of modes
    int nModes=numMode(freq,mod,max);
    //
    int *modes=mode(freq,mod,max,nModes);
    //Display the random array
    prntAry(array,size,10);
    //Print Array
    prntAry(freq,mod,10);
    cout<<"Max frequency: "<<max<<" "<<endl;
    cout<<"Number of Modes: "<<nModes<<endl;
    if (nModes>1){
    cout<<"The modes are: ";
    }else 
        cout<<"The mode is ";
    //Print Mode
    prntAry(modes,nModes,10);
    
    
    //Deallocate Memory
    delete []array;
    delete []freq;
    delete []modes;
    //Exit stage right
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Print Array
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
//     perLine->Number of integers to display per row
////////////////////////////////////////////////////////////////////////////////
void prntAry(int *a,int n,int perLine){
    //Output the Array
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                Fill Array
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with 2 digit integers
////////////////////////////////////////////////////////////////////////////////
int *fillMod(int size,int mod){
    //Declare and allocate memory
    int *a=new int[size];
    //Loop and fill with 2 digit numbers
    for(int i=0;i<size;i++){
        *(a+i)=rand()%mod;
    }
    //return the pointer
    return a;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                Print Mode
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with 2 digit integers
////////////////////////////////////////////////////////////////////////////////
int *mode(int *freq,int size,int max,int nModes){
    //Declare and allocate memory
    int *a=new int[nModes];
    int index=0;
    for (int i=0;i<size;i++){
        if (freq[i]==max){
            a[index]=i;
            index++;
        }
    }
    //return the pointer
    return a;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                              Find Max Frequency
////////////////////////////////////////////////////////////////////////////////
int findMax (int *a,int size){
    int max=0;
    for (int i=0;i<size;i++){
        if (a[i]>max)
            max=a[i];
    }
    return max;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                              Number of Modes
////////////////////////////////////////////////////////////////////////////////
int numMode(int *a,int size,int max){
    int counter=0;
    for (int i=0;i<size;i++){
        if (a[i]==max)
            counter++;
    }
    return counter;
}