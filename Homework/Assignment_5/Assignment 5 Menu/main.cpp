/*Assignment 5 Problem Set*/
/*Need: One more template
 Includes: classes in all of them
 2 exceptions
 two template
 Fix: problems 1-3 where the user enter their name*/
//Library includes Here
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

//Global Constants 
const float PI=3.1415926;

//User Libraries
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"
#include "Date.h"
#include "AbsValue.h"
#include "TimeClock.h"

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    bool reDsply=true;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break; 
        case 6:    problem6();break;
        default:   {def(inN);
                    reDsply=false;}
        }
    }while(reDsply);
    return 0;
}

void Menu(){
    cout<<"\nMenu for Assignment 4"<<endl;
    cout<<"Type 1 for Gaddis_8thEd_Chap15_Prob1"<<endl;
    cout<<"Type 2 for Gaddis_8thEd_Chap15_Prob2"<<endl;
    cout<<"Type 3 for Gaddis_8thEd_Chap15_Prob3"<<endl;
    cout<<"Type 4 for Gaddis_8thEd_Chap16_Prob1"<<endl;
    cout<<"Type 5 for Gaddis_8thEd_Chap16_Prob4"<<endl;
    cout<<"Type 6 for Gaddis_8thEd_Chap15_Prob4"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}
void problem1(){
    cout<<"In Gaddis_8thEd_Chap15_Prob1"<<endl<<endl;
    cout<<"Employee and ProductionWorker Classes"<<endl;
    cout<<"This problem demonstrates implementation of an exception"<<endl;
    cout<<"As well as derived classes (inheritance)"<<endl;
   
    //declare variables
    string name; //employee name
    string empNum; //employee number
    string hireDate; //hire date of the employee
    int shift; //the shift of the employee (shift 1 or shift 2)
    float rate; //employee rate of pay
    bool v=true;//validation for shift
    ProductionWorker emp; //employee information held here
    
    //input information
    cout<<"\nInput the following employee information"<<endl;
    //this part not working
    cout<<"What is the name of the employee? "<<endl;
    cin.ignore();
    getline(cin,name);
    emp.setName(name);
    cin.ignore();
    do{
        cout<<"What is the employee's id number? Enter a four digit number"<<endl;
        cin>>empNum;
        if(empNum.length()!=4){
            cout<<"Invalid entry enter again."<<endl;
        }
    }while(empNum.length()!=4);
    emp.setNum(empNum);    
    do{
        cout<<"What was the hire date of the employee? (mm/dd/yy) "<<endl;
        cin>>hireDate;
        if(hireDate.length()!=8){
            cout<<"Invalid entry enter again."<<endl;
        }
    }while(hireDate.length()!=8);
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
}

void problem2(){
    cout<<"In  Gaddis_8thEd_Chap15_Prob2"<<endl<<endl;
    cout<<"ShiftSupervisor Class"<<endl;
    //declare variables
    string name; //employee name
    string empNum; //employee number
    string hireDate; //hire date of the employee
    int shift; //the shift of the employee (shift 1 or shift 2)
    float salary; //employee rate of pay
    float bonus;
    ShiftSupervisor emp;
    
    //input information
    cout<<"What is the name of the employee? "<<endl;
    cin.ignore();
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
}
void problem3(){
    cout<<"In Gaddis_8thEd_Chap15_Prob3"<<endl<<endl;
    cout<<"TeamLeader Class"<<endl;
    
    //declare variables
    string name; //employee name
    string empNum; //employee number
    string hireDate; //hire date of the employee
    int shift; //the shift of the employee (shift 1 or shift 2)
    float rate; //employee rate of pay
    float bonus; //monthly bonus
    int hrsR;//required number of training hours
    int hrsA; //number of training hours already completed
    TeamLeader emp; //team leader information
    
    //input information
    cout<<"What is the required number of training hours to be a team leader?"<<endl;
    cin>>hrsR;
    emp.setTrainR(hrsR);
    cout<<"What is the amount of training hours the employee has already attended?"<<endl;
    cin>>hrsA;
    emp.setTrainA(hrsA);
    cout<<"What is the name of the team leader? "<<endl;
    cin.ignore();
    getline(cin,name);
    emp.setName(name);
    cout<<"What is the team leader's id number? "<<endl;
    cin>>empNum;
    emp.setNum(empNum);
    cout<<"What was the hire date of the team leader's? (mm/dd/yy) "<<endl;
    cin>>hireDate;
    emp.setHireD(hireDate);
    do{
        cout<<"What is the team leader's shift? Enter 1 for shift 1, 2 for shift 2"<<endl;
        cin>>shift;
        if(shift<1||shift>2)cout<<"Invalid shift number"<<endl;
    }while(shift<1||shift>2);
    emp.setShift(shift);
    cout<<"What is the team leader's rate of pay? "<<endl;
    cin>>rate;
    emp.setRate(rate);
    cout<<"What is the team leader's monthly bonus? "<<endl;
    cin>>bonus;
    emp.setMonBon(bonus);
    
    cout<<"********************************************"<<endl;
    cout<<"Team Leader Information "<<endl;
    cout<<"Name: "<<emp.getName()<<endl;
    cout<<"Employee Id: "<<emp.getNum()<<endl;
    cout<<"Hire Date: "<<emp.getHirdD()<<endl;
    cout<<"Shift: "<<emp.getShift()<<endl;
    cout<<"Monthly Bonus: $"<<emp.getMonBon()<<endl;
    cout<<"Hourly Pay Rate: $"<<emp.getRate()<<endl;
    cout<<"Required Total Training Hours: "<<emp.getTrainR()<<endl;
    cout<<"Training Hours Already Attended: "<<emp.getTrainA()<<endl;
    if(hrsA<hrsR){
        cout<<"Hours Still Needed: "<<(emp.getTrainR()-emp.getTrainA())<<endl;
    }
    cout<<"********************************************"<<endl;
}

