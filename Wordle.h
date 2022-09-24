//
// Created by BBert on 4/19/2022.
//

#ifndef WORDLE_WORDLE_H
#define WORDLE_WORDLE_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>
using namespace std;

class Wordle{
public:
Wordle(int);
void guessWord(string);
string getKeyWord();
void printBoard();
bool isGuessed();
bool guessesLeft();
private:
    void setBoard();
    void setKeyWord(int);
    bool checkTokens(string);
    int getCount();
    bool isInFile(string);

    string keyWord;
    char board[6][10][2];
    int attemptNum;
    string wordFile;
    bool wordGuess = false;
    //if you change the number of allowed attempts also change the size in the board
    int attemptQuantity = 6;
};


#endif //WORDLE_WORDLE_H
