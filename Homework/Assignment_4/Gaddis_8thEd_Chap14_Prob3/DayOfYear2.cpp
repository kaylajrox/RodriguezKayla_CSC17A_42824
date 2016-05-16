/* 
 * File:   DayOfYear2.cpp
 * Author: Kayla
 * 
 * Created on May 12, 2016, 2:34 PM
 */

#include "DayOfYear2.h"
#include <iostream>
using namespace std;
DayOfYear2::DayOfYear2() {
    day=0;
}
int DayOfYear2::getDay(){
    return day;
}
void DayOfYear2::setDay(int x){
    day=x;
}
void DayOfYear2::print() {
   //leap year calculations
    if(day>=1&&day<=31)
        cout<<"January "<<day;
    if(day>31&&day<=59)
        cout<<"February "<<(day-31);
    if(day>59&&day<=90)
        cout<<"March "<<(day-59);
    if(day>90&&day<=120)
        cout<<"April "<<(day-90);
    if(day>120&&day<=151)
        cout<<"May "<<(day-120);
    if(day>151&&day<=181)
        cout<<"June "<<(day-151);
    if(day>181&&day<=212)
        cout<<"July "<<(day-181);
    if(day>212&&day<=243)
        cout<<"August "<<(day-212);
    if(day>243&&day<=273)
        cout<<"September "<<(day-243);
    if(day>273&&day<=304)
        cout<<"October "<<(day-273);
    if(day>304&&day<=334)
        cout<<"November "<<(day-304);
    if(day>334&&day<=365)
        cout<<"December "<<(day-334);
}
void DayOfYear2::leapYear(){
     //leap year calculations
    if(day>=1&&day<=31)
        cout<<"January "<<day;
    if(day>31&&day<=60)
        cout<<"February "<<(day-31);
    if(day>60&&day<=91)
        cout<<"March "<<(day-60);
    if(day>91&&day<=121)
        cout<<"April "<<(day-91);
    if(day>121&&day<=152)
        cout<<"May "<<(day-121);
    if(day>152&&day<=182)
        cout<<"June "<<(day-152);
    if(day>182&&day<=213)
        cout<<"July "<<(day-182);
    if(day>213&&day<=244)
        cout<<"August "<<(day-213);
    if(day>244&&day<=274)
        cout<<"September "<<(day-244);
    if(day>274&&day<=305)
        cout<<"October "<<(day-274);
    if(day>305&&day<=335)
        cout<<"November "<<(day-305);
    if(day>335&&day<=366)
        cout<<"December "<<(day-335);
}
 DayOfYear2& DayOfYear2::operator++(){
    day++;
    if(day>365) day=1;
   return *this; 
 }
 DayOfYear2& DayOfYear2::operator--(){
    day--;
    if(day<1) day=365;
   return *this; 
 }