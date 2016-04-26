#include "Hangman.h"
#include <iostream>
#include <locale>

Hangman::Hangman()
{
    //ctor
    Letterhead = nullptr;
    Lettertail = nullptr;
}

Hangman::~Hangman()
{
    //dtor
}

void Hangman::addWord(std::string inword){
    wordArray[a] = inword;  //inserting each word into a string array
    a++;
}

void Hangman::generateWord(){
    int random = rand() % 49;
    int wordLength = wordArray[random].length();
    std::string hiddenWord= wordArray[random];
    char firstletter = hiddenWord[0];
    Wordhead = new Word(firstletter, nullptr, nullptr, false);  //Building a linked list with each node being a letter
    Word *nextletter = Wordhead;
    for(int i = 1; i < hiddenWord.length()-1; i++){
        Word *currentletter = new Word(hiddenWord[i], nullptr, nextletter, false);
        nextletter->next = currentletter;
        nextletter = currentletter;
    }
    Wordtail = new Word(hiddenWord[hiddenWord.length()-1], nullptr, nextletter, false);

    std::cout<<"Your word has "<<hiddenWord.length()<<" letters."<<std::endl;
    std::cout<<wordArray[random]<<std::endl;

    /*for(int i = 0; i < 26; i++){
        guessedLetter[i] = 0;
    }
    guessedletterindex = 0;*/
}

std::string Hangman::checkLetter(std::string letter){
    Word *tmp = Wordhead;
    char lowletter = letter[0];
    int correct = 0;
    /*for(int i = 0; i < guessedletterindex; i++){
        if(guessedLetter[i] == tolower(lowletter)){
            std::cout<<"You have already guessed that letter."<<std::endl;
            break;
        }
    }*/
    while(tmp != nullptr){
        if(tmp->letterSpot == tolower(lowletter)){
            tmp->guessed = true;
            correct++;
        }
        tmp = tmp->next;
    }
    if(correct == 1){
        std::cout<<"There is "<<correct<<" "<<lowletter<<"."<<std::endl;
    }
    else{
        std::cout<<"There are "<<correct<<" "<<lowletter<<"'s."<<std::endl;
    }

    guessedLetters *finder = new guessedLetters(letter, nullptr);
    if(Letterhead == nullptr){
        Letterhead = finder;
        Lettertail = finder;
    }
    else{
        Lettertail->next = finder;
        Lettertail = finder;
    }
}

std::string Hangman::checkWord(std::string word){
    Word *tmp = Wordhead;
    int i = 0;
    char c;
    int inputSum = 0;
    while(word[i]){
        c = word[i];
        inputSum = inputSum + tolower(c);
        i++;
    }

    int knownSum = 0;
    while(tmp != nullptr){
        knownSum = knownSum + int(tmp->letterSpot);
        tmp = tmp->next;
    }
    knownSum = knownSum + int(Wordtail->letterSpot);

    if(knownSum == inputSum){
        std::cout<<"You correctly guessed the word!"<<std::endl;
    }
    else{
        std::cout<<"You are incorrect!"<<std::endl;
    }
}

std::string Hangman::displayGuesses(){

}

std::string Hangman::displayProgress(){
    Word *temp = Wordhead;  //Shows user how complete their word is
    std::cout<<"Here's how much progress you've made."<<std::endl;

    while(temp != nullptr){
        if(temp->guessed == true){
            std::cout<<temp->letterSpot;
        }
        else{
            std::cout<<"_";
        }
        temp = temp->next;
    }
}
