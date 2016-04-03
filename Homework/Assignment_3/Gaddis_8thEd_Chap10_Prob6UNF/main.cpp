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
/*Problems: everything works except for when it is added to the switch statement
 does not allow input for the switch statement 
 Plan on filling the other functions- assigning integer values to vowels and
 consonants and counting these through for loops, return string isnt working
 either space count?*/
//System Libraries
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void cVowel();  //Vowel count function
void cConsts(); //Consonants count function
void cVowNCon();//Consonants and Vowel count function
char *input();
//Execution Begins Here
int main(int argc, char** argv){
    //Declare and initialize variables
    char nSoltn;//Problem Solution to display
    bool reDsply=true;    //Exit program when false
    
    //Menu to Display Solution
    do{
        //Input problem to display, i.e. Menu
        cout<<"\nVowels and Consonants Menu"<<endl;
        cout<<"Type A to count the number of vowels in a string"<<endl;
        cout<<"Type B to count the number of consonants in a string"<<endl;
        cout<<"Type C to count both vowels and consonants in a string"<<endl;
        cout<<"Type D to enter another string"<<endl;
        cout<<"Type anything else to exit "<<endl<<endl;
        cin>>nSoltn;
        //Solutions to all the problems
        switch(nSoltn){
            case 65:case 97:{cVowel();break;}
            case 66:case 98:{cConsts();break;}
            case 67:case 99:{cVowNCon();break;}
            case 68:case 100:{*input();break;}
            default:{
                cout<<"Exiting the Program"<<endl;
                reDsply=false;
            }
        }
    }while(reDsply);

    //Exit stage right
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Count Consonants Function                           */
/******************************************************************************/
char *input(){ 
    char strng[50];
    cout<<"Enter a string "<<endl;
    cin.getline(strng,50);
    for (int i=0;i<strlen(strng);i++)
        cout<<*(strng+i);
//    return strng;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Count Vowels Function                               */
/******************************************************************************/
void cVowel(){

}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Count Consonants Function                           */
/******************************************************************************/
void cConsts(){
  
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                      Count Vowels and Consonants Function                  */
/******************************************************************************/
void cVowNCon(){
  
}
