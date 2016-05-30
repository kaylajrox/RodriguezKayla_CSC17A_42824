/* File:   Color.h
 Base Color Class for User class and Computer class
 */

#ifndef COLOR_H
#define COLOR_H
#include <string>
class Color {
    protected:
        int spot;
        std::string color;
    public:
        Color();
        void setColor(std::string);
        std::string getColor();
        void setSpot(int);
        int getSpot();
};

#endif /* COLOR_H */

