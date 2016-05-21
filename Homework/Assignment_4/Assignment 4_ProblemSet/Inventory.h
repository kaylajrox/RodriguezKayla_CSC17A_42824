/* 
 * File:   Inventory.h
 * Author: Kayla
 *
 * Created on April 24, 2016, 2:12 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
    private:
        int itemNumber;
        int quantity;
        float cost;
        float totalCost;
    public:
        Inventory();
        Inventory(const Inventory& orig);//
        void setItemNumber(int);
        void setQuantity(int);
        void setCost(float);
        void setTotalCost(int,float);
        int getQuantity()const;
        float getCost()const;
        float getTotalCost()const;
        int getItemNumber() const;
    };

#endif /* INVENTORY_H */


