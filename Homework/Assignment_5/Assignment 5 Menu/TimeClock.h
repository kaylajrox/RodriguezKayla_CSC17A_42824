/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeClock.h
 * Author: Kayla
 *
 * Created on June 2, 2016, 10:29 AM
 */

#ifndef TIMECLOCK_H
#define TIMECLOCK_H

template < class T> //define template

class TimeClock{ //templates with inheritance 
    private:
        T strTime; //starting time
        T endTime; //end time
        T milHour; 
        T  milSec1;
        T milSec2;
    public:
        TimeClock()
            {strTime=0; endTime=0;}
        void setTimeC1(T x) {  
            strTime=x;
        }   
        void setTimeC2(T a){
            endTime=a;
            //endTime=s;
        }
        T getElapse(){
                {return (endTime-strTime)/100;}
        } 
        void setTime(T h,T s, T s2){
            milHour=h;
            milSec1=s;
            milSec2 =s2;
        }
        int getHour() const{
            return milHour;
        }
        
        T bigger(){
            if(milSec1>milSec2)
                return milSec1;
            else 
                return milSec2;
        }
            
};
#endif /* TIMECLOCK_H */

