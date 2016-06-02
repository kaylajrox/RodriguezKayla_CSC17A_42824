/* 
 * File:   ComColor.cpp
 * Author: Kayla
 * Created on April 30, 2016, 3:25 PM
 */

#include "ComColor.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

ComColor::ComColor(): Color(){
    name="";
    games=0;
    win=0;
    lose=0;
}
void ComColor::setName(string x){
    name=x; 
}
void ComColor::setGames(int x){
    games=x;
}
void ComColor::setWin(int x){
    win=x;
}
void ComColor::setLose(int x){
    lose=x;
}
int ComColor::getGames(){
    return games;
}
int ComColor::getWin(){
    return win;
}
int ComColor::getLose(){
    return lose;
}
string ComColor::getName(){
    return name;
}

void ComColor::print2(){
    cout<<"Player Stats: "<<endl;
    cout<<"Username: "<<getName()<<endl;
    cout<<"Games Played: "<<getGames()<<endl;
    cout<<"Wins: "<<getWin()<<endl;
    cout<<"Losses: "<<getLose()<<endl;
}


