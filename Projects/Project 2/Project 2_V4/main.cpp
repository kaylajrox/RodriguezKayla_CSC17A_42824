/* Author: Kayla Rodriguez
 * Created on January 30, 2016, 8:55 PM
 * Purpose: Mastermind
 * file opening was used on notepad and the format outputs the way it should
 * on notepad
 */
/*Concerns: run is failing again, I need help with the leader board functions
 when i press 1 it shows the instructions, but once it is back in the menu
 it doesn't redisplay the instructions, need a more efficient way to code the 
 leader board functions.
 Things I added in this Version:
 -exceptions
 -put everything in a menu*/
//System Libraries
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream> //File I/O
#include <vector> //vector library
#include <iomanip> //Formatting
using namespace std;
 
//User Libraries
#include "UserColor.h"
#include "ComColor.h"

//Global Constant
const char CNVPERC=100;

//Function Prototypes
char *compic(ComColor[],string[],char[],int);
UserColor *input(string *,const int,char[],string[]);
void switchH(UserColor[],ComColor[],int,const int);
void reppic(char[],char[],int &,const char,const int ,vector<string>&);
void results(UserColor[],int&,const char,const char,int,char[],char[]);
string aryToStr(char [],int);//converts a character array to a string
void  writeFile(fstream& ,int& ,const char, UserColor[],ComColor[],vector<string>&);
void readFile(fstream& ,string);
char *input2(UserColor[],const int,char[],string[]);
void markSrt(int *,int);
void readLdr(fstream&,string);
void lder(string,int,fstream&);
void lderOutput(string,int);
void game(fstream&,fstream&,fstream&);
void leader(string,int,fstream);
void Menu();
void def(int);
int getN();

//Execution Begins Here
int main(int argc, char** argv) {
    //The Problem to solve
    cout<<endl<<"Project 2"<<endl;
    cout<<endl<<"Mastermind Problem "<<endl;
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    //file instructions
    fstream infile; //in file instructions
    string instr; //file instructions
    fstream out;//output file
    fstream leader; //file to hold leader board results
    
    //menu variables
    int inN;
    bool reDsply=true;
    
    //Open the Files
    infile.open("instructions.txt", ios::in|ios::binary);
    out.open("results.txt",ios::out|ios::binary);
    leader.open("leader.txt",ios::in|ios::out);
    
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    //Read the File and Output its contents (the introduction)
                   readFile(infile,instr);break;
        case 2:    game(infile,out,leader);break;
//        case 3:    problem3();break; //fix this to output just the contents of leader board file      
        default:   {def(inN);
                    reDsply=false;}
        }
    }while(reDsply);
    
    //close the files
    infile.close();
    out.close();
    leader.close();
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"\nMenu for Mastermind"<<endl;
    cout<<"Type 1 for the instructions"<<endl;
    cout<<"Type 2 for to play the game"<<endl;
    cout<<"Type 3 to see the contents of the leader board"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                                Play Mastermind                             */
