/* 
 * File:   ProductionWorker.h
 Specification File for Derived Class ProductionWorker
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H
#include "Employee.h"
class ProductionWorker : public Employee
{ 
    protected:
        int shift;
        float rate;
    public:
        ProductionWorker();
        void setShift(int);
        int getShift();
        void setRate(float);
        float getRate();
        class EmpClass{};
};

#endif	/* PRODUCTIONWORKER_H */
