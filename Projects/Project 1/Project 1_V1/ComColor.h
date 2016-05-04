
/* 
 * File:   ComColor.h
 * Author: Kayla
 *
 * Created on April 30, 2016, 3:25 PM
 */

#ifndef COMCOLOR_H
#define COMCOLOR_H
#include <string>
using namespace std;

class ComColor {
private:
    string color;
    int spot;
public:
    ComColor();
    //Accessor and Mutator Functions
    void setColor(string);
    string getColor();
};

#endif /* COMCOLOR_H */

