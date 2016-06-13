/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3TableInherited.h
 * Author: Kayla
 *
 * Created on June 11, 2016, 2:10 AM
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H
#include "Prob3Table.h"
template <class T>
class Prob3TableInherited:public Prob3Table<T>{
    protected:
        T *augTable;         //Augmented Table with sums                         
    public:
        //this constructor will set the other table equal to this new table
        Prob3TableInherited(char *,int,int); 
        ~Prob3TableInherited(){delete [] augTable;};  //Destructor
        const T *getAugTable(void){return augTable;}; 
};
//template<class T>
//Prob3TableInherited<T>::Prob3TableInherited(char* fleTxt, int r, int c){
//    augTable=new T[(rows+1)*(cols+1)];
//}
#endif /* PROB3TABLEINHERITED_H */

