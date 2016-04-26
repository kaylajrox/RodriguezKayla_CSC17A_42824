/* 
 * File:   main.cpp
 * Author: Kayla
 *
 * Created on April 25, 2016, 10:46 PM
 */
//System Libraries
#include <bits/stdc++.h>

using namespace std;
//User Libraries
#include "RetailItem.h"
int main(int argc, char** argv) {
    //Declare and Set Variables
    RetailItem setItem1("Jacket", 12, 59.95);
    RetailItem setItem2("Designer Jeans", 40, 34.95);
    RetailItem setItem3("Shirt", 20, 24.95);
    //Output and Display the data
    cout<<"Item #1 "<<item1.getItem1_D()<<setw(2)<<item1.getItem1_U()<<setw(2);
    cout<<item1.getItem1_P;
    return 0;
}
  
