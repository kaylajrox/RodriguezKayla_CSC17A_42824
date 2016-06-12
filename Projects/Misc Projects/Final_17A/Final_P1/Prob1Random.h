
/* 
 * File:   Prob1Random.h
 * Author: Kayla
 *
 * Created on June 11, 2016, 4:30 PM
 */

#ifndef PROB1RANDOM_H
#define PROB1RANDOM_H
#include <ctime>
#include <cstdlib>
using namespace std;
class Prob1Random
{
    private:
        char *set;      //The set of numbers to draw random numbers from
        char  nset;     //The number of variables in the sequence
        int  *freq;     //Frequency of all the random numbers returned
        int   numRand;  //The total number of times the random number function is called
    public:
        Prob1Random(const char,const char *);     //Constructor
        ~Prob1Random(void);                       //Destructor
        char randFromSet(void);                   //Returns a random number from the set
        int *getFreq(void) const;                 //Returns the frequency histogram
        char *getSet(void) const;                 //Returns the set used
        int getNumRand(void) const;               //Gets the number of times randFromSet has
                                                  //been called
};
#endif /* PROB1RANDOM_H */

