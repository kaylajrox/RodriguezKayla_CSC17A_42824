/* 
 * File:   Color.cpp
 * Author: Kayla
  Created on May 29, 2016, 6:15 PM
 */

#include "Color.h"
#include <string>

using namespace std;
Color::Color(){
    color="";
    spot=0;
}
void Color::setColor(string x) {
    color=x;
}
string Color::getColor() {
    return color;
}
void Color::setSpot(int x){
    spot=x;
}
int Color::getSpot(){
    return spot;
}
  