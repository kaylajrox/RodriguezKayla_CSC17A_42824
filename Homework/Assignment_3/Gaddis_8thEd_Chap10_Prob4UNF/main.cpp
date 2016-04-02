/*
 * Author: Kayla Rodriguez
 * Title: Average Number of Letters
 * Problem: Gaddis_8thEd_Chap10_Prob4
 *
    Problem 3:
  Write a function that accepts a pointer to a C-string as an argument and
  returns the number of words contained in the string. For instance, if the
  string argument is “Four score and seven years ago” the function should return
  the number 6. Demonstrate the function in a program that asks the user to
  input a string and then passes it to the function. The number of words in the
  string should be displayed on the screen. Optional Exercise: Write an
  overloaded version of this function that accepts a string class object
   as its argument.
    Problem 4:
  Modify the program you wrote for Problem 3 (Word Counter), so it also
  displays the average number of letters in each word.
 */
/*This problem is not working correctly. Does not calculate the average like
 it should. Need to find a better way to fin avg */

//System Libraries
#include <bits/stdc++.h>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int wrdCnt(char*,int&); //word count function
int letrCnt(char*,int&); //letter count function
//Execution Begins Here
int main(int argc, char** argv){
    //Declare Variables   
    char str[50];//character array of max size 50
    int count=0; //counts the number of words and letters
    
    //Input
    cout<<"Please input a string (any word or sentence) and press enter "<<endl;
    cin.ignore();
    cin.getline(str,50);
    //Word Count 
    int nWord=wrdCnt(str,count);
    cout<<"There were "<<(count+1)<<" words."<<endl;
    //Letter Count
    int nLetr=letrCnt(str,count);
    cout<<"There were "<<nLetr<<" letters"<<endl;
    cout<<"There was an average of "<<(nLetr/(nWord+1))<<" letters per word."<<endl;
    
    return 0;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Word Count Function                                 */
/******************************************************************************/
int wrdCnt(char *str,int &cWord){
     //Count the number of words
    for (int i=0;i<strlen(str);i++){
        if (str[i]==' '){
            cWord++;
        } 
    }
    return cWord;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Letter Count Function                               */
/******************************************************************************/
int letrCnt(char *str,int &cLetr){
     //Count the number of letters
    for (int j=0;j<strlen(str);j++){
        if (str[j]!=' '){
            cLetr++;
        }      
    }
    return cLetr;
}