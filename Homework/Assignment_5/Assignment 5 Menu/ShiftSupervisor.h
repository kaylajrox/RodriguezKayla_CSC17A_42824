/* File:   ShiftSupervisor.h
 * Specification File of ShiftSupervisor Class*/

#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H
#include "Employee.h"
class ShiftSupervisor : public Employee{
    protected:
        float salary;
        float bonus;
    public:
        ShiftSupervisor();
        void setSalary(float);
        float getSalary();
        void setBonus(float);
        float getBonus();
};

#endif /* SHIFTSUPERVISOR_H */
