/* 
 * File:   UserColor.cpp
 * Implementation file containing user color information derived from the base
 * Color class
 */

#include "UserColor.h"

UserColor::UserColor() : Color() {
    turn=0;
}
UserColor UserColor::operator++() {
    UserColor temp;
    temp.setTurn(turn);
    turn++;
    return temp;
}
void UserColor::setTurn(int x){
    turn=x;
}
int UserColor::getTurn(){
    return turn;
}

