/* 
 * File:   ComColor.h
 * Author: Kayla
 *
 * Created on April 30, 2016, 3:25 PM
 */

#ifndef COMCOLOR_H
#define COMCOLOR_H
#include "Color.h"
#include <string>
#include <fstream>
using namespace std;

class ComColor : public Color 
{
    protected:
        fstream out;
    public:
        ComColor() : Color(){}
        void lder();
        void markSrt(int*,int);
        void readLdr();
};

#endif /* COMCOLOR_H */
