/* File:   Color.h
 Base Color Class for User class and Computer class
 */

#ifndef COLOR_H
#define COLOR_H
#include <string>

using namespace std; 

class Color {
    protected:
        int spot;
        string color;
        static const int SIZE=8;
        static string options[SIZE];
    public:
        Color();
        void setColor(string);
        string getColor();
        void setSpot(int);
        int getSpot();
        class EmpClass{};
};

#endif /* COLOR_H */

