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
    int len = wordArray[random].length();
    std::string hiddenWord= wordArray[random];
    char firstletter = hiddenWord[0];
    head = new Word(firstletter, nullptr, nullptr, false);
    Word *nextletter = head;
    for(int i = 1; i < hiddenWord.length()-1; i++){
        Word *currentletter = new Word(hiddenWord[i], nullptr, nextletter, false);
        nextletter->next = currentletter;
        nextletter = currentletter;
    }
    tail = new Word(hiddenWord[hiddenWord.length()-1], nullptr, nextletter, false);

    std::cout<<"Your word has "<<hiddenWord.length()<<" letters."<<std::endl;
}

std::string Hangman::checkLetter(std::string letter){

}

std::string Hangman::checkWord(std::string word){

}

std::string Hangman::displayGuesses(){

}
