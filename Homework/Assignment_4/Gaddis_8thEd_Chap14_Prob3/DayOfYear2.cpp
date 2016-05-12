/* 
 * File:   DayOfYear2.cpp
 * Author: Kayla
 * 
 * Created on May 12, 2016, 2:34 PM
 */

#include "DayOfYear2.h"
#include <iostream>
using namespace std;
DayOfYear2::DayOfYear2() {
    day=0;
}
DayOfYear2::print(int x) {
   //leap year calculations
    if(x>=1&&x<=31)
        cout<<"January "<<x;
    if(x>31&&x<=59)
        cout<<"February "<<(x-31);
    if(x>59&&x<=90)
        cout<<"March "<<(x-60);
    if(x>90&&x<=120)
        cout<<"April "<<(x-91);
    if(x>120&&x<=151)
        cout<<"May "<<(x-121);
    if(x>151&&x<=181)
        cout<<"June "<<(x-152);
    if(x>181&&x<=212)
        cout<<"July "<<(x-182);
    if(x>212&&x<=243)
        cout<<"August "<<(x-213);
    if(x>243&&x<=273)
        cout<<"September "<<(x-244);
    if(x>273&&x<=304)
        cout<<"October "<<(x-274);
    if(x>304&&x<=334)
        cout<<"November "<<(x-305);
    if(x>334&&x<=365)
        cout<<"December "<<(x-335);
}
DayOfYear2::leapYear(int x){
     //leap year calculations
    if(x>=1&&x<=31)
        cout<<"January "<<x;
    if(x>31&&x<=60)
        cout<<"February "<<(x-31);
    if(x>60&&x<=91)
        cout<<"March "<<(x-60);
    if(x>91&&x<=121)
        cout<<"April "<<(x-91);
    if(x>121&&x<=152)
        cout<<"May "<<(x-121);
    if(x>152&&x<=182)
        cout<<"June "<<(x-152);
    if(x>182&&x<=213)
        cout<<"July "<<(x-182);
    if(x>213&&x<=244)
        cout<<"August "<<(x-213);
    if(x>244&&x<=274)
        cout<<"September "<<(x-244);
    if(x>274&&x<=305)
        cout<<"October "<<(x-274);
    if(x>305&&x<=335)
        cout<<"November "<<(x-305);
    if(x>335&&x<=366)
        cout<<"December "<<(x-335);
}