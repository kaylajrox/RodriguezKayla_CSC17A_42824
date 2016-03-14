/* 
 * Author: Dr. Mark E. Lehr
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
int *fill2Dg(int);
int *fillIdx(int);
void markSrt(int *,int *,int);
void prntAry(int *,int,int);
void prntAry(int *,int *,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare and allocate the array
    int size=100;
    int *array=fill2Dg(size);
    int *index=fillIdx(size);
    //Display the random array
    cout<<"The original random 2 digit array"<<endl;
    prntAry(array,size,10);
    cout<<"The original indexed array"<<endl;
    prntAry(index,size,10);
    //Sort the array
    markSrt(array,index,size);
    //Display the sorted array
    cout<<"The original random 2 digit array after sorting"<<endl;
    prntAry(array,size,10);
    cout<<"The original indexed array after sorting"<<endl;
    prntAry(index,size,10);
    cout<<"The original array with sorted index"<<endl;
    prntAry(array,index,size,10);
    //Deallocate Memory
    delete []array;
    delete []index;
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
void markSrt(int *a,int *idx,int n){
    for(int pos=0;pos<n-1;pos++){
        for(int row=pos+1;row<n;row++){
            if(*(a+*(idx+pos))>*(a+*(idx+row))){
                *(idx+pos)=*(idx+pos)^*(idx+row);
                idx[row]=idx[pos]^idx[row];
                *(idx+pos)=*(idx+pos)^*(idx+row);
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
void prntAry(int *a,int *idx,int n,int perLine){
    //Output the Array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+*(idx+i))<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
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
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                        Fill Array with Index
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with 2 digit integers
////////////////////////////////////////////////////////////////////////////////
int *fillIdx(int n){
    //Declare and allocate memory
    int *a=new int[n];
    //Loop and fill with 2 digit numbers
    for(int i=0;i<n;i++){
        *(a+i)=i;
    }
    //return the pointer
    return a;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Fill Array with 2 Digit Numbers
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with 2 digit integers
////////////////////////////////////////////////////////////////////////////////
int *fill2Dg(int n){
    //Declare and allocate memory
    int *a=new int[n];
    //Loop and fill with 2 digit numbers
    for(int i=0;i<n;i++){
        *(a+i)=rand()%90+10;
    }
    //return the pointer
    return a;
}