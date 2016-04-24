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
        getline(ss,elementOne,',');

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
        cout<<"5. Quit"<<endl;

        cin>>option;

        if((option == 1)){

        }

        else if((option == 2)){
            cin.get();

            cout << "Enter a letter:" << endl;
            string letter;
            getline(cin, letter);
        }

        else if((option == 3)){
            cin.get();

            cout << "Enter word:" << endl;
            string word;
            getline(cin, word);


        }

        else if((option == 4)){

        }

        else if((option == 5)){
            cout<<"Goodbye!"<<endl;
        }
    } while(option != 5);

    return 0;
}
