#include "Hangman.h"
#include <iostream>
#include <locale>

Hangman::Hangman()
{
    //ctor
    Letterhead = nullptr;
    Lettertail = nullptr;
    Wordhead = nullptr;
    Wordtail = nullptr;
}

Hangman::~Hangman()
{
    //dtor
}

void Hangman::addWord(std::string inword){
    wordArray[a] = inword;  //inserting each word into a string array
    a++;
}

void Hangman::generateWord(){   //find a random word inside wordArray
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
}

std::string Hangman::checkLetter(std::string letter){   //user guesses letter
    guessedLetters *guess = Letterhead;
    while(guess != nullptr){
        if(guess->letter == letter){    //if the letter is already in the guessed linked list
            std::cout<<"You have already guessed that letter."<<std::endl;
            return "";
        }
        guess = guess->next;
    }
    Word *tmp = Wordhead;
    char lowletter = letter[0]; //turn everything into lowercase
    int correct = 0;
    while(tmp != nullptr){
        if(tmp->letterSpot == tolower(lowletter)){  //user guessed correctly
            tmp->guessed = true;
            correct++;
        }
        tmp = tmp->next;
    }
    if(correct == 1){
        std::cout<<"There is "<<correct<<" "<<lowletter<<"."<<std::endl;
    }
    else if(correct == 0){
        std::cout<<"There are "<<correct<<" "<<lowletter<<"'s."<<std::endl;
        wrongGuesses++;
        std::cout<<"You have "<<6-wrongGuesses<<" guesses left."<<std::endl;
    }
    else{
        std::cout<<"There are "<<correct<<" "<<lowletter<<"'s."<<std::endl;
    }

    if(wrongGuesses == 6){
        std::cout<<"You have been wrong too many times! You lose!"<<std::endl;
        return "";
    }

    guessedLetters *finder = new guessedLetters(letter, nullptr);   //put guessed letter into a linked list
    guessedletterindex++;
    if(Letterhead == nullptr){
        Letterhead = finder;
        Lettertail = finder;
    }
    else{
        Lettertail->next = finder;
        Lettertail = finder;
    }

    return "";
}

std::string Hangman::checkWord(std::string word){   //user guesses entire word
    Word *tmp = Wordhead;
    int i = 0;
    char c;
    int inputSum = 0;
    while(word[i]){ //summing user input in ASCII
        c = word[i];
        inputSum = inputSum + tolower(c);
        i++;
    }

    int knownSum = 0;
    while(tmp != nullptr){  //summing unknown word in ASCII
        knownSum = knownSum + int(tmp->letterSpot);
        tmp = tmp->next;
    }
    knownSum = knownSum + int(Wordtail->letterSpot);

    if(knownSum == inputSum){   //user guesses word correctly
        std::cout<<"You correctly guessed the word!"<<std::endl;
        Word *temp = Wordhead;
        while(temp != nullptr){
            temp->guessed = true;
            temp = temp->next;
        }
        Wordtail->guessed = true;
    }
    else{
        std::cout<<"You are incorrect!"<<std::endl;
        wrongGuesses++;
        std::cout<<"You have "<<6-wrongGuesses<<" guesses left."<<std::endl;
    }

    if(wrongGuesses == 6){
        std::cout<<"You have been wrong too many times! You lose!"<<std::endl;
        return "";
    }

    guessedLetters *finder = new guessedLetters(word, nullptr); //adds guessed word to linked list
    guessedletterindex++;
    if(Letterhead == nullptr){
        Letterhead = finder;
        Lettertail = finder;
    }
    else{
        Lettertail->next = finder;
        Lettertail = finder;
    }
    return "";
}

std::string Hangman::displayGuesses(){  //shows user's previous guesses
    guessedLetters *temp = Letterhead;
    if(Letterhead == nullptr){
        std::cout<<"You have not guessed anything yet."<<std::endl;
        return "";
    }
    std::cout<<"So far you have guessed: "<<std::endl;
    while(temp != nullptr){
        std::cout<<temp->letter<<std::endl;
        temp = temp->next;
    }
    return "";
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
    if(Wordtail->guessed == true){
        std::cout<<Wordtail->letterSpot;
    }
    else{
        std::cout<<"_";
    }
    std::cout<<std::endl;
    return "";
}

std::string Hangman::displayAnswer(){   //reveals answer to quitters
    Word *finding = Wordhead;
    std::cout<<"The answer is: "<<finding->letterSpot;
    while(finding->next != nullptr){
        std::cout<<finding->next->letterSpot;
        finding = finding->next;
    }
    std::cout<<Wordtail->letterSpot<<std::endl;
    return "";
}

std::string Hangman::displayMan(){  //shows the status of the man
    if(wrongGuesses == 0){
        std::cout<<"No man here!"<<std::endl;
    }
    else if(wrongGuesses == 1){
        std::cout<<" O "<<std::endl;
    }
    else if(wrongGuesses == 2){
        std::cout<<" O "<<std::endl;
        std::cout<<" | "<<std::endl;
        std::cout<<" | "<<std::endl;
    }
    else if(wrongGuesses == 3){
        std::cout<<" O "<<std::endl;
        std::cout<<"<| "<<std::endl;
        std::cout<<" | "<<std::endl;
    }
    else if(wrongGuesses == 4){
        std::cout<<" O "<<std::endl;
        std::cout<<"<|>"<<std::endl;
        std::cout<<" | "<<std::endl;
    }
    else if(wrongGuesses == 5){
        std::cout<<" O "<<std::endl;
        std::cout<<"<|>"<<std::endl;
        std::cout<<" | "<<std::endl;
        std::cout<<"^  "<<std::endl;
    }
    else{
        std::cout<<"I'm dead D:"<<std::endl;
        std::cout<<" O "<<std::endl;
        std::cout<<"<|>"<<std::endl;
        std::cout<<" | "<<std::endl;
        std::cout<<"^ ^"<<std::endl;
    }
    return "";
}

void Hangman::resetGame(){  //required in order to move onto a new game
    a = 0;
    guessedletterindex = 0;
    wordLength = 0;
    wrongGuesses = 0;
    guessedLetters *current = Letterhead;

    do{
        if(Letterhead == nullptr){
            break;
        }
        delete current;
        current = current->next;
    }
    while(current);
    Letterhead = nullptr;
    std::cout<<"Your game has been reset! Guesses left: 6"<<std::endl;
}
