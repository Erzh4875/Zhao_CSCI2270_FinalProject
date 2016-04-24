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
    wordArray[a] = inword;
    a++;
}

void Hangman::generateWord(){
    int random = rand() % 49;
    std::cout<<wordArray[random]<<std::endl;
}

std::string Hangman::checkLetter(std::string letter){

}

std::string Hangman::checkWord(std::string word){

}

std::string Hangman::displayGuesses(){

}
