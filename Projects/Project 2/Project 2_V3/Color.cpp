/* 
 * File:   Color.cpp
 * Author: Kayla
  Created on May 29, 2016, 6:15 PM
 */

#include "Color.h"
#include <string>
using namespace std;

//Initialize the static members
string Color::options[SIZE]={"red","green","blue","brown","black","yellow",
"orange","white"};

Color::Color(){
    color="";
    spot=0;
}
void Color::setColor(string x) {
    for(int i=0;i<SIZE;i++){
        if(x!=options[i]){
            color=x;
        }
        else{
            throw EmpClass();
        }
    }
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
 