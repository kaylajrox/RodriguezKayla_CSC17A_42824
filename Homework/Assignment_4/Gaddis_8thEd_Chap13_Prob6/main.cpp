/* 
 * File:   main.cpp
 * Author: Kayla
 * Title: Inventory Class
 * Gaddis_8thEd_Chap13_Prob6
 * Created on April 24, 2016, 2:09 PM
 */
#include <iostream>
#include <iomanip>
#include "Inventory.h"
using namespace std;

int main(int argc, char** argv) {
    //declare variables
    int itmNum; //item number
    int quantity; //quantity of item
    float cost; //cost of item
    Inventory itemInfo;
    cout<<fixed<<setprecision(2);
    //input
    do{
        cout<<"What is the item number?"<<endl;
        cin>>itmNum;
    }while(itmNum<0);
    itemInfo.setItemNumber(itmNum);
    do{
        cout<<"What is the quantity of the item purchased?\n";
        cin>>quantity;
    }while(quantity<0);
    itemInfo.setQuantity(quantity);
    do{
        cout<<"What is the cost of the item?\n";
        cin>>cost;
    }while(cost<0);
    itemInfo.setCost(cost);
    itemInfo.setTotalCost(quantity,cost);
    cout<<"Item Information\n";
    cout<<"Item Number: "<<itemInfo.getItemNumber()<<endl;
    cout<<"Quantity: "<<itemInfo.getQuantity()<<endl;
    cout<<"Cost: $"<<itemInfo.getCost()<<endl;
    cout<<"Total Cost: $"<<itemInfo.getTotalCost()<<endl;
    
    return 0;
}

