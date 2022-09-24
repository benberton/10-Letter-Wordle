//
// Created by BBert on 4/20/2022.
//

#include "Game.h"

Game::Game(int dayNum)
{
    wordle = new Wordle(dayNum);
    string guess;
    wordle->printBoard();
    while (!wordle->isGuessed() && wordle->guessesLeft())
    {
        cout << "Enter Guess" << endl;
        cin >> guess;
        wordle->guessWord(guess);
        wordle->printBoard();
    }
    cout << "Word is: " << wordle->getKeyWord() << endl;
}