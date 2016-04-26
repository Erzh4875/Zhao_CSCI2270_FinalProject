#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "Hangman.h"
using namespace std;

int main(int arg1, char* arg2[]){
    Hangman man = Hangman();

    ifstream file;
    file.open("Wordlist.txt");

    string inword;
    while(getline(file,inword)){

        stringstream ss(inword);

        string elementOne;
        getline(ss,elementOne);

        man.addWord(inword);
    }
    file.close();


    cout<<"Welcome to Hangman! Please select an option below."<<endl;
    cout<<endl;
    int option;
    do{
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Generate word"<<endl;
        cout<<"2. Guess letter"<<endl;
        cout<<"3. Guess word"<<endl;
        cout<<"4. Display previous guesses"<<endl;
        cout<<"5. Display progress"<<endl;
        cout<<"6. Display answer"<<endl;
        cout<<"7. Display man"<<endl;
        cout<<"8. Reset game"<<endl;
        cout<<"9. Give hint"<<endl;
        cout<<"10. Quit"<<endl;

        cin>>option;

        if((option == 1)){
            man.generateWord();
        }

        else if((option == 2)){
            cin.get();

            cout << "Enter a letter:" << endl;
            string letter;
            getline(cin, letter);

            man.checkLetter(letter);
        }

        else if((option == 3)){
            cin.get();

            cout << "Enter word:" << endl;
            string word;
            getline(cin, word);

            man.checkWord(word);
        }

        else if((option == 4)){
            man.displayGuesses();
        }

        else if((option == 5)){
            man.displayProgress();
        }

        else if((option == 6)){
            man.displayAnswer();
        }

        else if((option == 7)){
            man.displayMan();
        }

        else if((option == 8)){
            man.resetGame();
        }

        else if((option == 9)){
            man.giveHint();
        }

        else if((option == 10)){
            cout<<"Goodbye!"<<endl;
        }
    } while(option != 10);

    return 0;
}
