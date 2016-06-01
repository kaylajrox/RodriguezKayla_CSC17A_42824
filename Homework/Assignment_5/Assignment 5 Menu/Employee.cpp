/* 
 * File:   Employee.cpp
 * Base Class Employee
 * Implementation file
 */

#include "Employee.h"
#include <string>
using namespace std;
Employee::Employee() {
    name="";
    id="";
    hireDate="";
}
void Employee::setName(std::string x){
    name=x;
}
std::string Employee::getName(){
    return name;
}
void Employee::setNum(string x){
    id=x;
}
string Employee::getNum(){
    return id;
}
void Employee::setHireD(std::string x){
    hireDate=x;
}
std::string Employee::getHirdD(){
    return hireDate;
}