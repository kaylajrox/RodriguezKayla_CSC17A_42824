/* 
 * File:   UserColor.h
 * Author: Kayla
 *
 * Created on May 30, 2016, 4:49 PM
 */

#ifndef USERCOLOR_H
#define USERCOLOR_H
#include <string>
using namespace std;
class UserColor{    
private:
    string color;
    int spot;
public:
    void setColor(string);
    string getColor();
    void setSpot(int);
    int getSpot();
};

#endif /* USERCOLOR_H */

