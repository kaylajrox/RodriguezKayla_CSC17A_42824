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
    public:
        ComColor();
        void lder();
        void markSrt(int*,int);
        
};

#endif /* COMCOLOR_H */
