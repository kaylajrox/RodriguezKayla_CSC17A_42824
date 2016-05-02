/* 
 * File:   ComColor.cpp
 * Author: Kayla
 * 
 * Created on April 30, 2016, 3:25 PM
 */

#include "ComColor.h"

ComColor::ComColor() {
    color="";
    spot=0;
}
void ComColor::setColor(string x) {
    color=x;
}
void ComColor::setSpot(int y) {
    spot=y;
}
string ComColor::getColor() {
    return color;
}
int ComColor::getSpot() {
    return spot;
}



