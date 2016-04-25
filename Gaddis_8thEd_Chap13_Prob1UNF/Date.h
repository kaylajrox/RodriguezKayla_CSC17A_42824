/* 
 * File:   Date.h
 * Author: rcc
 *
 * Created on April 25, 2016, 3:40 PM
 */

#ifndef DATE_H
#define	DATE_H

class Date {
private:
    int month;
    int day;
    int year;
public:
    Date();
    Date(const Date& orig);
    virtual ~Date();


};

#endif	/* DATE_H */

