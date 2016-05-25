/* File:   ProductionWorker.cpp
 Implementation file of Production Worker Class
 */

#include "ProductionWorker.h"
//constructor
ProductionWorker::ProductionWorker() : Employee() {
    
}
//mutator functions
void ProductionWorker::setShift(int x){
    shift=x;
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

