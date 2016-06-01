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
            for(int i=0;i<SIZE;i++){
                if(x==options[i]){
                    color=x;
                    return ;
                }
            }
            throw EmpClass();
        }
};

#endif /* USERCOLOR_H */

