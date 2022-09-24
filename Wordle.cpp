//
// Created by BBert on 4/19/2022.
//

#include "Wordle.h"

Wordle::Wordle(int dayNum)
{
    wordFile = "wordFile.txt";
    setKeyWord(dayNum);
    setBoard();
    attemptNum = 0;
}

void Wordle::guessWord(string guessWord)
{

    //making guessWord uppercase
    for (int i = 0; i < guessWord.size(); i++)
    {
        if (islower(guessWord[i]))
            guessWord[i] = toupper(guessWord[i]);
    }

    if (!checkTokens(guessWord))
        return;

    for (int i = 0; i < keyWord.size(); i++)
    {
        board[attemptNum][i][0] = guessWord[i];
        board[attemptNum][i][1] = '0';
        for (int j = 0; j < keyWord.size(); j++)
        {
            if(guessWord[i] == keyWord[j])
                board[attemptNum][i][1] = '1';
        }
        if (guessWord[i] == keyWord[i])
            board[attemptNum][i][1] = '2';
    }
    attemptNum++;
    if(guessWord == keyWord)
        wordGuess = true;
}

bool Wordle::checkTokens(string guessWord)
{
    bool valid = false;
    if(wordGuess)
        cout << "ERROR: WORD CORRECTLY GUESSED" << endl;
    else if (guessWord.size() != keyWord.size())
        cout << "ERROR: WORD SIZE NOT VALID" << endl;
    else if (!isInFile(guessWord))
        cout << "ERROR: WORD IS NOT VALID" << endl;
    else
        valid = true;
    return valid;
}

bool Wordle::isInFile(string guessWord)
{
    fstream inFile;
    inFile.open(wordFile,ios::in);
    string word;
    while (inFile >> word)
    {
        if (word == guessWord)
            return true;
    }
    inFile.close();
    return false;
}

void Wordle::setKeyWord(int dayNum)
{
    int wordCount = getCount();
    dayNum = dayNum % wordCount;
    fstream inFile;
    inFile.open(wordFile,ios::in);
    string word;
    for (int i = 0; i < dayNum; i++)
        inFile >> word;
    keyWord = word;
    inFile.close();
}

int Wordle::getCount()
{
    fstream inFile;
    inFile.open(wordFile,ios::in);
    string word;
    int count = 0;
    while (getline(inFile,word))
        count++;
    inFile.close();
    return count;
}

void Wordle::printBoard()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,3);
    cout << "     10 LETTER WORD WORDLE" << endl;

    for (int i = 0; i < attemptQuantity; i++)
    {
        for (int j = 0; j < keyWord.size(); j++)
        {
            if (board[i][j][1] == '1')
                SetConsoleTextAttribute(hConsole,224);
            else if (board[i][j][1] == '2')
                SetConsoleTextAttribute(hConsole,BACKGROUND_GREEN);
            else
                SetConsoleTextAttribute(hConsole,BACKGROUND_INTENSITY);
            cout << " " << board[i][j][0] << " ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole,3);
    if (wordGuess)
        cout << "CORRECT WORD GUESSED!" << endl;
}

void Wordle::setBoard()
{
    for (int i = 0; i < attemptQuantity; i++)
    {
        for (int j = 0; j < keyWord.length(); j++)
        {
            board[i][j][0] = ' ';
        }
    }
}

string Wordle::getKeyWord()
{
    return keyWord;
}

bool Wordle::isGuessed()
{
    if (wordGuess)
        return true;
    return false;
}

bool Wordle::guessesLeft()
{
    if(attemptNum > attemptQuantity - 1)
    {
        cout << "ERROR: OUT OF ATTEMPTS" << endl;
        return false;
    }
    return true;
}