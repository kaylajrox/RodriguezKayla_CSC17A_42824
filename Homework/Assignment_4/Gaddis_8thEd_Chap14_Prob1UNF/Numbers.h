/* 
 * File:   Numbers.h
 * Author: Kayla
 * Created on April 27, 2016, 10:49 PM
 */

#ifndef NUMBERS_H
#define NUMBERS_H
#include <string>
using namespace std;
class Numbers {
private:
    int number;
    static const int SIZE;
    static string lessThan20[SIZE];
    static string hundred; 
    static string thousand; 
public:
    Numbers();
    void print(int);
};
const int Numbers::SIZE=20;
string Numbers::thousand= "thousand";
string Numbers::thousand= "hundred";
string Numbers::lessThan20[SIZE]= {"zero", "one","two","three","four","five",
    "six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen",
    "fifteen","sixteen","seventeen","eighteen", "nineteen"}; 
#endif /* NUMBERS_H */