void problem4(){
    cout<<"In Gaddis_8thEd_Chap16_Prob1"<<endl<<endl;
    cout<<"Date Exceptions"<<endl;
    
    //declare variables
    int day;//day to enter
    int month; //month to enter
    string year; //year to enter
    bool valid=true; //validation
    Date dateInfo; //date information to be stored in the class
    
    //input
    do{
        cout<<"Input the month ";
        cin>>month;
        if(month>12||month<1)
            cout<<"Invalid month entry."<<endl;
    }while(month>12||month<1);
    dateInfo.setMonth(month);
    cout<<"Input the day ";
    cin>>day;
    while(valid){
        try{
            dateInfo.setDay(day);
            valid=false;
        }catch(Date::EmpClass){
            cout<<"Invalid Entry. Input Day"<<endl;
            cin>>day;
        }
    }
    do{
        cout<<"Input the year ";
        cin>>year;
    }while(year.length()!=4);
    dateInfo.setYear(year);
    cout<<"The date in its three forms: "<<endl;
    dateInfo.slashForm(); //slash form of the date
    dateInfo.cmaForm(); //comma form of the date
    dateInfo.mlaForm(); //formal MLA style of the date  
}
void problem5(){
    cout<<"In Gaddis_8thEd_Chap16_Prob4"<<endl<<endl;
    cout<<"Absolute Value Template"<<endl;
     //declare variables
    float number;
    AbsValue <float> num;
    
    cout<<"Enter a number to have the absolute value taken of "<<endl;
    cin>>number;
    num.setAbs(number);
    
    cout<<num.findAbs(); 
}
void problem6(){
    cout<<"In Gaddis_8thEd_Chap15_Prob4"<<endl<<endl;
    cout<<"TimeClock Template"<<endl;
    
    //declare variables
    int mhr;
    int mSec;
    int mSec2;
    
    //declare instances
    TimeClock <int>time;
    cout<<"This program changes military time to standard time."<<endl;
    do{
        cout<<"Enter the time in this form (XXXX) must be between 2359 and 0000\n";
        cin>>mhr;
    }while(mhr>2359||mhr<0000);
    do{
        cout<<"Enter the number of seconds"<<endl;
        cin>>mSec;
    }while(mSec>59||mSec<0);
    do{
        cout << "Enter the seconds2:(Must be between 59 and 0)\n";
        cin >> mSec2;
    }while(mSec>59||mSec<0);
    
     time.setTime(mhr,mSec,mSec2);
    
    cout << "Military time: ";
    if(time.getHour()==0)
        cout << "0000";
    else if(time.getHour()<900){
        cout << "0" << time.getHour();
    }
    else
     cout << time.getHour();

    cout <<endl;
    cout << "Standard time: ";
    if(time.getHour()==0)
        cout << "1200";
    else if(time.getHour()<900){
        cout << "0" << time.getHour();
    }
    else
     cout << time.getHour();
    
    cout<< "\nSeconds: ";
    cout << time.bigger();
    cout<< endl<<endl;
}
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
