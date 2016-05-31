/* File:   ProductionWorker.cpp
 Implementation file of Production Worker Class
 */

#include "ProductionWorker.h"
//constructor
ProductionWorker::ProductionWorker() : Employee() {
    shift=0;
    rate=0;
}
//mutator functions
void ProductionWorker::setShift(int x){
    if(shift==1||shift==2){
        shift=x;
    }else{
        throw EmpClass();
    }
}
int ProductionWorker::getShift(){
    return shift;
}
void ProductionWorker::setRate(float x){
    rate=x;
}
float ProductionWorker::getRate(){
    return rate;
}


