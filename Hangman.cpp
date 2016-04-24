#include "Hangman.h"
#include <iostream>

Hangman::Hangman()
{
    //ctor
}

Hangman::~Hangman()
{
    //dtor
}

void Hangman::addWord(std::string inword){
    for(int i = 0; i < 50; i++){
        wordArray[i] = inword;
    }
}

void Hangman::generateWord(){

}

std::string Hangman::checkLetter(std::string letter){

}

std::string Hangman::checkWord(std::string word){

}

std::string Hangman::displayGuesses(){

}
