//System Libraries
#include <bits/stdc++.h>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv){    
    //Open the File and Declare/Initialize variables
    ifstream infile;
    infile.open("input.txt");
    ofstream outfile;
    outfile.open("output.txt");
    string fileIn,fileOut;
    //boolean to flag end of sentence
    bool isfirst=true;
    //check if file can open
    cout << "This program changes all letters after a period to uppercase"
            << endl;
     //get user input for an input file name
    cout << "Enter a file name you would like to read from" << endl;
    getline(cin,fileIn);
    infile.open(fileIn.c_str());
     // get user input for an output file name
    cout << "Enter a file name you would like to save the revised version " << endl;
    cin >> fileOut;
    outfile.open(fileOut.c_str());
    //Reading the first character
    char ch=infile.get();
    if (infile){
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

    return 0;
}