/******************************************************************************/   
void game(fstream& infile,fstream& out,fstream& leader){
    //Declare and initialize variables
    //constants
    const int SIZE=4;  //Size of array used to keep track of color choices    
    char gmelmt=10; //Number limit which determines win or loss
    
    //Arrays, Pointers,Vectors
    string order[SIZE]={"first","second","third","fourth"}; //User Order Inputs
    string options[8]={"red","green","blue","brown","black","yellow","orange","white"};
    char optChar[8]={'R','G','B','N','K','Y','O','W'};//character options
    char *userChar;//User's colors in character representation
    UserColor *clrPick;  //User Inputs
    vector<string>list; //vector which converts characters to one condensed string
    
    //Counters and Object variables
    int nTrys=0;//number of tries counter
    char choice; //choice on whether or not to increment turns
    UserColor limit; //object to be incremented using overloaded operator
    string name; //variable to store the name written in the file
    
    //Open the Files
    infile.open("instructions.txt", ios::in|ios::binary);
    out.open("results.txt",ios::out|ios::binary);
    leader.open("leader.txt",ios::in|ios::out);
        
        
    //Allocate Memory for computer colors
    ComColor *cColor = new ComColor[SIZE]; //Computer generated random pick
    
    //computer's colors in character representation
    char *comChar = compic(cColor,options,optChar,SIZE);
    for(int i=0;i<SIZE;i++){
        cout<<comChar[i];
    }
    //for loop allows player to play until the limit is hit
    for(int n=1;n<=gmelmt;n++){
        clrPick=input(order,SIZE,optChar,options);   
        userChar=input2(clrPick,SIZE,optChar,options);
        reppic(userChar,comChar,nTrys,gmelmt,SIZE,list);
        nTrys++; 
        if(nTrys<=gmelmt&&userChar[0]==comChar[0]&&userChar[1]==comChar[1]&&
                userChar[2]==comChar[2]&&userChar[3]==comChar[3]){
            cout<<"You win! "<<endl;
//            leader(name,nTrys,leader);
            break;
        }
        else if(nTrys==gmelmt){
            cout<<"You have reached the game limit and still have not guessed ";
            cout<<"the correct colors, which means you have lost the game. "<<endl;
            cout<<"Would you like to keep guessing anyway and increment your ";
            cout<<"turn number? Enter y for yes and anything else for no."<<endl;
            
            cin>>choice;//gets user input for color
            
            choice=tolower(choice);
            if (choice=='y'){
                limit.setTurn(nTrys);
                ++limit; //increment the number of turns user is allowed
                gmelmt=limit.getTurn();
            }
        }
        switchH(clrPick,cColor,nTrys,SIZE);
    }
    
    //Print results of the game
    results(clrPick,nTrys,CNVPERC,gmelmt,SIZE,userChar,comChar);
    
    //Write the Output Results File
    writeFile(out,nTrys,gmelmt,clrPick,cColor,list);
    
    //free allocated memory
    delete[] cColor;
    delete[] comChar;
    delete[] userChar;
    delete[] clrPick;
          
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                         Read the instruction File                          */
/******************************************************************************/
void readFile(fstream& infile,string instr){
    if( infile ){
        getline( infile, instr );
        while( infile ){
            cout << instr << endl;
            getline( infile, instr );
        }
    }   
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Write the File                                 */
/******************************************************************************/
void writeFile(fstream& out,int &nTrys,const char GMELMT,
        UserColor clrPick[],ComColor cColor[],vector<string>&list){    
    out<<"Color Choices\tTurn Number\r"<<endl;
    out<<"----------------------------\r"<<endl;
    for(int i=0;i<list.size();i++)
        out<<list[i]<<setw(15)<<i+1<<"\r"<<endl;
     
    if(nTrys<=GMELMT&&clrPick[0].getColor()==cColor[0].getColor()
            &&clrPick[1].getColor()==cColor[1].getColor()&&
            clrPick[2].getColor()==cColor[2].getColor()
            &&clrPick[3].getColor()==cColor[3].getColor())
    {
        //Tries Percentage if won 
        out<<fixed<<setprecision(1);
        out<<"You win!"<<endl;
        out<<"You attempted "<<nTrys<<" out of the maximum ten tries to win. \r"<<endl;
        out<<"Which means the percentage of the board you got through is ";
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
UserColor *input(string *order,const int SIZE,char optChar[],string options[]){
    UserColor * clrPick=new UserColor[SIZE];
    bool set[SIZE];
    bool v=true; //validation
    int spot;
    for(int i = 0; i < SIZE; i++)
    {
        set[i] = false;
    }
    for (int i=0;i<SIZE;i++){
        string color;
        cout<<"Pick your "<<*(order+i)<<" color"<<endl;
        cin>>color;
        for (int j=0;j<color.size();j++){
            color[j]=tolower(color[j]);
        }
        //utilizing an exception to check the color
        while(v){
           try{
                clrPick[i].setColor(color);
           }catch(UserColor::EmpClass){
                cout<<"Invalid color. Enter again."<<endl;
                cin>>color;
           }
        }
    do{    
            //pick spot
            cout<<"What spot would you like this color in?"<<endl;
            cin>>spot;
            clrPick[i].setSpot(spot);
            }while(set[clrPick[i].getSpot()-1]);
            set[clrPick[i].getSpot()-1]=true;
            //input to that index
            clrPick[clrPick[i].getSpot()-1].getColor()=color;
    } 
   return clrPick; 
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Input colors Function 2
 *returns the character representation of the color strings the user typed out*/
/******************************************************************************/
char *input2(UserColor clrPick[],const int SIZE,char optChar[],string options[]){
    char * userChar=new char[SIZE];
    for(int i=0;i<SIZE;i++){
        //input to that index;
        for(int j=0;j<8;j++){
            if(clrPick[clrPick[i].getSpot()-1].getColor()==options[j])
                userChar[clrPick[i].getSpot()-1]=optChar[j];
        }
    }
    return userChar;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                      Representation of previous picks to user              */
/******************************************************************************/
void reppic(char color[],char pick[],int &nTrys,const char GMELMT,
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
void results(UserColor color[],int &nTrys,const char CNVPERC,
        const char GMELMT,const int SIZE,char userChar[],char comChar[]){
    //Reveals Computer's Choice Once User Guesses
    cout<<"Your colors are ";
    for(int i=0;i<SIZE;i++){
        cout<<color[i].getColor()<<" ";
    }cout<<endl; 
    if(nTrys<=GMELMT&&userChar[0]==comChar[0]&&userChar[1]==comChar[1]&&
                userChar[2]==comChar[2]&&userChar[3]==comChar[3]){
        //Tries Percentage if won 
        cout<<fixed<<setprecision(1);
        cout<<"Your number of tries is "<<nTrys<<endl;
        cout<<"The percentage of the board you got through is ";
        cout<<(float)(nTrys)/(10.0f)*CNVPERC<<"% "<<endl;
    }else
        cout<<"You lose. You could not guess in 10 tries or less."<<endl;
    
}    
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Switch Hints Function                               */
/******************************************************************************/
void switchH(UserColor color[],ComColor pick[],int nTrys,const int SIZE){ 
    int counter=0;
    int count=0;
    bool check=false;
        for(int i=0;i<SIZE;i++){
            if(color[i].getColor()==pick[i].getColor())
                counter++;
        }
        if (counter==1){
            cout<<"One color is in the correct spot."<<endl;
            check=true;

        }else if (counter==2){
            cout<<"Two colors are in the correct spot."<<endl;
            check=true;
        }else if (counter==3){
            cout<<"Three colors are in the correct spot."<<endl;
            check=true;
        }
        else if (counter==4){
            cout<<"You guessed all the colors correctly."<<endl;
            check=true;
        }
        for(int j=0;j<SIZE;j++){
            for(int i=0;i<SIZE;i++){
                if(color[i].getColor()==pick[j].getColor()&&i!=j){
                    count++;
                }
            }
        }
         if (count==1){
            cout<<"One color is correct, but it is not in the correct spot."<<endl;
            check=true;

        }else if (count==2){
            cout<<"Two colors are correct,but they are not in the correct spot."<<endl;
            check=true;
        }else if (count==3){
            cout<<"Three colors are correct, but they are not in the correct spot."<<endl;
            check=true;
        }else if (count==4){
            cout<<"Four colors are correct, but they are not in the correct spot."<<endl;
            check=true;
        }else{
            cout<<"None of these color choices are correct or in the  "; 
            cout<<"right spot."<<endl<<"Try something different."<<endl
                                                                 <<endl;
        }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                         Leader board Function  
 * Function allows for user to enter their name to be sorted onto a leader
 * board, writes the leader file                                              */
/******************************************************************************/
void lder(string name,int score,fstream& out){ 
    out>>name;
    out<<"Top Ten On the Leader board\r"<<endl;
    out<<"UserName\tNumber of Tries\r"<<endl;
    out<<name<<"\t"<< score<<"\r"<<endl;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                         Leader board Function  
 * Function allows for user to enter their name to be sorted onto a leader
 * board, writes the leader file                                              */
/******************************************************************************/
void lderOutput(string name,int score){ 
    cout<<"Top Ten On the Leader board"<<endl;
    cout<<"UserName\tNumber of Tries"<<endl;
    cout<<name<<"\t\t"<< score<<endl;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                         Leader board Function  
 *   This function reads the contents of the Leader board file                */
/******************************************************************************/
void readLdr(fstream& leader,string n){
    if( leader ){
        getline( leader, n );
        while( leader ){
            cout << n << endl;
            getline( leader, n );
        }
    }  
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                           Leader board Function Calls                      */
/******************************************************************************/
void leader(string name,int nTrys,fstream leader){
    cout<<"Please enter a username to be put onto the Leader board "<<endl;
    cin>>name; 
    lderOutput(name,nTrys); //Outputs what is on the leader board
    readLdr(leader,name); //reads the leader file
    lder(name,nTrys,leader);//writes onto the leader file   
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
void markSrt(int *a,int n){
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
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                           Exits the Menu of the Game                       */
/******************************************************************************/
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
