/*File: NumDays.cpp*/

#include "NumDays.h"
NumDays::NumDays() {
}
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
    
}
NumDays NumDays::operator -(const NumDays&right)
{
    
}
NumDays NumDays::operator++(){
    
}
NumDays NumDays::operator++(int){
    
}
NumDays NumDays::operator--(){
    
}
NumDays NumDays::operator--(int){
    
}
NumDays NumDays::operator++(){
    
}