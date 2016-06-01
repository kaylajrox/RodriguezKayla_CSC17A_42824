/* 
 * File:   UserColor.cpp
 * Implementation file containing user color information derived from the base
 * Color class
 */
#include <string>
using namespace std;
#include "UserColor.h"

UserColor::UserColor() : Color() {
    turn=0;
}
UserColor UserColor::operator++() {
    ++turn;
    getTurn();
    return *this;
}
void UserColor::setTurn(int x){
    turn=x;
}
int UserColor::getTurn(){
    return turn;
}
