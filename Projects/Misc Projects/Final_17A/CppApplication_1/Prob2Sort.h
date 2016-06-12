/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
        Prob2Sort(){index=NULL;};                   //Constructor
        ~Prob2Sort(){delete []index;};              //Destructor
        T * sortArray(const T*,int,bool);           //Sorts a single column array
        T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 
template<class T>
T *Prob2Sort<T>::sortArray(const T *lt,int wrd,int clm,int usCol,bool asd){
    cout << "Descending order sort of column: " << usCol <<endl<<endl;
    int tot=wrd*clm;//use as single variable
  T *newAr = new T[tot];//this will be the sorted array that will be sent back
  for(int i=0;i<tot;i++){
    newAr[i]=lt[i];//copy information into new pointer
  }
 
  usCol-=1;
  bool swtch;
  T temp;
  do{
    swtch=false; //set bool to false, if doesn't enter either if statement loop ends
    for(int i=0;i<wrd-1;i++){
      if(asd==true){
        if(newAr[i*clm+usCol]<newAr[(i+1)*clm+usCol]){
          swtch=true;//set switch bool to true
          for(int j=0;j<clm;j++){
            temp=newAr[i*clm+j];//store value
            newAr[i*clm+j]=newAr[(i+1)*clm+j];//switches the location letters is stored in
            newAr[(i+1)*clm+j]=temp;// puts stored value in remaining location
          }
        }
     }
      else{
        if(newAr[i*clm+usCol]>newAr[(i+1)*clm+usCol]){
          swtch=true;//set swich bool to true
          for(int j=0;j<clm;j++){
            temp=newAr[i*clm+j];//stores value
            newAr[i*clm+j]=newAr[(i+1)*clm+j];//switches the location letters is stored in
            newAr[(i+1)*clm+j]=temp;// puts stored value in remaining location
          }
        }
      }
    }
  }while(swtch==true);
  return newAr;
}
#endif /* PROB2SORT_H */

