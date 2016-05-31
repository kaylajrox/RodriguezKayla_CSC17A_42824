/* 
 * File:   main.cpp
 * Author: rcc
 * Title: Employee and ProductionWorker Classes
 * Created on May 23, 2016, 2:27 PM
 */

/*Design a class named Employee. 
The class should keep the following information in
• Employee name
• Employee number
• Hire date
Write one or more constructors and the appropriate accessor and mutator functions
for the class. 
Next, write a class named ProductionWorker that is derived from the Employee class.
The ProductionWorker class should have member variables to hold the following
information:
• Shift (an integer)
• Hourly pay rate (a float )
The workday is divided into two shifts: day and night. The shift variable will 
hold an integer value representing the shift that the employee works. The day 
shift is shift 1, and the night shift is shift 2. Write one or more constructors 
and the appropriate accessor and mutator functions for the class. Demonstrate
the classes by writing a program that uses a ProductionWorker object. 
 */
/*Need to add the constructors default content*/
//System Libraries
#include <iostream>
#include <string>

//User Libraries
#include "ProductionWorker.h"
using namespace std;

int main(int argc, char** argv) {
    //declare variables
    string name; //employee name
    int empNum; //employee number
    string hireDate; //hire date of the employee
    int shift; //the shift of the employee (shift 1 or shift 2)
    float rate; //employee rate of pay
    bool v=true;//validation for shift
    ProductionWorker emp;
    
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
    cout<<"What is the employee's shift? Enter 1 for shift 1, 2 for shift 2"<<endl;
    cin>>shift;
    while(v){
        try{
            //call set function
            emp.setShift(shift);
            v=false;
        }catch(ProductionWorker::EmpClass){
            cout<<"Invalid Entry. Shift must be 1 or 2"<<endl;
            cin>>shift;
        }
    }
    cout<<"What is the employee's rate of pay? "<<endl;
    cin>>rate;
    emp.setRate(rate);
    cout<<"***********************************"<<endl;
    cout<<"Production Worker Information "<<endl;
    cout<<"Name: "<<emp.getName()<<endl;
    cout<<"Employee Id: "<<emp.getNum()<<endl;
    cout<<"Hire Date: "<<emp.getHirdD()<<endl;
    cout<<"Shift: "<<emp.getShift()<<endl;
    cout<<"Hourly Pay Rate: $"<<emp.getRate()<<endl;
    cout<<"***********************************"<<endl;
    return 0;
}

