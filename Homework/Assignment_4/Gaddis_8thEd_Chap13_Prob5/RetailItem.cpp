/* 
 * File:   RetailItem.cpp
 * Author: Kayla
 * 
 * Created on April 25, 2016, 10:47 PM
 */

#include "RetailItem.h"
#include <string>
using namespace std;
RetailItem::RetailItem() {
    descrptn1=""; 
    unitsOnHand1=0;
    price1=0.0;
    descrptn2=""; 
    unitsOnHand2=0;
    price2=0.0;
    descrptn3=""; 
    unitsOnHand3=0;
    price3=0.0;
}
void RetailItem::setItem1(string a, int b, float c){
    descrptn1=a;
    unitsOnHand1=b;
    price1=c;
}
void RetailItem::setItem2(string a, int b, float c){
    descrptn2=a;
    unitsOnHand2=b;
    price2=c;
}
void RetailItem::setItem3(string a, int b, float c){
    descrptn3=a;
    unitsOnHand3=b;
    price3=c;
}
string RetailItem::getItem1_D(){
    return descrptn1;
}
int RetailItem::getItem1_U(){
    return unitsOnHand1;
}
float RetailItem::getItem1_P(){
    return price1;
}
string RetailItem::getItem2_D(){
    return descrptn2;
}
int RetailItem::getItem2_U(){
    return unitsOnHand2;
}
float RetailItem::getItem2_P(){
    return price2;
}
string RetailItem::getItem3_D(){
    return descrptn3;
}
int RetailItem::getItem3_U(){
    return unitsOnHand3;
}
float RetailItem::getItem3_P(){
    return price3;
}

