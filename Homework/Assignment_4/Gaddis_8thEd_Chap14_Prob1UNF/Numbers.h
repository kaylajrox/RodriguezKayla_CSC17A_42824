/* 
 * File:   Numbers.h
 * Author: Kayla
 *
 * Created on April 27, 2016, 10:49 PM
 */

#ifndef NUMBERS_H
#define NUMBERS_H
#include <string>
using namespace std;
class Numbers {
private:
    static string lessThan20[20] = {"zero","one","two","three","four","five","six",
    "seven","eight","nine","ten","eleven","twelve","thirteen","fourteen",
    "fifteen","sixteen","seventeen","eighteen","nineteen"};
    static string hundred="hundred";
    static string thousand="thousand";
public:
    Numbers();
    Numbers(const Numbers& orig);
    virtual ~Numbers();
};

#endif /* NUMBERS_H */

