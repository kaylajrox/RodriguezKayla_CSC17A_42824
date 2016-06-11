/* 
 * Problem #3 Spreadsheet Stuff
 * Class Specifications Prob3Table
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

#include<iostream>
#include<fstream>
#include <iomanip>
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
    //set the variables
    grandTotal=0; 
    rows=rSum;
    cols=cSum; 
    
    //declare variables
    int cTtl=0;
    int rTtl=0;
    
    //allocate the space to add extra row and column
    table  = new T[rows*cols];
    rowSum = new T[rows];
    colSum = new T[cols];
    
    //opening the file and declaring file variable
    fstream in;
    in.open(fileTxt,ios::in);
    
    //read the table with a 2D array
    for(int i=0;i<(rows*cols);i++){
        in>>table[i];
    }
    //closing the file
    in.close();
    
    //Total Sum of Rows
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            rTtl+=table[i*cols+j];
        }
          rowSum[i]=rTtl;
    }
    //Total Sum of Columns
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            cTtl+=table[i*cols+j];
         
        }
        colSum[i]=cTtl;
    }    
    calcTable();
}  
template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char* txtFle, int rows, int cols):
Prob3Table<T>(txtFle,rows,cols){
    augTable=new T[(rows+1)*(cols+1)];
    for(int i=0;i<(rows+1);i++){
        for(int j=0; j<cols;j++){
            augTable[i*(cols+1)+j]=this->table[i*cols+j];
        }
        augTable[i*(cols+1)+cols]=this->rowSum[i];
    }
    for(int i=0;i<(rows+1);i++){
        for(int j=0; j<cols;j++){
            augTable[i*(cols+1)+j]=this->table[i*cols+j];
        }
        augTable[i*(cols+1)+cols]=this->rowSum[i];
    }

    
}
template<class T>
void Prob3Table<T>::calcTable(){
    int total=0;
    for(int i=0;i<rows;i++){
        total +=rowSum[i];
    }
    for(int i=0;i<rows;i++){
        total +=colSum[i];
    }
    grandTotal=total;
}
#endif /* PROB3TABLE_H */

