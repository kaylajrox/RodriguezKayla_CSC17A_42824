/* 
 * File:   PersonalInfo.h
 * Author: Kayla
 *
 * Created on April 25, 2016, 8:35 PM
 */

#ifndef PERSONALINFO_H
#define PERSONALINFO_H
#include <string>
using namespace std;
class PersonalInfo {
private:
    string name;
    string address;
    int age;
    string num;
public:
    PersonalInfo();
    void setName(string);
    void setAdd(string);
    void setNum(string);
    void setAge(int);
    string getName();
    string getAdd();
    string getNum();
    int getAge();
};

#endif /* PERSONALINFO_H */

