
/* 
 * File:   main.cpp
 * Author: Kayla
 *
 * Created on June 11, 2016, 4:28 PM
 */

#include <iostream>
using namespace std;

#include "Prob1Random.h"

int main(int argc, char** argv) {
    cout<<"Now Entering Problem 1"<<endl;
    char n=5;
    char rndseq[]={16,34,57,79,144};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
        a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
        cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    return 0;
}

