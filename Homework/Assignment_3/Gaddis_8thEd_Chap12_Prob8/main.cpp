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
void fileToArray(fstream&,const int,int *);
void arrayToFile(fstream&,int *,const int);
void prntary(fstream&,int *,const int);
string fileToString(fstream&);
//Execution Begins Here
int main(int argc, char** argv){
    //Declare Variables
    const int SIZE=7;//size of array
    fstream fleNme; //file name
    int array[SIZE]={1,2,3,4,5,6,7};    
    //Output results to a file
    arrayToFile(fleNme,array,SIZE);//File to string to print on console
    //Read the files
    fileToArray(fleNme,SIZE,array);    
    //close the files
    fleNme.close();
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                            Array to File (outputs file)                    */
/******************************************************************************/
void arrayToFile(fstream& fleNme,int *array,const int SIZE){
    //open the file
    fleNme.open("fileToArray.txt",ios::out|ios::binary);
    if(fleNme){
        cout<<"File opened"<<endl;
        fleNme.write(reinterpret_cast<char *>(array),sizeof(array));
    }else
        cout<<"File failed to open."<<endl;
    //close the file
    fleNme.close();
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             File to Array (reads file)                     */
/******************************************************************************/
void fileToArray(fstream& infile,const int SIZE,int *array){
    infile.open("fileToArray.txt",ios::in|ios::binary);  
    if(infile){
        infile.read(reinterpret_cast<char *>(array),sizeof(array));            
    }else
        cout<<"File failed to Open"<<endl;
    cout<<"Contents of array "<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<array[i]<<" ";
    }
    infile.close();
}

