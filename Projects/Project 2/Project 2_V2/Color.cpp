/* 
 * File:   Color.cpp
 * Author: Kayla
 * 
 * Created on May 29, 2016, 6:15 PM
 */

#include "Color.h"
Color::Color(){
    color="";
    spot=0;
}
void Color::setColor(std::string x) {
    color=x;
}
std::string Color::getColor() {
    return color;
}
void Color::setSpot(int x){
    spot=x;
}
int Color::getSpot(){
    return spot;
}
  
