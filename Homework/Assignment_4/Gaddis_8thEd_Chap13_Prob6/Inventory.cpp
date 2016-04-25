#include "Inventory.h"

Inventory::Inventory() {
    itemNumber=0;
    quantity=0;
    cost=0;
    totalCost=0;
}

Inventory::Inventory(const Inventory& orig) {
    setTotalCost();
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
float Inventory::setCost(float n){
    cost=n;
    return n;
}
int Inventory::setItemNumber(int n){
    itemNumber=n; 
    return n;
}
int Inventory::setQuantity(int n){
    quantity=n;
    return n;
}
float Inventory::setTotalCost(){
    totalCost=quantity*cost;
    return totalCost;
}