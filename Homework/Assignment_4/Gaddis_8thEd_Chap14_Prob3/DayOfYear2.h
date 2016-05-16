/* 
 * File:   DayOfYear2.h
 * Author: Kayla
 *
 * Created on May 12, 2016, 2:34 PM
 */

#ifndef DAYOFYEAR2_H
#define DAYOFYEAR2_H

class DayOfYear2 {
private:
    int day;
public:
    DayOfYear2();
    void print();
    void leapYear();
    void setDay(int);
    int getDay();
    DayOfYear2& operator++(); 
    DayOfYear2& operator--(); 
};

#endif /* DAYOFYEAR2_H */

