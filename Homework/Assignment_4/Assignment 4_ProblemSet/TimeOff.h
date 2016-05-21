/* 
 * File:   TimeOff.h
 * Author: Kayla Rodriguez
 * Created on May 19, 2016, 5:53 PM
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H
#include <string>
class TimeOff {
    private:
        int mxSickDays;
        int sickTaken;
        int mxVacation;
        int vacTaken;
        int mxUnpaid;
        int unpaidTaken;
        std::string name;
        int id;
        int hours;
    public:
        TimeOff();
        void setHours(int);
        int getHours();
        float getDays();
        void setMxSickDays(int);
        int getMxSickDays();
        void setSickDays(int);
        int getSickDays();
        void setMxVacDays(int);
        int getMxVacDays();
        void setVacDays(int);
        int getVacDays();
        void setMxUnpaid(int);
        int getMxUnpaid();
        void setUnpaid(int);
        int getUnpaid();
        void setName(std::string x);
        std::string getName();
        void setId(int);
        int getId();
};

#endif /* TIMEOFF_H */


