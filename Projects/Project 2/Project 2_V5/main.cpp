/* Author: Kayla Rodriguez
 * Created on January 30, 2016, 8:55 PM
 * Purpose: Mastermind
 * file opening was used on notepad and the format outputs the way it should
 * on notepad
 */
/*
 * Trying to add:
   search function to search the file for username
 sort function for the file
 when i press 1 it doesn't reshow the instructions
 need to add polymorphism
 * need to finish up the class with the data on each person 
 */
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
#include "ComMge.h"
#include "Mastermind_Mge.h"

//Global Constant
const char CNVPERC=100;

//Function Prototypes
char *compic(ComColor*,string[],char[],int);
UserColor *input(string[],const int,char[],string[]);
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
void game(fstream&,fstream&,fstream&,string&);
void leader(string,int,fstream);
void Menu();
void def(int);
int getN();
void endGme(); //displays end game message
void message();//Game Logo
void plyerInfo(fstream);//play information 
void findPlyr(); //find the player
void filePlyr(fstream,string); //display player file

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
    string name; //holds contents of leader file 
    fstream player; //holds player information
    
    //menu variables
    int inN;
    bool reDsply=true;
    
    //Open the Files
    infile.open("instructions.txt", ios::in|ios::binary);
    out.open("results.txt",ios::out|ios::binary);
    leader.open("leader.txt",ios::in|ios::out);
    player.open("playerStats.txt",ios::in|ios::out);
    
    //redisplay menu if user chooses to
    do{
        Menu();
        inN=getN();
        
        //Player inputs their information to be outputted on a file
//         plyerInfo();
    
        switch(inN){
            case 1:    //Read the File and Output its contents (the introduction)
                       readFile(infile,instr);break; 
            case 2:    game(infile,out,leader,name);break; //doesn't work
            case 3:{     //reads the leader board and outputs its contents
                cout<<"LeaderBoard"<<endl<<endl;
                cout<<"Username\tScore"<<endl;
                readLdr(leader,name);break;}
            case 4:    message();break;
            case 5:{
                //pass name into player output file
            }
        default:   {def(inN);
                    reDsply=false;}
        }
    }while(reDsply);
    
    //close the files
    infile.close();
    out.close();
    leader.close();
    player.close();
    
    return 0;//If midterm not perfect, return something other than 1
}
/*******************************************************************************
 *       Menu Function- Displays Options to Choose from in the game
 ******************************************************************************/
void Menu(){
    cout<<"\nMenu for Mastermind"<<endl;
    cout<<"Type 1 for the instructions"<<endl;
    cout<<"Type 2 for to play the game"<<endl;
    cout<<"Type 3 to see the contents of the leader board"<<endl;
    cout<<"Type 4 to see the Mastermind Picture"<<endl;
    cout<<"Type 5 if you want to see your stats "<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}
/*******************************************************************************
 *                  Integer response to the Menu
 ******************************************************************************/
