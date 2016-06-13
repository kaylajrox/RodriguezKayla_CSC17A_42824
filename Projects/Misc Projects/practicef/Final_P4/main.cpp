/*Problem 4*/
//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "SavingsAccount.h"

//Execution Begins Here
int main(int argc, char** argv) {
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.TotalRecursive((float)(0.10),7)
            <<" Recursive Calculation "<<endl;
    return 0;
}

