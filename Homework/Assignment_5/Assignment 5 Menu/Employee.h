/* 
 * File:   Employee.h
 * Base Class
 * Specification file
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <string>
class Employee {
    private:
        std::string name;
        std::string id;
        std::string hireDate;
    public:
        Employee();
        void setName(std::string);
        std::string getName();
        void setNum(std::string);
        std::string getNum();
        void setHireD(std::string);
        std::string getHirdD();
};
#endif	/* EMPLOYEE_H */

