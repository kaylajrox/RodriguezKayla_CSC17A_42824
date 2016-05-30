

#include <iostream>
using namespace std;


int main(int argc, char** argv) {
    string name;
    string answer;
    cout<<"Hi User, please enter your name "<<endl;
    getline(cin,name);
    cout<<"Is this correct? Type out yes or no"<<name<<endl;
    cin>>answer;
    if(answer=="yes"){
        cout<<"Congrats! You win a cruize to Hawii!";
    }else{
        cout<<"Hi User, please enter your name "<<endl;
        getline(cin,name);
    }
    return 0;
}

