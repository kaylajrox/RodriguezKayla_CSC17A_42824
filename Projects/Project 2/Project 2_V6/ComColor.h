/* 
 * File:   ComColor.h
 * Author: Kayla
 *
 * Created on April 30, 2016, 3:25 PM
 */
/*Template class that will print game over */

#ifndef COMCOLOR_H
#define COMCOLOR_H
#include "Color.h"

class ComColor : public Color 
{
    private:
        string name; //the user name
        int games; //number of games played
        int win; //number of times the user has won
        int lose; //number of times that the user has lost
    public:
        ComColor();
        void setName(string);
        void setGames(int);
        void setWin(int);
        void setLose(int);
        int getGames();
        int getWin();
        int getLose();
};

#endif /* COMCOLOR_H */
