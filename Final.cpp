#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "Hangman.h"
using namespace std;

int main(int arg1, char* arg2[]){
    int option;
    do{
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Insert movie"<<endl;
        cout<<"2. Delete movie"<<endl;
        cout<<"3. Find movie"<<endl;
        cout<<"4. Print table contents"<<endl;
        cout<<"5. Quit"<<endl;

        cin>>option;

        if((option == 1)){
            cin.get();

            cout << "Enter title:" << endl;
            string name;
            getline(cin, name);

            cout << "Enter year:" << endl;
            string date;
            getline(cin, date);
            int year = std::stoi(date);


        }

        else if((option == 2)){
            cin.get();

            cout << "Enter title:" << endl;
            string name;
            getline(cin, name);


        }

        else if((option == 3)){
            cin.get();

            cout << "Enter title:" << endl;
            string name;
            getline(cin, name);


        }

        else if((option == 4)){

        }

        else if((option == 5)){
            cout<<"Goodbye!"<<endl;
        }
    } while(option != 5);

    return 0;
}