int getN(){
        int inN;
        cin>>inN;
        return inN;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                                Play Mastermind                             */
/******************************************************************************/   
void game(fstream& infile,fstream& out,fstream& leader,string& name){
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
    ComColor *cColor; //pointer of computer colors
    char *comChar; //pointer of computer colors written in characters
    
    //Counters and Object variables
    int nTrys=0;//number of tries counter
    char choice; //choice on whether or not to increment turns
    UserColor limit; //object to be incremented using overloaded operator
    char repeat; //allows the user to play again
    ComColor outcome; //game outcome stats
    int win=1; //win for the player
    int lose=1; //lose for the player
    
    //Open the Files
    infile.open("instructions.txt", ios::in|ios::binary);
    out.open("results.txt",ios::out|ios::binary);
    leader.open("leader.txt",ios::in|ios::out);
    
    //repeat the game if user wishes
    do{      
        //Allocate Memory for computer colors
        cColor = new ComColor[SIZE]; //Computer generated random pick
        
        //computer's colors in character representation
        comChar = compic(cColor,options,optChar,SIZE);//allocate memory
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
                cout<<"Please enter a username to be put onto the Leader board "<<endl;
                cin>>name; 
                lderOutput(name,nTrys); //Outputs what is on the leader board
                readLdr(leader,name); //reads the leader file
                lder(name,nTrys,leader);//writes onto the leader file 
                outcome.setWin(win);
                break;
            }
            else if(nTrys==gmelmt){
                outcome.setLose(lose);
                cout<<"You have reached the game limit and still have not guessed ";
                cout<<"the correct colors, which means you have lost the game. "<<endl;
                cout<<"Would you like to keep guessing anyway and increment your ";
                cout<<"turn number? Enter y for yes and anything else for no."<<endl;

                //determines whether the game limit will be incremented
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

        //End the Game Message
        endGme();
        cout<<"Would you like to play again? Type y for yes and anything else";
        cout<<" for no."<<endl;
        cin>>repeat;
        repeat=tolower(repeat);
    }while(repeat=='y');
    
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
char *compic(ComColor *cColor,string options[],char optChar[],int SIZE){
    char *temp = new char[SIZE];
    vector<bool> cPick(8,0);
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
UserColor *input(string order[],const int SIZE,char optChar[],string options[]){
    UserColor *clrPick=new UserColor[SIZE];
    bool set[SIZE];
    bool v=true; //validation
    int spot;
    string color;
    for(int i = 0; i < SIZE; i++)
    {
        set[i] = false;
    }
    for (int i=0;i<SIZE;i++){
        cout<<"Pick your "<<order[i]<<" color"<<endl;
        cin>>color;
        for (int j=0;j<color.size();j++){
            color[j]=tolower(color[j]);
        }
        //utilizing an exception to check the color
        while(v){
           try{
                clrPick[i].setColor(color);
                v=false;
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
/*                          Print a End Game Message
 *  Purpose: Demonstrate template Using a string to output a message          */
/******************************************************************************/
void endGme(){
    //set the variable in the template
    ComMge <string>mge("You have reached the end of the game, thanks for playing!");
    cout<<mge.prntMge();
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Print Mastermind Logo                          */
/******************************************************************************/
void message(){
    //declare template variables
    Mastermind_Mge <string>mgeM("****            ****\n*****          *****\n"
    "******        ******\n*******      *******\n********    ********\n"
    "****  ***  ***  ****\n****    ****    ****\n****     **     ****\n"
    "****            ****\n");
    Mastermind_Mge <string>mgeA("****************\n****************\n******    ******\n"
    "******    ******\n****************\n****************\n******    ******\n"
    "******    ******\n******    ******\n******    ******\n");
    Mastermind_Mge <string>mgeS("  ************  \n ************** \n****************\n"
    "****        ****\n****            \n**************  \n ************** \n  **************\n            ****\n"
    "****        ****\n****************\n ************** \n  ************  \n");
    Mastermind_Mge <string>mgeT("****************\n****************\n****************\n"
    "     *****      \n     *****      \n     *****      \n     *****      \n     *****      \n"
    "     *****      \n     *****      \n     *****      \n");
    Mastermind_Mge <string>mgeE("****************\n****************\n****************\n"
    "*****           \n************    \n************    \n************    \n"
    "*****           \n****************\n****************\n****************\n");
    Mastermind_Mge <string>mgeR("****************\n****************\n****************\n"
    "*****      *****\n*****      *****\n*************** \n**************  \n"
    "*****   ******  \n*****    ****** \n*****    ****** \n*****      *****\n"
    "*****       ****\n");
    Mastermind_Mge <string>mgeI("****************\n****************\n****************\n"
    "     ******     \n     ******     \n     ******     \n     ******     \n"
    "****************\n****************\n****************\n");
    Mastermind_Mge <string>mgeN("*****       ****\n******      ****\n*******     ****\n"
    "********    ****\n**** ****   ****\n**** *****  ****\n****  ***** ****\n"
    "****   *********\n****    ********\n*****    *******\n");
    Mastermind_Mge <string>mgeD(" ************\n*****************   \n******************    \n"
    "*****         ******   \n*****          *******  \n*****           ******* \n"
    "*****           *******\n*****          ********\n*****         ********* \n"
    "*****        ********  \n*****       *******   \n******************    \n"
    "*****************\n ************\n");
    
    //Output the Mastermind Display Message
    cout<<mgeM.prntMge()<<endl<<mgeA.prntMge()<<endl<<mgeS.prntMge()<<endl;
    cout<<mgeT.prntMge()<<endl<<mgeE.prntMge()<<endl<<mgeR.prntMge()<<endl;
    cout<<mgeM.prntMge()<<endl<<mgeI.prntMge()<<endl<<mgeN.prntMge()<<endl;
    cout<<mgeD.prntMge();   
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                           Exits the Menu of the Game                       */
/******************************************************************************/
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                Player Information To be Stored onto a File                 */
/******************************************************************************/
void plyerInfo(fstream pFile){
    //declare variables
    ComColor plyrInfo; //object to hold player's information
    string name; //player's username
    cout<<"Enter your username "<<endl;
    cin>>name;
    plyrInfo.setName(name);
    pFile>>name;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Find the Username that was given                     */
/******************************************************************************/
//void findPlyr(){
//    //declare search variables
//    int search;
//    string username[];
//    
//    cout<<"Type in your username to search "<<endl;
//    cin>>username;
//    selectS(string username[]);
//    search=binaryS();
//}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*           Write Player File that Stores the Data on each player            */
/******************************************************************************/
//void filePlyr(fstream infile,string instr){
//    if( infile ){
//        getline( infile, instr );
//        while( infile ){
//            cout << instr << endl;
//            getline( infile, instr );
//        }
//    }   
//}
//******************************************************************************
//                     Definition of Selection Sort
//******************************************************************************
//void selectS(string names[]){
//    //Declare Variables
//    int strScan, mini; 
//    string minval;
//    for (strScan=0;strScan < (NAMES-1); strScan++){
//        mini=strScan;
//        minval = names[mini];
//        for (int i=strScan+1;i<NAMES;i++){
//            if (names[i]<minval){
//                minval=names[i];
//                mini=i;
//            }
//        }
//        string temp=names[strScan];
//        names[strScan]=minval;
//        names[mini]=temp;
//    }
//
//    cout<<endl;
//}
//******************************************************************************
//                  Definition of function Binary Sort
//******************************************************************************
//int binaryS(string names[],string sNames){
//    int pos = -1,first = 0,last = (NAMES-1);
//    int middle;                       
//    bool found = false;    // Flag
//
//    while (!found && first <= last){
//        middle = (first + last) / 2; // Calculate midpoint
//        if (names[middle] == sNames){ // If value is found at mid
//            pos = middle;
//            found = true;            
//        }
//        else if (names[middle] > sNames){ // If value is in lower half
//            last = middle - 1;
//        }
//        else{
//            first = middle + 1; // If value is in upper half
//        }
//    }
//    return pos;
//} 