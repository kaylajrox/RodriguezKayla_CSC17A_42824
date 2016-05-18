/* 
 * File:   NumDays.h
 * Author: rcc
 *
 * Created on May 18, 2016, 1:26 PM
 */
#ifndef NUMDAYS_H
#define	NUMDAYS_H

class NumDays {
private:
    float hours; //number of hours worked
public:
    NumDays();
    void setHours(float);
    float getHours() const;
    float getDays() const;
    //overloaded operators functions
    NumDays operator +(const NumDays&); //overloading the + operator
    NumDays operator - (const NumDays &); //overloading the - operator
    NumDays operator ++ (int); //overloading prefix ++
    NumDays operator ++ (); //overloading postfix ++      
    NumDays operator -- (int); //overloading prefix --
    NumDays operator -- (); //overloading postfix -- 
};

#endif	/* NUMDAYS_H */

