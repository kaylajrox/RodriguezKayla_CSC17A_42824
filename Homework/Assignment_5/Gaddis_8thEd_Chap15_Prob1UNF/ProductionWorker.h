/* 
 * File:   ProductionWorker.h
 Specification File for Derived Class ProductionWorker
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H

class ProductionWorker : public Employee{ //something wrong with this declaration of class
    protected:
        int shift;
        float rate;
    public:
        ProductionWorker() : Employee();
        void setShift(int);
        int getShift();
        void setRate(float);
        float getRate();
};

#endif	/* PRODUCTIONWORKER_H */

