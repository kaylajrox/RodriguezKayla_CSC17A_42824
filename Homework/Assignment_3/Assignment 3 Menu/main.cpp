/* 
 Author: Kayla Rodriguez
 * Assignment 3 Problem Set
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

//User Libraries
struct Company{
    string name; //name of division
    int qrtr; //the number of quarter
    int qrtrSles; //quarter sales      
    };
//Global Constants

//Function prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
int wrdCnt(char*,int&); //word count function
int letrCnt(char*,int&); //letter count function
int cVowel(char*,char*);  //Vowel count function
int cConsts(char*,char*); //Consonants count function
int cVowNCon(char*);//Consonants and Vowel count function
void input(char*);
void fileToArray(fstream&,const int,int *);
void arrayToFile(fstream&,int *,const int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned short nSoltn;//Problem Solution to display
    bool reDsply=true;    //Exit program when false

    //Menu to Display Solution
    do{
        //Input problem to display, i.e. Menu
        cout<<"\nAssignment 2 Problem Set"<<endl;
        cout<<"Type 1 to Display Gaddis_8thEd_Chap10_Prob4"<<endl;
        cout<<"Type 2 to Display Gaddis_8thEd_Chap10_Prob6"<<endl;
        cout<<"Type 3 to Display Gaddis_8thEd_Chap12_Prob7"<<endl;
        cout<<"Type 4 to Display Gaddis_8thEd_Chap12_Prob8"<<endl;
        cout<<"Type 5 to Display Gaddis_8thEd_Chap12_Prob11"<<endl;
        cout<<"Type anything else to exit "<<endl<<endl;
        cin>>nSoltn;
        //Solutions to all the problems
        switch(nSoltn){
            case 1:{problem1();break;}
            case 2:{problem2();break;}
            case 3:{problem3();break;}
            case 4:{problem4();break;}
            case 5:{problem5();break;}
            default:{
                cout<<"Exiting the Program"<<endl;
                reDsply=false;
            }
        }
    }while(reDsply);

    //Exit stage right
    return 0;
}
/******************************************************************************/
/************************** Problem 1 *****************************************/
/******************************************************************************/
void problem1(){
    cout<<endl<<"Solution to Gaddis_8thEd_Chap10_Prob4"<<endl;
    cout<<endl<<"Average Number of Letters"<<endl<<endl;
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

/******************************************************************************/
/************************** Problem 2 *****************************************/
/******************************************************************************/
void problem2(){
    //The problem to solve
    cout<<endl<<"Solution to Gaddis_8thEd_Chap10_Prob6"<<endl;
    cout<<endl<<"Vowels and Consonants "<<endl;
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
                reDsply='D';
            }
        }
        nSoltn=toupper(nSoltn);
    }while(reDsply!='D');
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
}
/******************************************************************************/
/************************** Problem 3 *****************************************/
/******************************************************************************/
void problem3(){
    //The problem to solve
    cout<<endl<<"Solution to Gaddis_8thEd_Chap12_Prob7"<<endl;
    cout<<endl<<"Sentence Filter"<<endl<<endl;
    //Open the File and Declare/Initialize variables
    ifstream infile;
    ofstream outfile;
    string fileIn,fileOut;
    //boolean to flag end of sentence
    bool isfirst=true;
    //check if file can open
    cout<<"This program changes all letters after a period to uppercase"<<endl;
    //get user input for an input file name
    cout << "Enter a file name you would like to read from" << endl;
    cin.ignore();
    getline(cin,fileIn);
    infile.open(fileIn.c_str());
    // get user input for an output file name
    cout<<"Enter a file name you would like to save the revised version"<<endl;
    cin >> fileOut;
    outfile.open(fileOut.c_str());
    //Reading the first character
    char ch=infile.get();
    if (infile.good()){
    while (!infile.eof())
    {
        if (isfirst)
        {
            if (isalpha(ch))
            {
                //write the first character of a sentence
                outfile.put(toupper(ch));
                //reset flag
                isfirst=false;
            }
            else 
                //write all other characters after period that are not a letter
                outfile.put(ch);            
        }
        else
            //write all other characters in lower case
          outfile.put(tolower(ch)); 
        
        if (ch=='.')
            isfirst=true; //this is the end of sentence so reads next character
        
        //Reading the next character
        ch=infile.get();
    }
    infile.close();
    outfile.close();
    }else{
        cout << "File opening failed" << endl;
        cout << fileIn << endl << fileOut << endl;
    }
}
void problem4(){
   cout<<endl<<"Solution to Gaddis_8thEd_Chap12_Prob8"<<endl;
   cout<<endl<<"Array/File Functions"<<endl<<endl;
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
/******************************************************************************/
/************************** Problem 5 *****************************************/
/******************************************************************************/
void problem5(){
    cout<<endl<<"Solution to Gaddis_8thEd_Chap12_Prob11"<<endl;
    cout<<endl<<"Corporate Sales Data Output"<<endl<<endl;
    //Declare Variables
    const int SIZE=2;
    Company divNme[SIZE][SIZE];
    string fleNme;//file name
    ofstream out; //output file name
    //Introduction
    cout<<"This Program stores quarterly sells for divisions of a company\n";
    cout<<"and outputs the results onto a text file.\n";
            
    //input data for file
    cout<<"Enter a file name to store the quarter sales "<<endl;
    cin.ignore();
    getline(cin,fleNme); 
    out.open(fleNme.c_str());
    //get user input for a file name
    for(int i=0;i<SIZE;i++){
        cout<<"Input division Name"<<endl;
        cin>>divNme[i][i].name;
        for(int j=0;j<SIZE;j++){
            cout<<"Input quarter number "<<endl;
            cin>>divNme[i][j].qrtr;
            do{
                cout<<"Input quarter sales"<<endl;
                cin>>divNme[i][j].qrtrSles;
                if(divNme[i][j].qrtrSles<0)
                    cout<<"No negative sales."<<endl;
            }while(divNme[i][j].qrtrSles<0);  
        }
    }
    cout<<endl;
    //output information to a file
    for(int i=0;i<SIZE;i++){
        out<<"Division Name: "<<endl;
        out<<divNme[i][i].name<<endl;
        for(int j=0;j<SIZE;j++){
            out<<"Quarter: "<<endl;
            out<<divNme[i][j].qrtr<<endl;
            out<<"Quarterly Sales "<<endl;
            out<<divNme[i][j].qrtrSles<<endl;           
        }
        out<<endl;
    }
    out<<endl;
}
