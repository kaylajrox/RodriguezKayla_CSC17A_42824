/* 
 * File:   Prob3TableInherited.h
 * Author: Kayla
 *
 * Created on June 11, 2016, 4:19 AM
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H
#include "Prob3Table.h"
template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
    protected:
            T *augTable;                                  //Augmented Table with sums
    public:
            Prob3TableInherited(char *,int,int);          //Constructor
            ~Prob3TableInherited(){delete [] augTable;};  //Destructor
            const T *getAugTable(void){return augTable;}; 
};
template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char* txtFle, int rows, int cols):
Prob3Table<T>(txtFle,rows,cols){
    augTable=new T[(rows+1)*(cols+1)];
    for(int i=0;i<rows;i++){
        for(int j=0; j<cols;j++){
            augTable[i*(cols+1)+j]=this->table[i*cols+j];
        }
        augTable[i*(cols+1)+cols]=this->rowSum[i];
    }
    for(int i=0;i<cols;i++){
        augTable[rows*(cols+1)+i]=this->colSum[i];
    }
  augTable[rows*(cols+1)+cols]=this->grandTotal;
}

#endif /* PROB3TABLEINHERITED_H */

