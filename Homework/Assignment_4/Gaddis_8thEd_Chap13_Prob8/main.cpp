/* 
 * Author: Kayla
 * Created on April 23, 2016, 4:39 PM
 * Title: Circle Class 
 * Gaddis_8thEd_Chap13_Prob8
 */
/*Problems/concerns: what are the uses of the .cpp file? All I put was the 
 initialization..*/
//System Libraries
#include <iostream>
using namespace std;
//User Libraries
#include "newClass.h"
//Global Constants
const float PI=3.1415926;

int main(int argc, char** argv) {
    float rad;
    Circle info;
    //input 
    cout<<"Input the radius"<<endl;
    cin>>rad;
    info.setRadius(rad);
    cout<<"Circle Information\n";
    cout<<"Area: "<<info.getArea(rad,PI)<<endl;
    cout<<"Diameter: "<<info.getDiameter(rad)<<endl;
    cout<<"Circumference: "<<info.getCircum(rad,PI)<<endl;
   
    return 0;
}

