/* 
 * Problem #3 Spreadsheet Stuff
 * Class Specifications Prob3Table
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H

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


#endif /* PROB3TABLEINHERITED_H */

