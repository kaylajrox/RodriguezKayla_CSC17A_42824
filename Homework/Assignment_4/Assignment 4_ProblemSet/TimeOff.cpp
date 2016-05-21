/* 
 * File:   TimeOff.cpp
 * Author: Kayla
 * 
 * Created on May 19, 2016, 5:53 PM
 */

#include "TimeOff.h"
#include <string>

TimeOff::TimeOff() {
    mxSickDays=0;
    sickTaken=0;
    mxVacation=0;
    vacTaken=0;
    mxUnpaid=0;
    unpaidTaken=0;
    name="";
    id=0;
    hours=0;
}
void TimeOff::setName(std::string x){
    name=x;
}
std::string TimeOff::getName(){
   return name; 
}
void TimeOff::setId(int x){
    id=x;
}
int TimeOff::getId(){
   return id; 
}
void TimeOff::setHours(int x){
    hours=x;
}
int TimeOff::getHours(){
   return hours; 
}
float TimeOff::getDays(){
   return hours/8; 
}
void TimeOff::setMxSickDays(int x){
    mxSickDays=x;
}
int TimeOff::getMxSickDays(){
    return mxSickDays;
}
void TimeOff::setSickDays(int x){
    sickTaken=x;
}
int TimeOff::getSickDays(){
    return sickTaken;
}
void TimeOff::setMxVacDays(int x){
    mxVacation=x;
}
int TimeOff::getMxVacDays(){
    return mxVacation;
}
void TimeOff::setVacDays(int x){
    vacTaken=x;
}
int TimeOff::getVacDays(){
    return vacTaken;
}
void TimeOff::setMxUnpaid(int x){
    mxUnpaid=x;
}
int TimeOff::getMxUnpaid(){
    return mxUnpaid;
}
void TimeOff::setUnpaid(int x){
    unpaidTaken=x;
}
int TimeOff::getUnpaid(){
    return unpaidTaken;
}