
/* 
 * File:   RetailItem.h
 * Author: Kayla
 *
 * Created on April 25, 2016, 10:47 PM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H
#include <iostream>
using namespace std;

class RetailItem {
private:
    string descrptn1; 
    int unitsOnHand1;
    float price1;
    string descrptn2; 
    int unitsOnHand2;
    float price2;
    string descrptn3; 
    int unitsOnHand3;
    float price3;
public:
  //  RetailItem(string descrptn,int unitsOnHand,float price);  
    RetailItem();
    void setItem1(string,int,float);
    void setItem2(string,int,float);
    void setItem3(string,int,float);
    string getItem1_D();
    int getItem1_U();
    float getItem1_P();
    string getItem2_D();
    int getItem2_U();
    float getItem2_P();
    string getItem3_D();
    int getItem3_U();
    float getItem3_P();
};
#endif /* RETAILITEM_H */

