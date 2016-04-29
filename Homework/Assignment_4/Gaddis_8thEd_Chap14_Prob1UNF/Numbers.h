/* 
 * File:   Numbers.h
 * Author: Kayla
 * Created on April 27, 2016, 10:49 PM
 */

#ifndef NUMBERS_H
#define NUMBERS_H
#include <string>
#include <bits/stdc++.h>
using namespace std;
class Numbers {
private:
    int number;
    static const int SIZE;
    static const string lessThan20[SIZE];
    static const string hundred; 
    static const string thousand; 
public:
    Numbers();
    void print(int);
};
#endif /* NUMBERS_H */

