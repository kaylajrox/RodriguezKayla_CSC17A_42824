/*midterm Problem 3*/

//System Libraries
#include <bits/stdc++.h>
using namespace std;

//User Libraries
struct statsResult{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};
//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv){
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    int size;
    int *array;
    //Input
    cout<<"What is the size of your array? "<<endl;
    cin>>size;
    array=new int[size];
    
    //Results
    statsResult result=*avgMedMode(array,size);
    //free memory
    return 0;
}
statsResult *avgMedMode(int *a,int size){
    //Loop and fill with 2 digit numbers
    for(int i=0;i<size;i++){
        *(a+i)=rand()%10;
    }
    //return the pointer
    return a;
}
