/* 
 * File:   Prob1Random.cpp
 * Author: Kayla
 * 
 * Created on June 11, 2016, 4:30 PM
 */

#include "Prob1Random.h"


Prob1Random::Prob1Random(const char n,const char * list){
    //set the random seed
    srand(static_cast<unsigned int>(time(0)));
    set=new char[(int)n];
    nset=n;
    freq=new int[(int)n];
    for(int i=0;i<(int)nset;i++){
        set[i]=list[i];
        freq[i]=0;
    }
    numRand=0;
}
Prob1Random::~Prob1Random(void){
    delete[] set;
    delete[] freq;
}
char Prob1Random::randFromSet(void){
    numRand++;
    int idex=rand()%5;
    freq[idex]++;
    return set[idex];
}
int *Prob1Random::getFreq(void) const{
    return freq;
}
char *Prob1Random::getSet(void) const{
    return set;
}
int Prob1Random::getNumRand(void) const{
    return numRand;
}