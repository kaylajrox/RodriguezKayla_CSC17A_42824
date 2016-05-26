/* 
 * File:   Employee.cpp
 * Author: rcc
 * 
 * Created on May 23, 2016, 2:40 PM
 */

#include "Employee.h"

Employee::Employee() {
    name="";
    id=0;
    hireDate="";
}
void Employee::setName(std::string x){
    name=x;
}
std::string Employee::getName(){
    return name;
}
void Employee::setNum(int x){
    id=x;
}
int Employee::getNum(){
    return id;
}
void Employee::setHireD(std::string x){
    hireDate=x;
}
std::string Employee::getHirdD(){
    return hireDate;
}