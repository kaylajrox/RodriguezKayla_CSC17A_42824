/*User Libraries*/


#ifndef CIRCLE_H
#define CIRCLE_H
class Circle
{
    private:
        float radius;
    public:
        Circle();
        void setRadius(float number){
            radius=number;
        }
        float getRadius(){
            return radius;
        }
        float getArea(float radius,const float PI){
            getRadius();
            return PI*radius*radius;
        }
        float getDiameter(float radius){
            getRadius();
            return radius*2;
        }
        float getCircum(float radius,const float PI){
            getRadius();
            return 2*PI*radius;
        }   
};
#endif