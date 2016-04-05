/*
 * Author: Kayla Rodriguez
 * Title: Array/File Functions
 * Problem: Gaddis_8thEd_Chap12_Prob8
 *
    Problem 8:
   Write a function named  arrayToFile . The function should accept three
   arguments: the name of a file, a pointer to an  int  array, and the size of 
   the array. The function should open the specified file in binary mode, write
   the contents of the array to the file, and then close the file.  
   Write another function named  fileToArray . This function should accept 
   three arguments: the name of a file, a pointer to an  int  array, and the 
   size of the array. The function should open the specified file in binary mode,
   read its contents into the array, and then close the file.  Write a complete
   program that demonstrates these functions by using the  arrayToFile  
   function to write an array to a file, and then using the  fileToArray  
   function to read the data from the same file. After the data are read from 
   the file into the array, display the array’s contents on the screen.   
 */
/*Need to better utilize binary files, compiles but not sure if this is what
 the problem is asking for*/

//System Libraries
#include <bits/stdc++.h>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void fileToArray(ifstream&,const int,int *);
void arrayToFile(ofstream&,int *,const int);
void prntary(ofstream&,int *,const int);
//Execution Begins Here
int main(int argc, char** argv){
    //Declare Variables
    const int SIZE=7;//size of array
    ifstream infile; //input infile
    ofstream out;    //output file
    int array[SIZE];
    //Open the files
    infile.open("arrayInput.txt",ios::binary);
//trying to resolve problem so it includes spaces not sure if this is important
    //for program
    //   infile.read(&array,sizeof(array)); 
    out.open("fileToArray.txt");
    //Read the files
    fileToArray(infile,SIZE,array);
  //  getline(infile,array);
    //print the contents of the array
    prntary(out,array,SIZE);
    //close the files
    infile.close();
    out.close();
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                            Array to File                                   */
/******************************************************************************/
void arrayToFile(ofstream& out,int *array,const int SIZE){
    for(int i=0;i<SIZE;i++){
        out<<array[i];           
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             File to Array                                  */
/******************************************************************************/
void fileToArray(ifstream& infile,const int SIZE,int *array){
  for(int i=0;i<SIZE;i++){
        infile>>array[i];
   //    getline(infile,array,'\n');
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                            Array to File                                   */
/******************************************************************************/
void prntary(ofstream& out,int *array,const int SIZE){
    for(int i=0;i<SIZE;i++){
        cout<<array[i];           
    }
}