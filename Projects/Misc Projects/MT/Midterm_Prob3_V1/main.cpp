/*midterm Problem 3_V1*/

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};
//Global Constants

//Function Prototypes
int *fillAry(int);
void fillMod(int,int*);
void prntAry(int *,int);
void markSrt(int *,int);
int *mode(int *,int,int,int);
int findMax (int*,int);
void prntMod(int *,int);
int numMode(int *,int,int);
int *freqF(int*,int,int);
float med(int*,int);
float mean(int*,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and allocate the array
    statsResult data;
    int size=4;//size of array
    int mod=10; //Used to find the range of numbers in array
    int array[size];
    fillMod(size,array);
    //Creating frequency array
    int *freq=freqF(array,mod,size);
    //Find the max Frequency
    data.maxFreq=findMax(freq,mod);
    //Find the number of modes
    data.nModes=numMode(freq,mod,data.maxFreq);
    //Find the modes
    data.mode=mode(freq,mod,data.maxFreq,data.nModes);
    //Display the random array
    cout<<"The Original Array"<<endl;
    prntAry(array,size);
    //Sort the Random Array
    markSrt(array,size);
    //Display the Sorted array
    cout<<"\nThe Sorted Random Array"<<endl;
    prntAry(array,size);
    //Display Max frequency and Number of modes
    cout<<"\nMax frequency: "<<data.maxFreq<<" "<<endl;
    cout<<"Number of Modes: "<<data.nModes<<endl;
    if (data.nModes>1){
        cout<<"The modes are: ";
    }else 
        cout<<"The mode is ";
    //Print Mode
    prntAry(data.mode,data.nModes);
    //Display Median
    cout<<"The median is ";
    data.median=med(array,size);
    //Display Mean
    cout<<"\nThe mean of this set is ";
    data.avg=mean(array,size);
    cout<<data.avg;
   
    //Deallocate Memory
//    delete []array;
//    delete []freq;
//    delete []modes;
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
void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                Fill Mod
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with 2 digit integers
////////////////////////////////////////////////////////////////////////////////
void fillMod(int n,int *a){
    cout<<"fill the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>*(a+i);
    }
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
float med(int *array,int n){
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