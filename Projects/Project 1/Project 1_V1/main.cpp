/* Author: Kayla Rodriguez
 * Created on January 30, 2016, 8:55 PM
 * Purpose: Mastermind
 */

//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream> //File I/O
#include <iomanip> //Formatting
#include <vector> //vector library
using namespace std;
 
//User Libraries
struct UserColor{
    string color;
    int spot;
};
#include "ComColor.h"
//Global Constant
const char CNVPERC=100;
const int COLS=2;
//Function Prototypes
char *compic(ComColor[],string[],char[],int);
char *input(UserColor[],string*,const int,string[],char[]);
void switchH(UserColor[],ComColor[],int,int &);
void reppic(char[],char[],int &,const char,int &,const int ,vector<string>&);
void results(UserColor[],ComColor[],int&,const char,const char,int&,int,char[][COLS],
        const int,string[],int);
int check(char[],int, char);//checks to see if input is valid
string aryToStr(char [],int);//converts a character array to a string
void hints1();
void hints2();
void hints3();
void  writeFile(fstream& ,int,const char,UserColor[],ComColor[],vector<string>&);
//Execution Begins Here
int main(int argc, char** argv) {
    //The Problem to solve
    cout<<endl<<"Solution to Project 2"<<endl;
    cout<<endl<<"Mastermind Problem "<<endl;
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare and initialize variables
    const int SIZE=4;  //Size of array used to keep track of color choices    
    UserColor clrPick[SIZE];  //User Inputs
    string order[SIZE]={"first","second","third","fourth"}; //User Order Inputs
    string options[8]={"Red","Green","Blue","Brown","Black","Yellow","Orange","White"};//Options for computer and user 
    ComColor cColor[SIZE]; //Computer generated random pick
    int limit=0;  //number of attempts, the user can set their attempts greater than 10
    const char GMELMT=10; //Number limit which determines win or loss
    int search; //search function finds invalid characters
    char end[SIZE][COLS]; //2D array to show final results
    vector<string>list; //vector which converts characters to one condensed string
    int nameN=10; //number of names
    string *eachPick; //holds an array of each of the turn options 
    string names[nameN];//names in list
    char optChar[8]={'R','G','B','N','K','Y','O','W'};//character options
    fstream infile; //in file instructions
    string instr; //file instructions
    fstream out;//output file
    char *userChar; //User's colors in character representation
    int nTrys=0;//number of tries counter
    //Open the Files
    infile.open("instructions.txt", ios::in|ios::binary);
    out.open("results.txt",ios::out|ios::binary);
    //Read the File
    if( infile ){
        getline( infile, instr );
        while( infile ){
            cout << instr << endl;
            getline( infile, instr );
        }
    }
    //Set Game Limit
    cout<<"Enter in a maximum limit for the game. The game limit is ten, but you ";
    cout<<"can play more than 10 games to enter"<<endl;
    //User Inputs Game Amount
    cout<<"What is the max amount of attempts you would like to play?"<<endl;
    cin>>limit;
    //Modify the limit of games based on how many it takes to win
    limit= limit>GMELMT ? limit : GMELMT;//Ternary Operator
    eachPick=new string[limit];  
    //Function Output
    //computer's colors in character representation
    char *comChar = compic(cColor,options,optChar,SIZE);
    for(int i=0;i<SIZE;i++){
        cout<<cColor[i].getColor()<<" ";
    }
    //for loop allows player to play until the limit is hit
    for(int n=1;n<=limit;n++){
        userChar =input(clrPick,order,SIZE,options,optChar);
        reppic(userChar,comChar,nTrys,GMELMT,limit,SIZE,list);
        nTrys++;
        if (nTrys<=GMELMT&&clrPick[0].color==cColor[0].getColor()&&
                clrPick[1].color==cColor[1].getColor()&&
                clrPick[2].color==cColor[2].getColor()&&clrPick[3].color==cColor[3].getColor()){
            limit=nTrys;
            cout<<"Your number of tries is "<<nTrys<<endl;
        }
        switchH(clrPick,cColor,nTrys,limit);
    }
    //Print results of the game
    results(clrPick,cColor,nTrys,CNVPERC,GMELMT,limit,SIZE,end,COLS,names,nameN);
    //Write the Output Results File
    //writeFile(outptFile,nTrys,GMELMT,clrPick,cColor,list);
     out<<"Color Choices\tTurn Number\r";
    out<<"----------------------------\r";
    for(int i=0;i<list.size();i++)
        out<<list[i]<<"               "<<i+1<<"\r";
     
    if(nTrys<=GMELMT&&clrPick[0].color==cColor[0].getColor()
            &&clrPick[1].color==cColor[1].getColor()&&
            clrPick[2].color==cColor[2].getColor()&&clrPick[3].color==cColor[3].getColor()){
        //Tries Percentage if won 
        out<<fixed<<setprecision(1);
        out<<"You win!"<<endl;
        out<<"The percentage of the board you got through is ";
        out<<(float)(nTrys)/(10.0f)*CNVPERC<<"% "<<endl;
    }else
        out<<"You lose. You could not guess in 10 tries or less."<<endl;
    //free allocated memory
    delete[] eachPick;
    delete[] comChar;
    delete[] userChar;
    //close the files
    infile.close();
    out.close();
    return 0;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Write the File                                 */
/******************************************************************************/
void writeFile(fstream& out,int &nTrys,const char GMELMT,
        UserColor clrPick[],ComColor pick[],vector<string>&list){    
    out<<"Color Choices\tTurn Number\r";
    out<<"----------------------------\r";
    for(int i=0;i<list.size();i++)
        out<<list[i]<<"               "<<i+1<<"\r";
     
    if(nTrys<=GMELMT&&clrPick[0].color==pick[0].getColor()
            &&clrPick[1].color==pick[1].getColor()&&
            clrPick[2].color==pick[2].getColor()&&clrPick[3].color==pick[3].getColor()){
        //Tries Percentage if won 
        out<<fixed<<setprecision(1);
        out<<"You win!"<<endl;
        out<<"The percentage of the board you got through is ";
        out<<(float)(nTrys)/(10.0f)*CNVPERC<<"% "<<endl;
    }else
        out<<"You lose. You could not guess in 10 tries or less."<<endl;
}    
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Computer picks its colors                            */
/******************************************************************************/
//Computer Generated Pick of Colors User Tries to Guess
char *compic(ComColor cColor[],string options[],char optChar[],int SIZE){
    char *temp = new char[SIZE];
    bool cPick[8] = {0};
    for(int j=0;j<SIZE;j++){
        int index=rand()%8;
        while(cPick[index]==true)
            index=rand()%8;
        cPick[index] = true;
        cColor[j].setColor(options[index]);
        temp[j]=optChar[index];
    }
    return temp;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Input colors Function                                */
/******************************************************************************/
char *input(UserColor clrPick[],string *order,const int SIZE,string options[],char optChar[]){
    char * userChar=new char[SIZE];
    bool set[SIZE]={0};
    for (int i=0;i<SIZE;i++){
        string color;
        int spot;
        do{
            cout<<"Pick your "<<*(order+i)<<" color"<<endl;
            cin>>color;
            //pick spot
            cout<<"What spot would you like this color in?"<<endl;
            cin>>clrPick[i].spot;
        }while(set[clrPick[i].spot-1]);
        set[clrPick[i].spot-1]=true;
        
        //input to that index;
        clrPick[clrPick[i].spot-1].color=color;
        for(int j=0;j<8;j++){
            if(clrPick[clrPick[i].spot-1].color==options[j])
                userChar[clrPick[i].spot-1]=optChar[j];
        }
    }
    return userChar;
    
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                      Representation of previous picks to user              */
/******************************************************************************/
void reppic(char color[],char pick[],int &nTrys,const char GMELMT,int &limit,
     const int SIZE,vector<string>&list){
    //Representation of User's Original Choices
    //this is where the conversion from string to characters will happen
    cout<<"Your colors are ";
    for(int i=0;i<SIZE;i++){
        cout<<color[i]<<" ";
    }cout<<endl;
    //Loop to generate the table of choices
    list.push_back(aryToStr(color,SIZE));
    cout<<"Color Choices\tTurn Number"<<endl;
    cout<<"----------------------------"<<endl;
    for(int i=0;i<list.size();i++){
        cout<<list[i]<<"               "<<i+1<<endl;
    }      
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                          Array to String 
 * Turns an Array of characters into its own string to be outputted in a table*/
/******************************************************************************/
string aryToStr(char color[],int cSize){
    string str="";
    for(int i=0;i<cSize;i++){
        str+=color[i];
   }
   return str; 
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Results Output Function                             */
/******************************************************************************/
void results(UserColor color[],ComColor pick[],int &nTrys,const char CNVPERC,
        const char GMELMT,int &limit,const int SIZE,char end[][COLS],const int COLS,
        string names[],int nameN){
    //Reveals Computer's Choice Once User Guesses
    cout<<"Your colors are ";
    for(int i=0;i<SIZE;i++){
        cout<<color[i].color<<" ";
    }cout<<endl; 
    if(nTrys<=GMELMT&&color[0].color==pick[0].getColor()&&color[1].color==pick[1].getColor()&&
    color[2].color==pick[2].getColor()&&color[3].color==pick[3].getColor()){
        //Tries Percentage if won 
        cout<<fixed<<setprecision(1);
        cout<<"You win!"<<endl;
        cout<<"The percentage of the board you got through is ";
        cout<<(float)(nTrys)/(10.0f)*CNVPERC<<"% "<<endl;
    }else
        cout<<"You lose. You could not guess in 10 tries or less."<<endl;
    
}    
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Switch Hints Function                               */
/******************************************************************************/
void switchH(UserColor color[],ComColor pick[],int nTrys,int &limit){ 
//Two in the correct spot
if (color[0].color==pick[0].getColor()&&
        color[1].color==pick[1].getColor()&&
        color[2].color==pick[2].getColor()&&
        color[3].color==pick[3].getColor()){
    nTrys=limit;
    cout<<"You guessed all the colors correctly."<<endl;
//Three in the correct spot
}else if((color[0].color==pick[0].getColor())&&
        (color[1].color==pick[1].getColor())&&
        (color[2].color==pick[2].getColor())){
    cout<<"Three of your colors are correct and in the right ";
    cout<<"spot."<<endl<<endl;
}else if((color[0].color==pick[0].getColor())&&
        (color[1].color==pick[1].getColor())&&
        (color[3].color==pick[3].getColor())){
    cout<<"Three of your colors are correct and in the right ";
    cout<<"spot."<<endl<<endl;
}else if((color[3].color==pick[3].getColor())&&
        (color[1].color==pick[1].getColor())&&
        (color[2].color==pick[2].getColor())){
    cout<<"Three of your colors are correct and in the right ";
    cout<<"spot."<<endl<<endl;
}else if((color[0].color==pick[0].getColor())&&
        (color[3].color==pick[3].getColor())&&
        (color[2].color==pick[2].getColor())){
    cout<<"Three of your colors are correct and in the right ";
    cout<<"spot."<<endl<<endl;
}else if((color[0].color==pick[0].getColor())&&
        (color[1].color==pick[1].getColor())){
    cout<<"Two of your colors are correct and in the correct ";
    cout<<"spot."<<endl<<endl;
}else if((color[0].color==pick[0].getColor())&&
        (color[2].color==pick[2].getColor())){
    cout<<"Two of your colors are correct and in the correct ";
    cout<<"spot."<<endl<<endl;
}else if((color[0].color==pick[0].getColor())&&
        (color[3].color==pick[3].getColor())){
    cout<<"Two of your colors are correct and in the correct ";
    cout<<"spot."<<endl<<endl;
}else if((color[2].color==pick[2].getColor())&&
        (color[1].color==pick[1].getColor())){
    cout<<"Two of your colors are correct and in the correct ";
    cout<<"spot."<<endl<<endl;
}else if((color[3].color==pick[3].getColor())&&
        (color[1].color==pick[1].getColor())){
    cout<<"Two of your colors are correct and in the correct ";
    cout<<"spot."<<endl<<endl;
}else if((color[2].color==pick[2].getColor())&&
        (color[3].color==pick[3].getColor())){
    cout<<"Two of your colors are correct and in the correct ";
    cout<<"spot."<<endl<<endl;
}else if ((color[0].color==pick[0].getColor())||
        (color[1].color==pick[1].getColor())||
        (color[2].color==pick[2].getColor())||
        (color[3].color==pick[3].getColor())){
    cout<<"One of your colors is correct and in the correct "; 
    cout<<"spot."<<endl<<endl;
}else{
    cout<<"None are in the right spot."<<endl;


//Three of your color choices are correct
if ((color[0].color==pick[1].getColor()||color[0].color==pick[2].getColor()
        ||color[0].color==pick[3].getColor())&&
        (color[1].color==pick[2].getColor()||
        color[1].color==pick[3].getColor()||color[1].color==pick[0].getColor())
         &&(color[2].color==pick[1].getColor()||
        color[2].color==pick[3].getColor()||
        color[2].color==pick[0].getColor())){
    hints3();
}else if ((color[0].color==pick[1].getColor()||
        color[0].color==pick[2].getColor()||color[0].color==pick[3].getColor())
        &&(color[1].color==pick[2].getColor()||color[1].color==
        pick[3].getColor()||color[1].color==pick[0].getColor())
         &&(color[3].color==pick[1].getColor()||
        color[3].color==pick[2].getColor()||color[3].color==pick[0].getColor())){
    hints3();
}else if ((color[3].color==pick[1].getColor()||
        color[3].color==pick[2].getColor()||color[3].color==pick[0].getColor())
        &&(color[1].color==pick[2].getColor()||
        color[1].color==pick[3].getColor()||color[1].color==pick[0].getColor())
         &&(color[2].color==pick[1].getColor()||
        color[2].color==pick[3].getColor()||color[2].color==pick[0].getColor())){
    hints3();
}else if ((color[0].color==pick[1].getColor()||
        color[0].color==pick[2].getColor()||
        color[0].color==pick[3].getColor())
        &&(color[3].color==pick[2].getColor()||
        color[3].color==pick[1].getColor()||color[3].color==pick[0].getColor())
         &&(color[2].color==pick[1].getColor()||
        color[2].color==pick[3].getColor()||color[2].color==pick[0].getColor())){
    hints3();
} 
//Two of your color choices are correct  
    else if ((color[0].color==pick[1].getColor()||
        color[0].color==pick[2].getColor()||
        color[0].color==pick[3].getColor())
        &&(color[1].color==pick[2].getColor()||color[1].color==pick[3].getColor()
        ||color[1].color==pick[0].getColor())){
    hints2();
}else if ((color[0].color==pick[1].getColor()||
        color[0].color==pick[2].getColor()||color[0].color==pick[3].getColor())
        &&(color[2].color==pick[1].getColor()||
        color[2].color==pick[3].getColor()||color[2].color==pick[0].getColor())){
    hints2();
}else if ((color[0].color==pick[1].getColor()||
        color[0].color==pick[2].getColor()||color[0].color==pick[3].getColor())
        &&(color[3].color==pick[2].getColor()||
        color[3].color==pick[1].getColor()||color[3].color==pick[0].getColor())){
    hints2();
}else if ((color[3].color==pick[1].getColor()||color[3].color==pick[2].getColor()
        ||color[3].color==pick[0].getColor())&&
        (color[1].color==pick[2].getColor()||
        color[1].color==pick[3].getColor()||color[1].color==pick[0].getColor())){
    hints2();
}else if ((color[2].color==pick[1].getColor()||
        color[2].color==pick[0].getColor()||color[2].color==pick[3].getColor())
        &&(color[1].color==pick[2].getColor()||
        color[1].color==pick[3].getColor()||color[1].color==pick[0].getColor())){
    hints2();
}else if ((color[3].color==pick[1].getColor()||
        color[3].color==pick[2].getColor()||color[3].color==pick[0].getColor())
        &&(color[2].color==pick[1].getColor()||
        color[2].color==pick[3].getColor()||color[2].color==pick[0].getColor())){
    hints2();
//One of your color choices is correct
}else if (color[0].color==pick[1].getColor()&&
        !(color[0].color==pick[2].getColor()&&color[0].color==pick[3].getColor()
        &&color[1].color==pick[0].getColor()&&
        color[1].color==pick[2].getColor()&&color[1].color==pick[3].getColor()&&
        color[2].color==pick[1].getColor()&&color[2].color==pick[0].getColor()
        &&color[2].color==pick[3].getColor()&&
        color[3].color==pick[1].getColor()&&color[3].color==pick[2].getColor()
        &&color[3].color==pick[0].getColor())){
    hints1();
}else if (color[0].color==pick[2].getColor()&&!(color[0].color==pick[1].getColor()
        &&color[0].color==pick[3].getColor()&&
        color[1].color==pick[0].getColor()&&color[1].color==pick[2].getColor()
        &&color[1].color==pick[3].getColor()&&
        color[2].color==pick[1].getColor()&&color[2].color==pick[0].getColor()
        &&color[2].color==pick[3].getColor()&&
        color[3].color==pick[1].getColor()&&
        color[3].color==pick[2].getColor()&&color[3].color==pick[0].getColor())){
    hints1();
}else if(color[0].color==pick[3].getColor()&&!(color[0].color==pick[2].getColor()
        &&color[0].color==pick[1].getColor()
        &&color[1].color==pick[0].getColor()&&color[1].color==pick[2].getColor()
        &&color[1].color==pick[3].getColor()&&
        color[2].color==pick[1].getColor()&&color[2].color==pick[0].getColor()
        &&color[2].color==pick[3].getColor()&&
        color[3].color==pick[1].getColor()&&color[3].color==pick[2].getColor()
        &&color[3].color==pick[0].getColor())){
    hints1();
}else if (color[1].color==pick[0].getColor()&&!(color[0].color==pick[2].getColor()
        &&color[0].color==pick[3].getColor()
        &&color[0].color==pick[1].getColor()&&color[1].color==pick[2].getColor()
        &&color[1].color==pick[3].getColor()&&
        color[2].color==pick[1].getColor()&&color[2].color==pick[0].getColor()
        &&color[2].color==pick[3].getColor()&&
        color[3].color==pick[1].getColor()&&color[3].color==pick[2].getColor()
        &&color[3].color==pick[0].getColor())){
    hints1();
}else if(color[1].color==pick[2].getColor()&&!(color[0].color==pick[2].getColor()
        &&color[0].color==pick[3].getColor()
        &&color[1].color==pick[0].getColor()&&color[0].color==pick[1].getColor()
        &&color[1].color==pick[3].getColor()&&
        color[2].color==pick[1].getColor()&&color[2].color==pick[0].getColor()
        &&color[2].color==pick[3].getColor()&&
        color[3].color==pick[1].getColor()&&color[3].color==pick[2].getColor()
        &&color[3].color==pick[0].getColor())){
    hints1();
}else if(color[1].color==pick[3].getColor()&&!(color[0].color==pick[2].getColor()
        &&color[0].color==pick[3].getColor()
        &&color[1].color==pick[0].getColor()&&color[1].color==pick[2].getColor()
        &&color[0].color==pick[1].getColor()&&
        color[2].color==pick[1].getColor()&&color[2].color==pick[0].getColor()
        &&color[2].color==pick[3].getColor()&&
        color[3].color==pick[1].getColor()&&color[3].color==pick[2].getColor()
        &&color[3].color==pick[0].getColor())){
    hints1();
}else if (color[2].color==pick[1].getColor()&&!(color[0].color==pick[2].getColor()
        &&color[0].color==pick[3].getColor()
        &&color[1].color==pick[0].getColor()&&color[1].color==pick[2].getColor()
        &&color[1].color==pick[3].getColor()&&
        color[0].color==pick[1].getColor()&&color[2].color==pick[0].getColor()
        &&color[2].color==pick[3].getColor()&&
        color[3].color==pick[1].getColor()&&color[3].color==pick[2].getColor()
        &&color[3].color==pick[0].getColor())){
    hints1();
}else if(color[2].color==pick[0].getColor()&&!(color[0].color==pick[2].getColor()
        &&color[0].color==pick[3].getColor()
        &&color[1].color==pick[0].getColor()&&color[1].color==pick[2].getColor()
        &&color[1].color==pick[3].getColor()&&
        color[2].color==pick[1].getColor()&&color[0].color==pick[1].getColor()
        &&color[2].color==pick[3].getColor()&&
        color[3].color==pick[1].getColor()&&color[3].color==pick[2].getColor()
        &&color[3].color==pick[0].getColor())){
    hints1();
}else if(color[2].color==pick[3].getColor()&&!(color[0].color==pick[2].getColor()
        &&color[0].color==pick[3].getColor()
        &&color[1].color==pick[0].getColor()&&color[1].color==pick[2].getColor()
        &&color[1].color==pick[3].getColor()&&
        color[2].color==pick[1].getColor()&&color[2].color==pick[0].getColor()
        &&color[0].color==pick[1].getColor()&&
        color[3].color==pick[1].getColor()&&color[3].color==pick[2].getColor()
        &&color[3].color==pick[0].getColor())){
    hints1();
}else if (color[3].color==pick[1].getColor()&&!(color[0].color==pick[2].getColor()
        &&color[0].color==pick[3].getColor()
        &&color[1].color==pick[0].getColor()&&color[1].color==pick[2].getColor()
        &&color[1].color==pick[3].getColor()&&
        color[2].color==pick[1].getColor()&&color[2].color==pick[0].getColor()
        &&color[2].color==pick[3].getColor()&&
        color[0].color==pick[1].getColor()&&color[3].color==pick[2].getColor()
        &&color[3].color==pick[0].getColor())){
    hints1();
}else if(color[3].color==pick[2].getColor()&&(!(color[0].color==pick[2].getColor()
        &&color[0].color==pick[3].getColor()
        &&color[1].color==pick[0].getColor()&&color[1].color==pick[2].getColor()
        &&color[1].color==pick[3].getColor()&&
        color[2].color==pick[1].getColor()&&color[2].color==pick[0].getColor()
        &&color[2].color==pick[3].getColor()&&
        color[3].color==pick[1].getColor()&&color[0].color==pick[1].getColor()
        &&color[3].color==pick[0].getColor()))){
    hints1();
}else if(color[3].color==pick[0].getColor()&&!(color[0].color==pick[2].getColor()
        &&color[0].color==pick[3].getColor()
        &&color[1].color==pick[0].getColor()&&color[1].color==pick[2].getColor()
        &&color[1].color==pick[3].getColor()&&
        color[2].color==pick[1].getColor()&&color[2].color==pick[0].getColor()
        &&color[2].color==pick[3].getColor()&&
        color[3].color==pick[1].getColor()&&color[3].color==pick[2].getColor()
        &&color[0].color==pick[1].getColor())){
    hints1();
}else{
    cout<<"None of these color choices are correct or in the  "; 
    cout<<"right spot."<<endl<<"Try something different."<<endl
                                                         <<endl;
}

}


}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                               Hints Function                               */
/******************************************************************************/
void hints1(){
    cout<<"One of your colors is correct; ";
    cout<<"however, it is not in the right spot."<<endl;
    cout<<"Change the order of which you ";
    cout<<"input this color to get it in the right spot."<<endl;
    cout<<endl<<endl;
}
void hints2(){
    cout<<"Two of your colors are correct; ";
    cout<<"however, neither are in the right spot."<<endl;
    cout<<"Change the order of which you ";
    cout<<"input this color to get it in the right spot."<<endl;
    cout<<endl<<endl;
}
void hints3(){
    cout<<"Three of your colors are correct; ";
    cout<<"however, none are not in the right spot."<<endl;
    cout<<"Change the order of which you ";
    cout<<"input this color to get it in the right spot."<<endl;
    cout<<endl<<endl;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Linear Search
//Inputs:
//  a->Array or List
//  n->Size of List
//  strt->Starting Position
//  val->Value to find
//Outputs:
//  pos->Index where value is found
//******************************************************************************
int check(char options[], int SIZE, char color){
    int i = 0;			
    int pos = -1; //Records position of search value		
    bool found = false;		
    while (i < SIZE && !found){
        if (options[i] == toupper(color)){
            found = true;
            pos = i;		  			
        }
        i++;
    }
    return pos;				
}

