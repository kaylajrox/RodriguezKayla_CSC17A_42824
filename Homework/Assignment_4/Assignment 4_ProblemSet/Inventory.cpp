#include "Inventory.h"
//default constructor
Inventory::Inventory() {
    itemNumber=0;
    quantity=0;
    cost=0;
    totalCost=0;
}
//copy constructor
Inventory::Inventory(const Inventory& orig) {
    itemNumber = orig.itemNumber;
    quantity = orig.quantity;
    cost = orig.cost;
    totalCost = orig.totalCost;   
}
float Inventory::getCost() const{
    return cost;
}
int Inventory::getItemNumber() const{
    return itemNumber;
}
int Inventory::getQuantity() const{
    return quantity;
}
float Inventory::getTotalCost() const{
    return totalCost;
}
void Inventory::setCost(float n){
    cost=n;
}
void Inventory::setItemNumber(int n){
    itemNumber=n; 
}
void Inventory::setQuantity(int n){
    quantity=n;
}
void Inventory::setTotalCost(int a,float b){
    quantity=a;
    cost=b;
    totalCost=a*b;
}