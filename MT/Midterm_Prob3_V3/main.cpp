/*midterm Problem 3_V3
 */

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
int *fillMod(int,int*);
void prntAry(int *,int);
void markSrt(int *,int);
int *mode(int *,int,int,int);
int findMax (int*,int);
void prntMod(int *,int);
int numMode(int *,int,int);
int *freqF(int*,int,int);
float med(int*,int);
float mean(int*,int);
statsResult printStat(int*,int,statsResult*);
statsResult *avgMedMode(int*,int);

//Execution Begins Here
int main(int argc, char** argv) {
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