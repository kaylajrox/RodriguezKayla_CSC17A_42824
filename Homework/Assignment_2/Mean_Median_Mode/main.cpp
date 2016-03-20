/* 
 * Author: Kayla Rodriguez
 * Created on March 9, 2016, 1:09 PM
 * Mean Median and Mode Calculation on a randomly generated set
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
int *freqF(int*,int,int);
float median(int*,int);
float mean(int*,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare and allocate the array
    int size=50;//size of array
    int mod=10; //Used to find the range of numbers in array
    int *array=fillMod(size,mod);
    //Creating frequency array
    int *freq=freqF(array,mod,size);
    //Find the max Frequency
    int max=findMax(freq,mod);
    //Find the number of modes
    int nModes=numMode(freq,mod,max);
    //Find the modes
    int *modes=mode(freq,mod,max,nModes);
    //Display the random array
    cout<<"The Original Array"<<endl;
    prntAry(array,size,10);
    //Sort the Random Array
    markSrt(array,size);
    //Display the Sorted array
    cout<<"The Sorted Random Array"<<endl;
    prntAry(array,size,10);
    //Display Max frequency and Number of modes
    cout<<"Max frequency: "<<max<<" "<<endl;
    cout<<"Number of Modes: "<<nModes<<endl;
    if (nModes>1){
        cout<<"The modes are: ";
    }else 
        cout<<"The mode is ";
    //Print Mode
    prntAry(modes,nModes,10);
    //Display Median
    cout<<"The median is ";
    float medianF=median(array,size);
    //Display Mean
    cout<<"\nThe mean of this set is ";
    float meanF=mean(array,size);
    cout<<meanF;
   
    //Deallocate Memory
    delete []array;
    delete []freq;
    delete []modes;
    //Exit stage right
    return 0;
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
//                                Fill Mod
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
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                              Frequency Array Creation
////////////////////////////////////////////////////////////////////////////////
int *freqF(int *array,int mod,int size){
    int *freq=new int[mod];
    for (int i=0;i<mod;i++){
        freq[i]=0;
    }//loop from 0 to size
    for (int i=0;i<size;i++){
        freq[array[i]]++;
    }
    return freq;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                              Median Calculation
//Inputs: n--> size
//
//Outputs: median position
////////////////////////////////////////////////////////////////////////////////
float median(int *array,int n){
    float median;
    if (n%2==0){
        cout<<array[n/2];
    }else
        cout<<array[(n/2)-1];
    return median;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                              Median Calculation
////////////////////////////////////////////////////////////////////////////////
float mean(int *array,int n){
    float sum=0,mean;
    for(int i=0;i<n;i++){
        sum+=*(array+i);
    }
    mean=sum/n;
    return mean;
}