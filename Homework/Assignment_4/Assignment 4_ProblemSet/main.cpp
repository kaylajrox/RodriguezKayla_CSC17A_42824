/*Assignment 4 Problem Set*/

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
#include "Date.h"
#include "PersonalInfo.h"
#include "RetailItem.h"
#include "Inventory.h"
#include "Circle.h"
#include "Numbers.h"
#include "DayOfYear.h"
#include "DayOfYear2.h"
#include "NumDays.h"
#include "TimeOff.h"
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
void problem7();
void problem8();
void problem9();
void problem10();

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
        case 7:    problem7();break;
        case 8:    problem8();break;
        case 9:    problem9();break;
        case 10:   problem10();break;
        default:   {def(inN);
                    reDsply=false;}
        }
    }while(reDsply);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"\nMenu for Assignment 4"<<endl;
    cout<<"Type 1 for Gaddis_8thEd_Chap13_Prob1"<<endl;
    cout<<"Type 2 for Gaddis_8thEd_Chap13_Prob4"<<endl;
    cout<<"Type 3 for Gaddis_8thEd_Chap13_Prob5"<<endl;
    cout<<"Type 4 for Gaddis_8thEd_Chap13_Prob6"<<endl;
    cout<<"Type 5 for Gaddis_8thEd_Chap13_Prob8"<<endl;
    cout<<"Type 6 for Gaddis_8thEd_Chap14_Prob1"<<endl;
    cout<<"Type 7 for Gaddis_8thEd_Chap14_Prob2"<<endl;
    cout<<"Type 8 for Gaddis_8thEd_Chap14_Prob3"<<endl;
    cout<<"Type 9 for Gaddis_8thEd_Chap14_Prob4"<<endl;
    cout<<"Type 10 for Gaddis_8thEd_Chap14_Prob5"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}
void problem1(){
    cout<<"In Gaddis_8thEd_Chap13_Prob1"<<endl<<endl;
    //declare variables
    int day;//day to enter
    int month; //month to enter
    int year; //year to enter
    Date dateInfo; //date information to be stored in the class
    //input
    do{
        cout<<"Input the month ";
        cin>>month;
        if(month>12||month<1)
            cout<<"Invalid month entry."<<endl;
    }while(month>12||month<1);
    dateInfo.setMonth(month);
    do{
        cout<<"Input the day ";
        cin>>day;
        if(day>31||day<1)
            cout<<"Invalid day entry."<<endl;
    }while(day>31||day<1);
    dateInfo.setDay(day);
    cout<<"Input the year (in XXXX form)";
    cin>>year;
    dateInfo.setYear(year);
    cout<<"The date in its three forms: "<<endl;
    dateInfo.slashForm(); //slash form of the date
    dateInfo.cmaForm(); //comma form of the date
    dateInfo.mlaForm(); //formal MLA style of the date
}

void problem2(){
    cout<<"In  Gaddis_8thEd_Chap13_Prob4"<<endl<<endl;
    //declare variables
    string name;
    string address;
    string number;
    int age;
    PersonalInfo pInfo;
    //input
    cout<<"Enter your name "<<endl;
    getline(cin,name);
    cin.ignore();
    pInfo.setName(name);
    cout<<"Enter your address "<<endl;
    getline(cin,address);
    cin.ignore();
    pInfo.setAdd(address);
    cout<<"Enter your number"<<endl;
    getline(cin,number);
    cin.ignore();
    pInfo.setNum(number);
    cout<<"Enter your age "<<endl;
    cin>>age;
    pInfo.setAge(age);
    cout<<endl<<"Your information\n";
    cout<<"Name: "<<pInfo.getName()<<endl;
    cout<<"Address: "<<pInfo.getAdd()<<endl;
    cout<<"Number: "<<pInfo.getNum()<<endl;
    cout<<"Age: "<<pInfo.getAge()<<endl;
}


