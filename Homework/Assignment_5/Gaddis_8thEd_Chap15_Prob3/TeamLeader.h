/* File:   TeamLeader.h
 * specification file of TeamLeader Class */

#ifndef TEAMLEADER_H
#define TEAMLEADER_H
#include "ProductionWorker.h"
class TeamLeader : public ProductionWorker{
    private:
        int trnHrsR; 
        int trnHrsA;
        float monBonus;
    public:
        TeamLeader();
        void setTrainR(int);
        void setTrainA(int);
        void setMonBon(float);
        int getTrainR();
        int getTrainA();
        float getMonBon();       
};

#endif /* TEAMLEADER_H */

