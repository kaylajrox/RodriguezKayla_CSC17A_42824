/* 
 * Problem #3 Spreadsheet Stuff
 * Class Specifications Prob3Table
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

template<class T>
class Prob3Table
{
    protected:
        int rows;                   //Number of rows
        int cols;                   //Number of cols in the table
        T *rowSum;                  //RowSum array
        T *colSum;                  //ColSum array
        T *table;                   //Table array
        T grandTotal;               //Grand total
        void calcTable(void);       //Calculate all the sums
    public:
        Prob3Table(char *,int,int); //Constructor then Destructor
        ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
        const T *getTable(void){return table;};
        const T *getRowSum(void){return rowSum;};
        const T *getColSum(void){return colSum;};
        T getGrandTotal(void){return grandTotal;};
};
template<class T>
Prob3Table::Prob3Table(char *,int,int){
    
}

#endif /* PROB3TABLE_H */

