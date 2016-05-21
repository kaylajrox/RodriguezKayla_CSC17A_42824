/* 
 * File:   main.cpp
 * Author: Kayla
 *
 * Created on May 19, 2016, 5:49 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "TimeOff.h"
//Execution Begins Here
int main(int argc, char** argv) {
    //declare variables
    TimeOff tmoff; //time off 
    int hours;
    int mxSkDays; //Maximum number of sick days 
    int skDays; //Number of sick days the employee has already taken
    int mxVac; //maximum vacation days
    int pVac; //number of paid vacation days take
    int mxUnpVac;//maximum days of unpaid vacation an employee can take
    int unpTaken;//unpaid vacation days taken
    string name;
    int id;
    cout<<"What is the employee's name? ";
    cin>>name;
    tmoff.setName(name);
    cout<<"What is the employee's id number? ";
    cin>>id;
    tmoff.setId(id);
    //Conversion of hours to work days
    cout<<"Enter a total number of hours worked by the employee  "<<endl;
    cin>>hours;
    tmoff.setHours(hours);
    cout<<"What is the maximum days of sick leave an employee may take? ";
    cin>>mxSkDays;
    tmoff.setMxSickDays(mxSkDays);
    cout<<"What is the amount of sick days the employee has already taken?\n";
    cin>>skDays;
    tmoff.setSickDays(skDays);
    do{
        cout<<"What is the maximum number of days of paid vacation an employee can take? \n";
        cin>>mxVac;
        if(mxVac>240){
            cout<<"You cannot have paid vacation over 240 days"<<endl;
        }
    }while(mxVac>240);
    tmoff.setMxVacDays(mxVac);
    cout<<"What is the the number of days the employee has taken paid vacation?\n";
    cin>>pVac;
    tmoff.setVacDays(pVac);
    cout<<"What is the max number of unpaid vacation an employee can take?\n";
    cin>>mxUnpVac;
    tmoff.setMxUnpaid(mxUnpVac);
    cout<<"What is the amount of unpaid sick days the employee has taken?"<<endl;
    cin>>unpTaken;
    tmoff.setUnpaid(unpTaken);
    //Print out Employee Information
    cout<<"Employee Name: "<<tmoff.getName();
    cout<<"\nEmployee Id: "<<tmoff.getId();
    cout<<"\nTotal Days worked overall "<<tmoff.getDays();
    cout<<"\nOut of the total of "<<tmoff.getMxSickDays()<<" sick days ";
    cout<<"the employee took "<<tmoff.getSickDays()<<" sick days. "<<endl;
    cout<<"\nOut of the total of "<<tmoff.getMxVacDays()<<" vacation days ";
    cout<<"the employee took "<<tmoff.getVacDays()<<" vacation days. "<<endl;
    cout<<"\nOut of the maximum number of unpaid vacation days "<<tmoff.getMxUnpaid();
    cout<<" the employee took "<<tmoff.getUnpaid()<<" days off"<<endl;
    
    return 0;
}

