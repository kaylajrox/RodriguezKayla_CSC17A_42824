/* 
 * File:   ComMge.h
 * Author: Kayla
 *
 * Created on June 1, 2016, 12:39 AM
 */

#ifndef COMMGE_H
#define COMMGE_H

template <class T>
class ComMge {
 private:
        T message;
    public:
        ComMge(T a){
            message=a;
        }
        T prntMge()const{
            return message;
        }
};

#endif /* COMMGE_H */

