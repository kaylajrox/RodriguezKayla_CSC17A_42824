
/* 
 * File:   Prob3Table.h
 * Author: Kayla
 *
 * Created on June 11, 2016, 2:09 AM
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H
#include <iostream>
#include <fstream>
#include <cstring>
template<class T>
class Prob3Table {
    protected:
        int rows;
        int cols;
        T *rowSum;
        T *colSum;
        T *table;
        T grandTotal;
        void calcTable(void);
    public:
        Prob3Table(char*,int,int);
        ~Prob3Table(){
            delete[] table;
            delete[] rowSum;
            delete[] colSum;
        }
        const T *getTable(void){
            return table;
        }
        const T *getRowSum(void){
            return rowSum;
        }
        const T *getGrandTotal(void){
            return grandTotal;
        }
};
template<class T>
Prob3Table<T>::Prob3Table(char* fleTxt,int r,int c){
    rows=r;
    cols=c;
    table=new T[rows*cols];
    rowSum=new T[rows];
    colSum=new T[cols];
    fstream in;
    in.open(fleTxt,ios::in);
    for(int i=0;i<(rows*cols);i++){
        in>>table[i];
    }
    
    in.close();
}
#endif /* PROB3TABLE_H */

