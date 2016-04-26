/* 
 * File:   main.cpp
 * Author: Kayla
 * Title: Personal Information Class
 * Problem: Gaddis_8thEd_Chap13_Prob4
 * Created on April 25, 2016, 8:33 PM
 */
//System Libraries
#include <iostream>
using namespace std;
//User Libraries
#include "PersonalInfo.h"

int main(int argc, char** argv) {
    //declare variables
    string name;
    string address;
    string number;
    int age;
    PersonalInfo pInfo;
    //input
    cout<<"Enter your name "<<endl;
    getline(cin,name);
    pInfo.setName(name);
    cout<<"Enter your address "<<endl;
    getline(cin,address);
    pInfo.setAdd(address);
    cout<<"Enter your number"<<endl;
    getline(cin,number);
    pInfo.setNum(number);
    cout<<"Enter your age "<<endl;
    cin>>age;
    pInfo.setAge(age);
    cout<<endl<<"Your information\n";
    cout<<"Name: "<<pInfo.getName()<<endl;
    cout<<"Address: "<<pInfo.getAdd()<<endl;
    cout<<"Number: "<<pInfo.getNum()<<endl;
    cout<<"Age: "<<pInfo.getAge()<<endl;
    return 0;
}

