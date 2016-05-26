/* 
 * File:   main.cpp
 * Author: Kayla
 * Title: ShiftSupervisor Class
 * Problem: Gaddis_8thEd_Chap15_Prob2
  Created on May 26, 2016, 2:52 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "ShiftSupervisor.h"

//Execution Begins Here
int main(int argc, char** argv) {
 //declare variables
    string name; //employee name
    int empNum; //employee number
    string hireDate; //hire date of the employee
    int shift; //the shift of the employee (shift 1 or shift 2)
    float salary; //employee rate of pay
    float bonus;
    ShiftSupervisor emp;
    //input information
    cout<<"What is the name of the employee? "<<endl;
    getline(cin,name);
    emp.setName(name);
    cout<<"What is the employee's id number? "<<endl;
    cin>>empNum;
    emp.setNum(empNum);
    cout<<"What was the hire date of the employee? (mm/dd/yy) "<<endl;
    cin>>hireDate;
    emp.setHireD(hireDate);
    cout<<"What is the supervisor's annual salary? "<<endl;
    cin>>salary;
    emp.setSalary(salary);
    cout<<"What is the production bonus the supervisor made?"<<endl;
    cin>>bonus;
    emp.setBonus(bonus);
    
    //Output Employee Information
    cout<<"***********************************"<<endl;
    cout<<"Shift Supervisor Information "<<endl;
    cout<<"Name: "<<emp.getName()<<endl;
    cout<<"Employee Id: "<<emp.getNum()<<endl;
    cout<<"Hire Date: "<<emp.getHirdD()<<endl;
    cout<<"Annual Salary: $"<<emp.getSalary()<<endl;
    cout<<"Bonus: $"<<emp.getBonus()<<endl;
    cout<<"Total Salary with Bonus: "<<(emp.getSalary()+emp.getBonus())<<endl;
    cout<<"***********************************"<<endl;
    return 0;
}

