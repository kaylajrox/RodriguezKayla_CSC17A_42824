/* 
 * File:   Mastermind_Mge.h
 * Author: rcc
 * Created on June 1, 2016, 1:25 PM
 */

#ifndef MASTERMIND_MGE_H
#define	MASTERMIND_MGE_H

template <class T>
class Mastermind_Mge {
    private:
        T message;
    public:
        Mastermind_Mge(T a){
            message=a;
        }
        T prntMge()const{
            return message;
        }
};

#endif	/* MASTERMIND_MGE_H */

