
///* 
// * File:   Prob2Sort.h
// * Author: Kayla
// *
// * Created on June 11, 2016, 6:32 PM
// */
//
//#ifndef PROB2SORT_H
//#define PROB2SORT_H
//#include <fstream>
//using namespace std;
//template<class T>
//class Prob2Sort
//{
//    private:
//        int *index;               //Index that is utilized in the sort
//    public:
//        Prob2Sort(){index=0;};                   //Constructor
//        ~Prob2Sort(){delete []index;};              //Destructor
//        T * sortArray(const T*,int,bool);           //Sorts a single column array
//        T * sortArray( const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
//}; 
//
//
//template<class T>
//T *Prob2Sort<T>::sortArray( T* names,int row,int col,int column,bool a){
//    //allocate the memory
//    T *index=new T[row*col];
//    
//    //declare variables
//    T temp; //temporary memory
//    bool swap; //signifies swapping has been made
//    //set the index array
//    for(int i=0;i<(row*col);i++){
//        index[i]=names[i];
//    }
//    col--;
//    do{
//        swap=false;
//        for(int i=0;i<row-1;i++){
//           if(a==true){
//               if(index[i*col+column]>index[(i+1)*col+column]){
//                   swap=true;
//               }for(int j=i+1;j<col;j++){
//                //swap
//                    temp=index[i*col+j];
//                    index[i*col+j]=index[(i+1)*col+j];
//                    index[(i+1)*col+j]=temp;//XOR
//                    
//               }
//            }else{
//                if(index[i*col+column]>index[(i+1)*col+column]){
//                    swap=true;
//                    for(int j=0;j<col;j++){
//                        temp=index[i*col+j];
//                        index[i*col+j]=index[(i+1)*col+j];
//                        index[(i+1)*col+j]=temp;//XOR
//                    }
//                }
//            }
//        }
//    }while(swap==true);
//    return index;
//}
//
//#endif /* PROB2SORT_H */

/* 
 * File:   Prob2Sort.h
 * Author: chrystallahavadjia
 *
 * Created on June 7, 2016, 10:55 PM
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H

#include<iostream>
using namespace std;

template<class T>
class Prob2Sort
{
    private:
        int *index;                                 //Index that is utilized in the sort
    public:
        Prob2Sort(){index=0;};                   //Constructor
        ~Prob2Sort(){delete []index;};              //Destructor
        T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 
template<class T>
T *Prob2Sort<T>::sortArray( const T *names,int row,int col,int column,bool a){
    //allocate the memory
    T *index = new T[row*col];
    
    //declare variables
    bool swap;
    T temp;
    
    //set the index array
    for(int i=0;i<row*col;i++){
        index[i]=names[i];
    }
   
    //decrement the column picked
    --column;
    
    //swaping do while swap has been done 
    do{
        swap=false; 
        for(int i=0;i<row-1;i++){
            if(a==true){
                if(index[i*col+column]<index[(i+1)*col+column]){
                    swap=true;
                    for(int j=0;j<col;j++){
                        //swap
                        temp=index[i*col+j];
                        index[i*col+j]=index[(i+1)*col+j];
                        index[(i+1)*col+j]=temp;
                    }
                }
            }
        else{
            if(index[i*col+column]>index[(i+1)*col+column]){
                swap=true;
                for(int j=0;j<col;j++){
                    //swap
                    temp=index[i*col+j];
                    index[i*col+j]=index[(i+1)*col+j];
                    index[(i+1)*col+j]=temp;
                    }
                }
            }
        }
    }while(swap==true);
  return index;
}
#endif /* PROB2SORT_H */
//
