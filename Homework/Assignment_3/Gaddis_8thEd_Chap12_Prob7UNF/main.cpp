/*Author: Kayla Rodriguez
 Title: Sentence Filter
 Problem:
  Write a program that asks the user for two file names.
  The first file will be opened for input and the second file will be opened 
  for output. (It will be assumed that the first file contains sentences that 
  end with a period.) The program will read the contents of the first file and 
  change all the letters to lowercase except the first letter of each sentence, 
  which should be made uppercase. The revised contents should be stored in the 
  second file.       */
//System Libraries
#include <bits/stdc++.h>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv){    
    //Open the File
    ifstrem infile;
    infile.open("input.txt");
    
    //Read the File
    rdFile();
    
   
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Read the File                                  */
/******************************************************************************/
void rdFile(ifstream&   infile){
    for (int i=0;i<NAMES;i++){
        infile>>names[i];
    }
}
//    //Declare variables 
//    ifstream file1;
//    ofstream file2;
//    file2;
//    //Input 
//    cout<<"Input two file names. The first will be opened for input and the ";
//    cout<<"second will be opened for output "<<endl;
//    cout<<"Enter the first file name and press enter."<<endl;
//    cin>>file1;
//    cout<<"Enter the second file name and press enter."<<endl;
//    cin>>file2;