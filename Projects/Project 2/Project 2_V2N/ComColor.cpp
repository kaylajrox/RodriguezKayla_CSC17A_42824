/* 
 * File:   ComColor.cpp
 * Author: Kayla
 * 
 * Created on April 30, 2016, 3:25 PM
 */

#include "ComColor.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
//ComColor::ComColor(){
//    
//}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                         Leader board Function  
 * This function should read in the contents of the leader file and sort them
 * and then output the leader board with the new name on it                   */
/******************************************************************************/
void ComColor::lder(){
    char *name;
    string n; 
    for (int i=0;i<strlen(name);i++){
        cout<<"Please enter a username to be put onto the Leader board "<<endl;
        cin>>name[i];
    }
//        leader>>name[i];
//    }cout<<"Top Ten on the Leader board "<<endl;
//    for(int i=0;i<n.length();i++){
//        leader>>n[i];
//    }
//    if( leader ){
//        getline( leader, n );
//        while( leader ){
//            cout << n << endl;
//            getline( leader, n );
//        }
//    }   
//    for (int i=0;i<strlen(name);i++){
//        cout<<name[i]<<endl;
//    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Sort the Array
//Inputs
//     n->Size of the array
//     a->Array
//Output
//     a->The sorted array
////////////////////////////////////////////////////////////////////////////////
void ComColor::markSrt(int *a,int n){
    for(int pos=0;pos<n-1;pos++){
        for(int row=pos+1;row<n;row++){
            if(*(a+pos)>*(a+row)){
                *(a+pos)=*(a+pos)^*(a+row);
                a[row]=a[pos]^a[row];
                *(a+pos)=*(a+pos)^*(a+row);
            }
        }
    }
}