/* 
 * File:   Prob3Table.h
 * Author: heidy
 * Created on June 9, 2016, 7:40 PM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

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
            T getGrandTotal(){return grandTotal;};
};

template<class T>
Prob3Table<T>::Prob3Table(char *text, int row, int col){
    
    fstream in;
    rows=row;
    cols=col;
    table=new T[rows*cols];
    rowSum=new T[rows];
    colSum=new T[cols];
    int rsum=0;        
    int csum=0;
    int add=0;
    int i=0;
    
    in.open(text, ios::in);
    while(in>>table[i])
    {
        i++;
    }
    
    in.close();
    
    //sum of the rows
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            rsum+=table[j];
        }
        rowSum[i]=rsum;
    }
    
    //sum of the columns
    for(int k=0;k<cols;k++)
    {
        for(int l=0;l<rows;l++)
        {
            csum+=table[l];
        }
        colSum[k]=csum;
    }
    
    //Sum of the total
    for(int i=0;i<cols*rows;i++)
    {
        add+=table[i];
    }
    grandTotal=add;
}
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

template <class T>
Prob3TableInherited<T>::Prob3TableInherited(char* text, int rows, int cols):Prob3Table<T>(text, rows, cols){
  augTable = new T[(rows+1)*(cols+1)];
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      augTable[i*(cols+1)+j]=this->table[i*cols+j];
    }
    augTable[i*(cols+1)+cols]=this->rowSum[i];
  }
  for(int i=0;i<cols;i++){
    augTable[rows*(cols+1)+i]=this->colSum[i];
  }
  augTable[rows*(cols+1)+cols]=this->grandTotal;
}

#endif /* PROB3TABLE_H */