void problem3(){
    cout<<"In Gaddis_8thEd_Chap13_Prob5"<<endl<<endl;
    cout<<"Retail Items of a Store "<<endl;
    //Declare and Set Variables
    RetailItem item1;
    RetailItem item2;
    RetailItem item3;
    RetailItem item[3];
    
    item1.setItem1("Jacket", 12, 59.95);
    item2.setItem2("Designer Jeans", 40, 34.95);
    item3.setItem3("Shirt", 20, 24.95);
    //Output and Display the data
    cout<<"          "<<"Description\t\t"<<"Units On Hand\t"<<"Price"<<endl;
    cout<<"Item #1   "<<item1.getItem1_D()<<"\t\t"<<item1.getItem1_U()<<"\t\t";
    cout<<item1.getItem1_P();
    cout<<"\nItem #2   "<<item2.getItem2_D()<<"\t"<<item2.getItem2_U()<<"\t\t";
    cout<<item2.getItem2_P();
    cout<<"\nItem #3   "<<item3.getItem3_D()<<"\t\t\t"<<item3.getItem3_U()<<"\t\t";
    cout<<item3.getItem3_P();
    cout<<endl;
}

void problem4(){
    cout<<"In Gaddis_8thEd_Chap13_Prob6"<<endl<<endl;
    //declare variables
    int itmNum; //item number
    int quantity; //quantity of item
    float cost; //cost of item
    Inventory itemInfo;
    cout<<fixed<<setprecision(2);
    //input
    do{
        cout<<"What is the item number?"<<endl;
        cin>>itmNum;
    }while(itmNum<0);
    itemInfo.setItemNumber(itmNum);
    do{
        cout<<"What is the quantity of the item purchased?\n";
        cin>>quantity;
    }while(quantity<0);
    itemInfo.setQuantity(quantity);
    do{
        cout<<"What is the cost of the item?\n";
        cin>>cost;
    }while(cost<0);
    itemInfo.setCost(cost);
    itemInfo.setTotalCost(quantity,cost);
    cout<<"Item Information\n";
    cout<<"Item Number: "<<itemInfo.getItemNumber()<<endl;
    cout<<"Quantity: "<<itemInfo.getQuantity()<<endl;
    cout<<"Cost: $"<<itemInfo.getCost()<<endl;
    cout<<"Total Cost: $"<<itemInfo.getTotalCost()<<endl;   
}
void problem5(){
    cout<<"In Gaddis_8thEd_Chap13_Prob8"<<endl<<endl;
    float rad;
    Circle info;
    //input 
    cout<<"Input the radius"<<endl;
    cin>>rad;
    info.setRadius(rad);
    cout<<"Circle Information\n";
    cout<<"Area: "<<info.getArea(rad,PI)<<endl;
    cout<<"Diameter: "<<info.getDiameter(rad)<<endl;
    cout<<"Circumference: "<<info.getCircum(rad,PI)<<endl;    
}

