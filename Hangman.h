#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>

struct Word{
    char letterSpot;
    bool guessed;
    Word *next;
    Word *previous;

    Word(){}; // default constructor

    Word(char initSpot, Word *initNext, Word *initPrevious, bool initguess)
    {
        letterSpot = initSpot;
        next = initNext;
        previous = initPrevious;
        guessed = initguess;
    }

};

class Hangman
{
    public:
        Hangman();
        ~Hangman();
        int a = 0;
        void addWord(std::string inword);
        void generateWord();
        std::string checkLetter(std::string);
        std::string checkWord(std::string);
        std::string displayGuesses();
    protected:
    private:
        std::string wordArray[50];
        Word *head;
        Word *tail;
};

#endif // HANGMAN_H
