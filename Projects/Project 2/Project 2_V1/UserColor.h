/* 
 * File:   UserColor.h
 * Specification file containing user color information derived from the base
 * Color class
 */

#ifndef USERCOLOR_H
#define USERCOLOR_H
#include "Color.h"
class UserColor : public Color {
    private:
        int turn; 
    public:
        UserColor();
        UserColor operator ++();//overloading the ++ operator
        void setTurn(int);
        int getTurn();
        
};

#endif /* USERCOLOR_H */