void problem6(){
    cout<<"In Gaddis_8thEd_Chap14_Prob1"<<endl<<endl;
    //declare variables
    int number;
    Numbers numInfo;
    //input number to be written in its English word form
    cout<<"Enter a number between 0-10000 ";
    cin>>number;
    numInfo.print(number);
}
void problem7(){
    cout<<"In Gaddis_8thEd_Chap14_Prob2"<<endl<<endl;
    //declare variables
    int day;
    char leapQ; //leap year question
    DayOfYear info;
    //input day
    do{
        cout<<"Is it a leap year this year? Type y if yes, n if no "<<endl;
        cin>>leapQ;
        leapQ=tolower(leapQ);
        if(leapQ!='y'&&leapQ!='n')
            cout<<"Invalid answer"<<endl;
    }while(leapQ!='y'&&leapQ!='n');
    do{
        cout<<"Enter a day of the year (out of 365)"<<endl;
        cin>>day;
    }while(day>366&&day<1);
    if(leapQ=='y')
        info.leapYear(day);
    else
        info.print(day);
}
void problem8(){
   cout<<"In Gaddis_8thEd_Chap14_Prob3"<<endl<<endl;
   //declare variables
    int day;
    char leapQ; //leap year question
    DayOfYear2 info;
    //input day
    do{
        cout<<"Is it a leap year this year? Type y if yes, n if no "<<endl;
        cin>>leapQ;
        leapQ=tolower(leapQ);
        if(leapQ!='y'&&leapQ!='n')
            cout<<"Invalid answer"<<endl;
    }while(leapQ!='y'&&leapQ!='n');
    do{
        cout<<"Enter a day of the year (out of 365)"<<endl;
        cin>>day;
        info.setDay(day);
    }while(day>366&&day<1);
    if(leapQ=='y')
        info.leapYear();
    else
        info.print();
    
    cout<<"\nOriginal Day: ";
    info.print();
    ++info;
    cout<<"\nAfter Incremented Day: ";
    info.print();
    cout<<"\nThe previous day: ";
    --info;
    --info;
    info.print();
}
void problem9(){
   cout<<"In Gaddis_8thEd_Chap14_Prob4"<<endl<<endl;
   //declare variables
    float hours,hours1,hours2;
    NumDays hrsToDays,hrsToDays1,hrsToDays2;
    //input
    cout<<"This program converts number of work hours to number of days"<<endl;
    cout<<"And demonstrates different overloaded operators."<<endl;
    do{
        cout<<"Enter the number hours to be converted "<<endl;
        cin>>hours;
    }while(hours<0);
    hrsToDays.setHours(hours);
    cout<<"The number of days this is: \n";
    cout<<hrsToDays.getDays();
    cout<<"\nThis part of the program demonstrates overloaded operators"<<endl;
    cout<<"Adding Days"<<endl;
    //Adding Days
    do{
        cout<<"Enter the number hours to be converted "<<endl;
        cin>>hours1;
    }while(hours1<0);
    hrsToDays1.setHours(hours1);
    do{
        cout<<"Enter the number hours to be converted "<<endl;
        cin>>hours2;
    }while(hours2<0);
    hrsToDays2.setHours(hours2);
    hrsToDays1.getDays();
    hrsToDays2.getDays();
    cout<<"\nThe added amount of days is ";
    NumDays combined=hrsToDays1+hrsToDays2; //combined days of both inputs
    cout<<combined.getDays();
    cout<<"\nThe subtracted days is:";
    NumDays combine=hrsToDays1-hrsToDays2; //combined days of both inputs
    cout<<combine.getDays();
    cout<<"\nIncrementing Days (Prefix operator)"<<endl;
    NumDays incre1pre = ++hrsToDays1;//increment days of first input(prefix)
    NumDays incre2pre = ++hrsToDays2;//increment days of second input(prefix)
    cout<<"For first input: "<<incre1pre.getDays()<<endl;
    cout<<"For second input: "<<incre2pre.getDays()<<endl;
    cout<<"Incrementing Days (Postfix operator)"<<endl;
    NumDays incre1pst = hrsToDays1++; //incrementing days of first input(postfix)
    NumDays incre2pst = hrsToDays2++;//incrementing days of second input(postfix)
    cout<<"For first input: "<<incre1pst.getDays()<<endl;
    cout<<"For second input: "<<incre2pst.getDays()<<endl;
    cout<<"Decrementing Days (prefix)"<<endl;
    NumDays decr1pre = --hrsToDays1;//decrement days of first input(prefix)
    NumDays decr2pre = --hrsToDays2;//decrement days of second input(prefix)
    cout<<"For first input: "<<decr1pre.getDays()<<endl;
    cout<<"For second input: "<<decr2pre.getDays()<<endl;
    cout<<"Decrementing Days (postfix)"<<endl;
    NumDays decr1pst = hrsToDays1--;//decrement days of first input(postfix)
    NumDays decr2pst = hrsToDays2--;//decrement days of second input(postfix)
    cout<<"For first input: "<<decr1pst.getDays()<<endl;
    cout<<"For second input: "<<decr2pst.getDays()<<endl;
}
void problem10(){
    cout<<"In Gaddis_8thEd_Chap14_Prob5"<<endl<<endl;
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
    cout<<"Out of the total of "<<tmoff.getMxVacDays()<<" vacation days ";
    cout<<"the employee took "<<tmoff.getVacDays()<<" vacation days. "<<endl;
    cout<<"Out of the maximum number of unpaid vacation days "<<tmoff.getMxUnpaid();
    cout<<" the employee took "<<tmoff.getUnpaid()<<" days off"<<endl;
}
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}