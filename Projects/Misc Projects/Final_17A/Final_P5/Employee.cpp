/* 
 * File:   Employee.cpp
 * Author: Kayla 
 * Created on June 10, 2016, 6:38 AM
 */

#include "Employee.h"
#include <iostream>
#include <cstring>
using namespace std;

Employee::Employee(char a[],char b[],float c) {
    for(int i=0;i<strlen(MyName);i++){
        MyName[i]=a[i];
        JobTitle[i]=b[i];
    }
    setHourlyRate(c);
    NetPay=0;
    GrossPay=0;
    HoursWorked=0;
}

float  Employee::getGrossPay(float HourlyRate,int HoursWorked){
    GrossPay=0;
    if(HoursWorked<=40){
        GrossPay=HourlyRate*HoursWorked;
    }else if(HoursWorked<=50){
        GrossPay=40*HourlyRate+(HoursWorked-40)*(HourlyRate*1.5);
    }else{
        GrossPay=55*HourlyRate+(HourlyRate-50)*2*HourlyRate;
    }
    return GrossPay;
}
float  Employee::getNetPay(float g){
    NetPay=GrossPay-Tax(g);
  return NetPay;
    
} 
float Employee::Tax(float GrossPay){
    if(GrossPay<=500){
        NetPay=GrossPay-(.1*GrossPay);
    }else if(GrossPay<=1000){
        NetPay=500*.1+(GrossPay-500)*.2;
    }else{
        NetPay=500*.1+500*.2+(GrossPay-1000)*.3;
    }
    return NetPay;
}

void Employee::toString(){
    cout<<"Name "<<MyName<<" Job Title = "<<JobTitle<<endl;
    cout<<"Hourly Rate = "<<HourlyRate<<" Hours Worked = "<<HoursWorked;
    cout<<" Gross Pay="<<GrossPay<<" NetPay="<<NetPay<<endl;
}    
int Employee::setHoursWorked(int x){
    if(HoursWorked<0||HoursWorked>84){
        cout<<"Unacceptable Hours Worked\n";
        HoursWorked=0;
    }
    else{
        HoursWorked=x;
    }
    return HoursWorked;    
} 
float  Employee::setHourlyRate(float x){
    if(HoursWorked>0||HoursWorked<200){
        HourlyRate=x;
    }
    else{
        cout<<"Unacceptable Hourly Rate\n";
        HourlyRate=0;
    }
    return HourlyRate;
} 
float  Employee::CalculatePay(float a,int b){
    return getNetPay(getGrossPay(setHourlyRate(HourlyRate),setHoursWorked(HoursWorked))); 
}