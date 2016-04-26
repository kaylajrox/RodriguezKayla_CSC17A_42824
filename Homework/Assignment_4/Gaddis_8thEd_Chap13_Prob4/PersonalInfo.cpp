/* 
 * File:   PersonalInfo.cpp
 * Author: Kayla
 * 
 * Created on April 25, 2016, 8:35 PM
 */
/*Questions: Do I also have to set the strings in the default constructor?*/
#include "PersonalInfo.h"
#include <string>
using namespace std;
PersonalInfo::PersonalInfo() {
    num="";
    age=0;
    name="";
    address="";
}
//set the name
void PersonalInfo::setName(string n){
    name=n;
}
//set the address
void PersonalInfo::setAdd(string n){
    address=n;
}
//set the phone number
void PersonalInfo::setNum(string n){
    num=n;
}
//set the age
void PersonalInfo::setAge(int n){
    age=n;
}
//get the name
string PersonalInfo::getName(){
    return name;
}
//get the address
string PersonalInfo::getAdd(){
    return address;
}
//get the phone number
string PersonalInfo::getNum(){
    return num;
}
//get the age
int PersonalInfo::getAge(){
    return age;
}

