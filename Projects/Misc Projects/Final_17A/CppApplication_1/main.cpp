/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3Table.h
 * Author: chrystallahavadjia
 *
 * Created on June 8, 2016, 3:33 PM
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class Prob3Table
{
    protected:
        int rows;                                 //Number of rows in the table
        int cols;                                 //Number of cols in the table
        T *rowSum;                                //RowSum array
        T *colSum;                                //ColSum array
        T *table;                                 //Table array
        T grandTotal;                             //Grand total
        void calcTable(void);                     //Calculate all the sums
    public:
        Prob3Table(char *,int,int);               //Constructor then Destructor
        ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
        const T *getTable(void){return table;};
        const T *getRowSum(void){return rowSum;};
        const T *getColSum(void){return colSum;};
        T getGrandTotal(void){return grandTotal;};
};

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
Prob3Table<T>::Prob3Table(char* fileTxt, int rSum, int cSum){
    grandTotal=0; 
    rows=rSum;
    cols=cSum;  
    //dynamic allocation of pointers
    table = new T[rows*cols];
    rowSum = new T[rows];
    colSum = new T[cols];
    ifstream infile;
    infile.open(fileTxt, ios::in);//open file
    int i=0;
    for(int i=0;i<30;i++){
        infile>>table[i];//copy file information into table pointer
    }        
    infile.close();//close file
    
    //calculate row sum
    int rTot=0;
    for(int k=0;k<rows;k++){
        for(int j=0;j<cols;j++){
            rTot+=table[k*cols+j];
        }
        rowSum[k]=rTot;//sum row and save it in row sum of row j
        rTot=0;
    }
    //calculate cols sum
    int cTot=0;
    for(int j=0;j<cols;j++){
        for(int k=0;k<rows;k++){
            cTot+=table[k*cols+j]; 
        }
        colSum[j]=cTot; //sum colum and save it in colum sum of row j
        cTot=0;
    } 
    calcTable();
}
template<class T>
void Prob3Table<T>::calcTable(){
    for(int i=0;i<rows;i++){
        grandTotal +=rowSum[i];//sum up all rowSums
    }
    for(int k=0;k<cols;k++){
        grandTotal +=colSum[k];//sum up all colSums
    } 
    grandTotal = grandTotal/2;//all numbers where counted twice, once from colum once 
                            //from row therefore take half of result
}
template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char* fle, int rows, int cols):Prob3Table<T>(fle,rows,cols){
    augTable = new T[(rows+1)*(cols+1)];//dynamically allocate pointer
    for(int i=0;i<(rows+1)*(cols+1);i++){
        for(int k=0; k<cols;k++){
            augTable[i*(cols+1)+k]=this->table[i*cols+k];
        }
        for(int k=0; k<rows;k++){//save sum row in augTable variable
            augTable[(cols)*k+(k+cols)]=this->rowSum[k];
        }
        for(int k=0; k<cols;k++){//save column sum in augTable variable
            augTable[35+k]=this->colSum[k];
        }
        augTable[41]=this->grandTotal;  //save grand total in augTable variable
        for(int k=0; k<cols;k++){
        }
    }
}
#endif /* PROB3TABLE_H */