


//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream> //File I/O
#include <iomanip> //Formatting
#include <vector>
using namespace std;

#include "ComColor.h"
void compic(ComColor[],string[]);
int main(int argc, char** argv) {
//Set the random number seed
srand(static_cast<unsigned int>(time(0)));
int SIZE=4;
string options[8]={"Red","Green","Blue","Brown","Black","Yellow","Orange","White"};
ComColor cColor[SIZE]; //Computer generated random pick    

compic(cColor,options);
for(int i=0;i<SIZE;i++){
    cout<<cColor[i].getColor()<<" ";
}
    return 0;
}
void compic(ComColor cColor[],string options[]){
    for(int j=0;j<4;j++){
        int index=rand()%8;
        cColor[j].setColor(options[index]);
    }
}
