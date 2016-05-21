/*File: NumDays.cpp*/

#include "NumDays.h"
//constructor
NumDays::NumDays() {
    hours = 0; 
}
//mutator functions
void NumDays::setHours(float x){
    hours = x;
}
//accessor functions
float NumDays::getHours() const{
    return hours;
}
float NumDays::getDays() const{
    return hours/8;
}
NumDays NumDays::operator +(const NumDays&right){
    NumDays t;
    t.hours = hours +right.hours ;
    return t;
}
NumDays NumDays::operator -(const NumDays&right){
    NumDays temp;
    temp.hours = hours - right.hours ;
    return temp;
}
NumDays NumDays::operator++(){
    ++hours;
    getDays();
    return *this;
}
NumDays NumDays::operator++(int){
     NumDays temp;
    temp.setHours(hours);
    hours++;
    temp.getDays();
    return temp;  
}
NumDays NumDays::operator--(){
    --hours;
    getDays();
    return *this;
}
NumDays NumDays::operator--(int){
    NumDays temp;
    temp.setHours(hours);
    hours--;
    temp.getDays();
    return temp;
}
