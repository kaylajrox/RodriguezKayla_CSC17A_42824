/* File:   Color.h
 Base Color Class for User class and Computer class
 */

#ifndef COLOR_H
#define COLOR_H
#include <string>

using namespace std; 

class Color {
    private:
        int spot;
        string color;
    public:
        Color();
        void setColor(string);
        string getColor();
        void setSpot(int);
        int getSpot();
};

#endif /* COLOR_H */

