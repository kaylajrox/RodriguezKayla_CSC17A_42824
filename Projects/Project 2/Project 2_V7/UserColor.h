/* 
 * File:   UserColor.h
 * Specification file containing user color information derived from the base
 * Color class
 */

#ifndef USERCOLOR_H
#define USERCOLOR_H
#include <string>
using namespace std;

#include "Color.h"
class UserColor : public Color {
    protected:
        int turn; 
    public:
        UserColor();
        UserColor operator ++();//overloading the ++ operator
        void setTurn(int);
        int getTurn();
        
        void setColor(string x) {
            if(x==options[0]||x==options[1]||x==options[2]||x==options[3]||
                        x==options[4]||x==options[5]||x==options[6]||x==options[7]){
                    color=x;
            }
            else{
                throw EmpClass();
            }
        }
};

#endif /* USERCOLOR_H */

