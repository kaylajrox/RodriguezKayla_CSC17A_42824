/* 
 * File:   Inventory.h
 * Author: Kayla
 *
 * Created on April 24, 2016, 2:12 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
public:
    Inventory();
    Inventory(const Inventory& orig);//
    int setItemNumber(int);
    int setQuantity(int);
    float setCost(float);
    float setTotalCost();
    int getQuantity()const;
    float getCost()const;
    float getTotalCost()const;
    int getItemNumber() const;
private:
    int itemNumber;
    int quantity;
    float cost;
    float totalCost;

};

#endif /* INVENTORY_H */
