/* File:   TeamLeader.cpp
 implementation file of TeamLeader Class */

#include "TeamLeader.h"

TeamLeader::TeamLeader() : ProductionWorker(){
}
void TeamLeader::setTrainR(int x){
    trnHrsR=x;
}
void TeamLeader::setTrainA(int x){
    trnHrsA=x;
}
void TeamLeader::setMonBon(float x){
    monBonus=x;
}
int TeamLeader::getTrainR(){
    return trnHrsR;
}
int TeamLeader::getTrainA(){
    return trnHrsA;
}
float TeamLeader::getMonBon(){
    return monBonus;
} 