/* 
 * File:   AbsValue.h
 * Author: Kayla
 *
 * Created on May 30, 2016, 9:49 PM
 */

template <class T>
#ifndef ABSVALUE_H
#define ABSVALUE_H

class AbsValue {
    private:
        T abs;
    public:
        void setAbs(T a){
            abs=a;
        }
        T getAbs(){
            return abs;
        }
        T findAbs(){
            if(abs<0){
                return -abs;
            }else{
                getAbs();
            }
        }
};

#endif /* ABSVALUE_H */

