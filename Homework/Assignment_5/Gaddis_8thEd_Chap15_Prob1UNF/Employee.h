/* 
 * File:   Employee.h
 * Author: rcc
 *
 * Created on May 23, 2016, 2:40 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <string>
class Employee {
    protected:
        std::string name;
        int id;
        std::string hireDate;
    public:
        Employee();
        void setName(std::string);
        std::string getName();
        void setNum(int);
        int getNum();
        void setHireD(std::string);
        std::string getHirdD();
};
class ProductionWorker:public Employee{
private:
public:
};
#endif	/* EMPLOYEE_H */

