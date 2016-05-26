/* 
 * File:   main.cpp
 * Author: Kayla
 * Title: TeamLeader Class
 * Problem: Gaddis_8thEd_Chap15_Prob3
 * Created on May 26, 2016, 3:37 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "TeamLeader.h"
int main(int argc, char** argv) {
//declare variables
    string name; //employee name
    int empNum; //employee number
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
    return 0;
}

