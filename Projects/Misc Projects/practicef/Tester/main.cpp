/* 
 * File:   main.cpp
 * Author: Kayla
 *
 * Created on June 11, 2016, 2:41 AM
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char** argv) {
    fstream in;
    char* fleTxt;
    fleTxt=new char[11];
    fleTxt="numbers.txt";
    in.open(fleTxt,ios::in);
    
    int table[30];
    int cols=6;
    int rows=5;
    for(int i=0;i<(rows*cols);i++){
        in>>table[i];
    }
    
    for(int j=0;j<rows;j++){
        for (int i=0; i<cols; i++) {
            cout << table[j*cols+i] << " ";
	}
        cout<<endl;
    }
    delete[]fleTxt;
    in.close();
    return 0;
}

