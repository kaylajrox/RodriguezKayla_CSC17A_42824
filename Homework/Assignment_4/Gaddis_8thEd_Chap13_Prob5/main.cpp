/* 
 * File:   main.cpp
 * Author: Kayla
 * Title: RetailItem Class
 * Problem: Gaddis_8thEd_Chap13_Prob5_V1
 * Done without arrays need to fix the default array
 * Created on April 25, 2016, 10:46 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//User Libraries
#include "RetailItem.h"
int main(int argc, char** argv) {
    //Declare and Set Variables
    RetailItem item1;
    RetailItem item2;
    RetailItem item3;
    RetailItem item[3];
    
    item1.setItem1("Jacket", 12, 59.95);
    item2.setItem2("Designer Jeans", 40, 34.95);
    item3.setItem3("Shirt", 20, 24.95);
    //Output and Display the data
    cout<<"          "<<"Description\t\t"<<"Units On Hand\t"<<"Price"<<endl;
    cout<<"Item #1   "<<item1.getItem1_D()<<"\t\t"<<item1.getItem1_U()<<"\t\t";
    cout<<item1.getItem1_P();
    cout<<"\nItem #2   "<<item2.getItem2_D()<<"\t"<<item2.getItem2_U()<<"\t\t";
    cout<<item2.getItem2_P();
    cout<<"\nItem #3   "<<item3.getItem3_D()<<"\t\t\t"<<item3.getItem3_U()<<"\t\t";
    cout<<item3.getItem3_P();
    return 0;
}
  
