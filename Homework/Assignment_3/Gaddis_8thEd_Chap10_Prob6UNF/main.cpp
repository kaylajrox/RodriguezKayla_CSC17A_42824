/*
 * Author: Kayla Rodriguez
 * Title: Vowels and Consonants
 * Problem: Gaddis_8thEd_Chap10_Prob6
 *
    Problem 6:
   Write a function that accepts a pointer to a C-string as its argument.
  The function should count the number of vowels appearing in the string and
  return that number.  Write another function that accepts a pointer to a
  C-string as its argument. This function should count the number of consonants
  appearing in the string and return that number.  Demonstrate these two
  functions in a program that performs the following steps:
  1.   The user is asked to enter a string.
  2.   The program displays the following menu:
   A)   Count the number of vowels in the string
   B)   Count the number of consonants in the string
   C)   Count both the vowels and consonants in the string
   D)   Enter another string
   E)   Exit the program
  3.    The program performs the operation selected by the user and repeats
    until the user selects E to exit the program.
 */
/*How can i make the D selection as opposed to a do-while loop*/
//System Libraries
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int cVowel(char*,char*);  //Vowel count function
int cConsts(char*,char*); //Consonants count function
int cVowNCon(char*);//Consonants and Vowel count function
void input(char*);
//Execution Begins Here
int main(int argc, char** argv){
    //Declare and initialize variables
    char nSoltn;//Problem Solution to display
    char reDsply;    //Exit program when false
    char strng[50];
    char vowels[5]={'a','e','i','o','u'};
    //Menu to Display Solution
    do{
        //Input problem to display, i.e. Menu
        cout<<"\nVowels and Consonants Menu"<<endl;
        cout<<"Type A to count the number of vowels in a string"<<endl;
        cout<<"Type B to count the number of consonants in a string"<<endl;
        cout<<"Type C to count both vowels and consonants in a string"<<endl;
        cout<<"Type D to enter a new string"<<endl;
        cout<<"Type E to exit "<<endl<<endl;
        cin>>nSoltn;

        //Solutions to all the problems
        switch(nSoltn){
            case 65:case 97:{int cVow=cVowel(strng,vowels);
            cout<<"Number of vowels "<<cVow;break;}
            case 66:case 98:{int cCon=cConsts(strng,vowels);
            cout<<"Number of consonants "<<cCon;break;}
            case 67:case 99:{int letr=cVowNCon(strng);
            cout<<"Number of vowels and consonants: "<<letr;break;}
            case 68:case 100:{input(strng);break;};
            case 69: case 101:{
                cout<<"Exiting the Program"<<endl;
                return 0;
            }
        }
        nSoltn=toupper(nSoltn);
    }while(reDsply!='D');

    //Exit stage right
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Count Vowels Function                               */
/******************************************************************************/
int cVowel(char *strng, char *vowels){
   int count=0;
    //Count the number of words
    for (int i=0;i<strlen(strng);i++){
        if (strng[i]==vowels[0]||strng[i]==vowels[1]||strng[i]==vowels[2]||
                strng[i]==vowels[3]||strng[i]==vowels[4]){
        count++;
        }
    }
    return count;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Count Consonants Function                           */
/******************************************************************************/
int cConsts(char *strng, char *vowels){
  int count=0;
    //Count the number of words
    for (int i=0;i<strlen(strng);i++){
        if (!(strng[i]==vowels[0]||strng[i]==vowels[1]||strng[i]==vowels[2]
                ||strng[i]==vowels[3]||strng[i]==vowels[4])){
        count++;
        }
    }
    return count;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                      Count Vowels and Consonants Function                  */
/******************************************************************************/
int cVowNCon(char *strng){
    int count=0;
    for (int i=0;i<strlen(strng);i++){
        if (isalpha(strng[i]))
            count++;
    }
    return count;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                      Count Vowels and Consonants Function                  */
/******************************************************************************/
void input(char *strng){
    //Input String
    cout<<"Enter a string "<<endl;
    cin.ignore();
    cin.getline(strng,50);
    for (int i=0;i<strlen(strng);i++)
        cout<<*(strng+i);
}
