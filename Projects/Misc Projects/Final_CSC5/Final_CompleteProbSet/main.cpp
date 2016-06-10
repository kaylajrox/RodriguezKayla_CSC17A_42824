/* 
    File:   main.cpp
    Author: Kayla Rodriguez
    Created on February 3, 2016, 8:35 PM
    Purpose:  Final Problem Set 
 */

//System Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>  //Random Functions
#include <ctime>    //Setting the seed with time
using namespace std;

//User Libraries

//Global Constants
const int COLS=7;
//Function prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void comPickG(int&);
void mxGuess(int&,int&);
void fillVec(vector<int>&,vector<int>&,int);
void prntVec(vector<int>&,vector<int>&,int);
int num1(int[]);
int num2(int[]);
void readFil(string[],int,ifstream&);
void selectS(string[],int);
void shArray(string[],int);
void prntTble(int [][COLS],int&,int);
void sumTble(int [][COLS],int);
void rdTble(int [][COLS],int,ifstream&);
void WtTble(int[][COLS],int,ofstream&);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned short nSoltn;//Problem Solution to display
    bool reDsply=true;    //Exit program when false
    
    //Menu to Display Solution
    do{
        //Input problem to display, i.e. Menu
        cout<<"\nFinal Problem Set "<<endl;
        cout<<"Type 1 to Display Problem 1"<<endl;
        cout<<"Type 2 to Display Problem 2"<<endl;
        cout<<"Type 3 to Display Problem 3"<<endl;
        cout<<"Type 4 to Display Problem 4"<<endl;
        cout<<"Type 5 to Display Problem 5"<<endl;
        cout<<"Type 6 to Display Problem 6"<<endl;
        cout<<"Type anything else to exit "<<endl<<endl;
        cin>>nSoltn;
        //Solutions to all the problems
        switch(nSoltn){
            case 1:{problem1();break;}
            case 2:{problem2();break;} 
            case 3:{problem3();break;}
            case 4:{problem4();break;}
            case 5:{problem5();break;}
            case 6:{problem6();break;}
            default:{
                cout<<"Exiting the Program"<<endl;
                reDsply=false;
            }
        }
    }while(reDsply);

    //Exit Stage Right
    return 0;
}
/******************************************************************************/
/************************** Problem 1 *****************************************/
/******************************************************************************/
void problem1(){
    cout<<endl<<"Final Problem 1"<<endl;
    cout<<endl<<"Unsigned Short to short reverse Conversion"<<endl<<endl;
    //Declare and initialize variables
    //Declare and initialize
    unsigned char  n10000s,n1000s,n100s,n10s,n1s;//Number of 10^x's               //Arabic number, regular year
    int number;
    bool possible=true;
    //Input
    cout<<"Enter a number between 0-65,535. This is the range for an unsigned";
    cout<<endl;
    cout<<"short. This number will then be reversed and given as a signed short.";
    cout<<endl;
    cin>>number;
    
    //Calculate the number of 1000's,100's,10's,1's
    n10000s=(number-number%10000)/10000;//Number of 1000's
    number=(number-n10000s*10000);     //Subtract off 1000's
    n1000s=(number-number%1000)/1000;//Number of 1000's
    number=(number-n1000s*1000);     //Subtract off 1000's
    n100s =(number-number%100)/100;  //Number of 100's
    number=(number-n100s*100);       //Subtract off 100's
    n10s  =(number-number%10)/10;    //Number of 10's
    n1s   =(number-n10s*10);         //Subtract off 10's to get 1's
    if (n10000s>6){
        possible=false;
        cout<<"Conversion not possible.";
    }else if (n10000s==6&&n1000s>5){
        possible=false;
        cout<<"Conversion not possible.";
    }else if (n10000s==6&&n1000s==5&&n100s>5){
        possible=false;
        cout<<"Conversion not possible.";
    }else if (n10000s==6&&n1000s==5&&n100s==5&&n10s>3){
        possible=false;
        cout<<"Conversion not possible.";
    }else if (n10000s==6&&n1000s==5&&n100s==5&&n10s==3&&n1s>5){
        possible=false;
        cout<<"Conversion not possible.";
    }else if (n10000s==0&&n1000s==0&&n100s==0&&n10s==0&&n1s>3){
        possible=false;
        cout<<"Conversion not possible.";
    }
    if (possible){        
        //Output the results
        cout<<"Your number has been reversed to ";
         if(n10000s>=4&&n1s>=4){
            cout<<"No conversion possible."<<endl;
        }else if (n1s==0&&n1000s==0&&n10s==0&&n100s==0){
            //Output the 1's
            switch(n1s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
            }
            //Output number of 10000's
            switch(n10000s){
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;               
            }
        }else if (n10000s==0&&n100s==0&&n10s==0&&n1s==0){
            //Output the 1's
            switch(n1s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
            }
           
            //Output the 1000's
            switch(n1000s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
            }
        }else if (n10000s==0&&n1000s==0&&n10s==0&&n1s==0){
            //Output the 1's
            switch(n1s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
            }
            //Output the 100's
            switch(n100s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
            }
        }
        else if (n10000s==0&&n1000s==0&&n100s==0&&n1s==0){
            //Output the 1's
            switch(n1s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
            }
              //Output the 10's
            switch(n10s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
            }           
        }else if (n10000s==0&&n1000s==0&&n100s==0&&n10s==0){
            //Output the 1's
            switch(n1s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
                case 0:  cout<<"0";break;
            }
              //Output the 10's
            switch(n10s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
                case 0:  cout<<"0";break;
            }
            //Output the 100's
            switch(n100s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
                case 0:  cout<<"0";break;
            }
            //Output the 1000's
            switch(n1000s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
                case 0:  cout<<"0";break;
            }
            //Output number of 10000's
            switch(n10000s){
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
                case 0:  cout<<"0";break;
            }
        }    
    else if(n10000s==0&&n1000s==0){
            //Output the 1's
            switch(n1s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
            }
              //Output the 10's
            switch(n10s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
                case 0:  cout<<"0";break;
            }
            //Output the 100's
            switch(n100s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
            }
        }else {
            //Output the 1's
            switch(n1s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
            }
              //Output the 10's
            switch(n10s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
                case 0:  cout<<"0";break;
            }
            //Output the 100's
            switch(n100s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
                case 0:  cout<<"0";break;
            }
            //Output the 1000's
            switch(n1000s){
                case 9:  cout<<"9";break;
                case 8:  cout<<"8";break;
                case 7:  cout<<"7";break;
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
                case 0:  cout<<"0";break;
            }
            //Output number of 10000's
            switch(n10000s){
                case 6:  cout<<"6";break;
                case 5:  cout<<"5";break;
                case 4:  cout<<"4";break;
                case 3:  cout<<"3";break;
                case 2:  cout<<"2";break;
                case 1:  cout<<"1";break;
            }
        }    
    }        
}
/******************************************************************************/
/************************** Problem 2 *****************************************/
/******************************************************************************/
void problem2(){
    //The problem to solve
    cout<<endl<<"Solution to Problem 2"<<endl;
    cout<<endl<<"Guess My Number"<<endl<<endl;
    //Initialize the seed
    srand(static_cast<unsigned int>(time(0)));
//Declare and initialize variables
    int guess;   //Initial guess
    int guess1;  //Every guess after the initial guess
    int comPick; //computer generated guess
    int maxG;    //Maximum amount of guesses
    char choice;
    //Introduction
    do{
        cout<<"Guess my number! "<<endl;
        cout<<"I have a number between 1 and 100. "<<endl;
        cout<<"You will be given "; 
        mxGuess(maxG,guess);
        cout<<"guesses. If you go over, you do not win."<<endl;
        comPickG(comPick);
        cout<<"Please type your first guess."<<endl;
        cin>>guess;
        //Decisions on Initial Guess
        if (guess==comPick){
            cout<<"Congratulations, You guessed the number!"<<endl;
            cout<<"Please retype your guess. "<<endl;
        }else if (guess<comPick){
                cout<<"Too low. Try again."<<endl;
        }else if (guess>comPick){
            cout<<"Too high. Try again."<<endl;
        }
        //Any guesses After the First
        while (!(guess1==comPick)){
            int nTrys=1;
            nTrys++;
            cout<<"Please type your next guess."<<endl;
            cin>>guess1;          
            if (guess1==comPick){
                if (nTrys>maxG){
                    cout<<"Too many tries. "<<endl;
                }
                else{
                    cout<<"Congratulations, you guessed the number!"<<endl;
                }    
            }else if (guess1<comPick){
                cout<<"Too low. Try again."<<endl;
            }else{
                cout<<"Too high. Try again."<<endl;
            }  
        }
        //Repeat program?
        cout<<"Would you like to play again(y or n)?"<<endl;
        cout<<"y=yes anything else to exit"<<endl;
        cin>>choice;
    }while (choice=='y');
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                           Array Output                                     */
/******************************************************************************/
void comPickG(int &comPick){
    comPick=rand()%101;//[1,100]   
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                          Calculate Max Guesses                             */
/******************************************************************************/
void mxGuess(int &maxG,int &guess){
    maxG=2*log(10)/log(2);
    cout<<maxG<<endl;
}
/******************************************************************************/
/************************** Problem 3 *****************************************/
/******************************************************************************/
void problem3(){
    //The problem to solve
    cout<<endl<<"Solution to Problem 3"<<endl;
    cout<<endl<<"Filling Vectors"<<endl<<endl;
    //Initialize the seed
    srand(static_cast<unsigned int>(time(0)));
//Declare and initialize variables
    int size;
    vector<int> even(size); //Even Vector
    vector<int> odd(size);  //Odd Vector
    //Input
    cout<<"This program sorts random even and odd four digut numbers into their ";
    cout<<"own vectors. "<<endl;
    cout<<"Enter the size of your vector: ";
    cin>>size;
    //Function Outputs
    fillVec(even,odd,size);
    prntVec(even,odd,size);
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                              Fill Vector                                   */
/******************************************************************************/
void fillVec(vector<int>&even,vector<int>&odd,int size){
    int evenNum; 
    int oddNum; 
    for(int i=0;even.size()<size;i++){
        evenNum=rand()%1001+1000;
        if(evenNum%2==0){
            even.push_back(evenNum);
        }                   
    }
    for(int i=0;odd.size()<size;i++){
        oddNum=rand()%1001+1000; 
        if(oddNum%2!=0){
            odd.push_back(oddNum);
        }         
    }
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Print Even and Odd Numbers                          */
/******************************************************************************/
void prntVec(vector<int>&even,vector<int>&odd,int size){
    //Display Rows and Columns
    int cols;
    int COLS=2;
    int numbers[size][cols]={even[size],odd[size]};   
    cout<<"\nEvens\tOdds"<<endl;
    for(int i=0;i<size;i++){      
        cout<<even[i]<<"    ";
        if (even[i]<10)
           cout<<" ";
        cout<<odd[i];
        if (odd[i]<10)
            cout<<" ";
            cout<<"     ";
       cout<<endl;
    }
    cout<<endl<<"How many columns would you like to be displayed? ";
    cin>>cols;
    for(int i=0;i<cols;i++){
        cout<<even[i]<<" ";
    }cout<<endl;
    for(int i=0;i<cols;i++){
        cout<<odd[i]<<" ";
    }cout<<endl;
    
}


/******************************************************************************/
/************************** Problem 4 *****************************************/
/******************************************************************************/
void problem4(){
   cout<<endl<<"Solution to Problem 4"<<endl;
   cout<<endl<<"Frequency of Sums"<<endl<<endl;
   //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variable
    const char SIZE=5;
    int list[SIZE]={9,61,88,101,121}; //list to choose from
    int sum; //Sum of two random numbers picked from the list
    int sumList[15]={18,70,97,110,130,122,149,162,182,176,
    189,209,202,222,242};//All the possible sum combinations from the list
    int LOOPS=1000000; //given number of loops
    int freq[15]={0};//starting frequency array
        for(int i=0;i<LOOPS;i++){
            sum=num1(list)+num2(list);
            for(int j=0;j<15;j++){
                if (sum==sumList[j]){
                    freq[j]++;
                }
            }
        }   
    for(int i=0;i<15;i++){
        cout<<"The frequency of "<<sumList[i]<<" was "<<freq[i]<<endl;
    }  
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                       Randomly Choosen Number Functions                    */
/******************************************************************************/
int num1(int list[]){
    int index=rand()%5;
    return list[index];   
}
int num2(int list[]){
    int index=rand()%5;
    return list[index];   
}
/******************************************************************************/
/************************** Problem 5 *****************************************/
/******************************************************************************/
void problem5(){
    cout<<endl<<"Solution to Problem 5"<<endl;
    cout<<endl<<"String Sorting from a file"<<endl<<endl;
    //Define an array with unsorted values
    ifstream infile;
    int NAMES=10;
    string names[NAMES];
    //Open the Files
    infile.open("input.txt");
       
    //Read the File
    readFil(names,NAMES,infile);
    
    //Display the values
    cout<<"The unsorted values are: "<<endl;
    shArray(names,NAMES);
    
    //Sort the values
    selectS(names,NAMES);
    
    //Display the values again
    cout<<"The sorted values are: "<<endl;
    shArray(names,NAMES);
    
    //Output sorted values to a table
    ofstream out;
    out.open("output.txt");
    for(int count=0;count<NAMES;count++){
        out<<names[count]<<" ";
        out<<endl;
    }out<<endl;
    //Close the Files
    out.close();
    infile.close();
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Read the File                                  */
/******************************************************************************/
void readFil(string names[], int NAMES, ifstream& infile){
    for (int i=0;i<NAMES;i++){
        infile>>names[i];
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                              Sort the Array                                */
/******************************************************************************/
void selectS(string names[],int NAMES){
    //Declare Variables
    int strScan, mini; 
    string minval;
    for (strScan=0;strScan < (NAMES-1); strScan++){
        mini=strScan;
        minval = names[mini];
        for (int i=strScan+1;i<NAMES;i++){
            if (names[i]>minval){
                minval=names[i];
                mini=i;
            }
        }
        string temp=names[strScan];
        names[strScan]=minval;
        names[mini]=temp;
    }
    cout<<endl;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                                Show Array                                  */
/******************************************************************************/
void shArray(string names[],int NAMES){
    for(int count=0;count<NAMES;count++){
        cout<<names[count]<<" ";
        cout<<endl;
    }cout<<endl;
}
/******************************************************************************/
/************************** Problem 6 *****************************************/
/******************************************************************************/
void problem6(){
    cout<<endl<<"Solution to Problem 6"<<endl;
    cout<<endl<<"Augmented 2D Array"<<endl<<endl;
    //Declare Variables
    const int ROWS=6; //number of rows originally
    int table[ROWS][COLS]={0}; //original table declared
    int count=0; //counter
    
    //Open the file
    ifstream infile;
    infile.open("table.txt");
    
    //Read the file 
    rdTble(table,ROWS,infile);
   
    //Print Input Table
    cout<<"         Input Table "<<endl;
    prntTble(table,count,ROWS);

    //Sum Input table
    sumTble(table,ROWS);
    
    cout<<"          Augmented Table "<<endl;
    //Print Augmented Table
    prntTble(table,count,ROWS);

    //Output Augmented Table to File
    ofstream out;
    out.open("augtable.txt");

    //Write the Output file
    WtTble(table,ROWS,out);
    
    //Close the Files
    infile.close();
    out.close();     
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Read the File                                  */
/******************************************************************************/
void rdTble(int table[][COLS],int ROWS,ifstream& infile){
    for(int i=0;i<ROWS-1;i++){
        for(int j=0;j<COLS-1;j++){
            infile>>table[i][j];
        }
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                               Sum Table                                    */
/******************************************************************************/
void sumTble(int table[][COLS],int num){
    //Total Sum of Columns
    for(int i=0;i<num;i++){
        for(int j=0;j<COLS-2;j++){
            table[num-1][i]+=table[j][i];
        }
    }   
    //Total Sum of Rows
    for(int i=0;i<COLS-1;i++){
        for(int j=0;j<COLS-1;j++){
            table[i][COLS-1]+=table[i][j];
        }
    }     
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Print Table                                    */
/******************************************************************************/
void prntTble(int table[][COLS],int &count,int num){
    //Printing the rows and columns separately
    if(count==0){
        for(int i=0;i<num-1;i++){
            for(int j=0;j<COLS-1;j++){
                cout<<setw(5)<<table[i][j];
                if(j%(COLS-1)==(COLS-2)){
                    cout<<endl;
                }
            }
        }
    cout<<endl;
    count++;
    return;
    }     
    if(count==1){
        for(int i=0;i<num;i++){
            for(int j=0;j<COLS;j++){
                cout<<setw(5)<<table[i][j];
                if(j%(COLS)==(COLS-1)){
                    cout<<endl;
                }
            }
        }
    cout<<endl;
    }
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                             Write the File                                  */
/******************************************************************************/
void WtTble(int table[][COLS],int ROWS,ofstream& out){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            out<<table[i][j]<<"   ";
            if(j%(COLS)==(COLS-1)){
                out<<endl;
            }
        }
    }
}
