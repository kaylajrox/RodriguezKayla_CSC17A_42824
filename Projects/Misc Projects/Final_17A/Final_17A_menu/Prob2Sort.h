
/* 
 * File:   Prob2Sort.h
 * Author: Kayla
 *
 * Created on June 11, 2016, 6:32 PM
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H
#include <fstream>
using namespace std;
template<class T>
class Prob2Sort
{
    private:
        int *index;               //Index that is utilized in the sort
    public:
        Prob2Sort(){index=0;};                   //Constructor
        ~Prob2Sort(){delete []index;};              //Destructor
//        T * sortArray(const T*,int,bool);           //Sorts a single column array
        T * sortArray( T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 
//template<class T>
//T *Prob2Sort<T>::sortArray(const T* names, int size, bool a){
//    //allocate the memory
//    T *index=new T[size];
//    
//    //declare variables
//    T temp; //temporary memory
//    bool swap; //signifies swapping has been made
//    //set the index array
//    for(int i=0;i<size;i++){
//        index[i]=names[i];
//    }
//    while(swap==true){
//        for(int i=0;i<size-1;i++){
//            for(int j=i+1;j<size;j++){
//                if(a==true){//ascending order is true
//                    //swap
//                    if(index[i]>index[j]){
//                        temp=index[j];
//                        index[j]=index[i];
//                        index[i]=temp;//XOR
//                        swap=true;
//                    }
//                }else{
//                     if(index[i]<index[j]){
//                        temp=index[j];
//                        index[j]=index[i];
//                        index[i]=temp;//XOR
//                        swap=true;
//                    }
//                }
//            }
//        }
//    }
//    return index;
//}
template<class T>
T *Prob2Sort<T>::sortArray( T* names,int row,int col,int column,bool a){
    //allocate the memory
    T *index=new T[row];
    
    //declare variables
    T temp; //temporary memory
    bool swap; //signifies swapping has been made
    //set the index array
    for(int i=0;i<row;i++){
        index[i]=names[i];
    }
    --col;
    do{
        swap=false;
        for(int i=0;i<row-1;i++){
           if(a==true){
               if(index[i*col+column]>index[(i+1)*col+column]){
                   swap=true;
               }for(int j=i+1;j<col;j++){
                //swap
                    temp=index[i*col+j];
                    index[i*col+j]=index[(i+1)*col+j];
                    index[(i+1)*col+j]=temp;//XOR
                    swap=true;
               }
            }else{
                if(index[i*col+column]>index[(i+1)*col+column]){
                    swap=true;
                    for(int j=0;j<col;j++){
                        temp=index[i*col+j];
                        index[i*col+j]=index[(i+1)*col+j];
                        index[(i+1)*col+j]=temp;//XOR
                    }
                }
            }
        }
    }while(swap==true);
    return index;
}
#endif /* PROB2SORT_H */

