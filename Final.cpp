#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

#include "Hangman.h"
using namespace std;

bool isNumber(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

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
    bool flag = true;
    string ans;
    string word;
    string letter;
    int ans1;
    while (flag){
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
        cout<<"10. Change subject"<<endl;
        cout<<"11. Quit"<<endl;
		
        getline (cin, ans);
		
		if (isNumber(ans) != true){
			cout<<"Wrong input"<<endl;
			continue;
		} else {
			if(ans.length()>2){
				cout<<"Wrong input"<<endl;
				continue;
			} else {
			ans1 = stoi(ans);
			
			}	
		}
		switch (ans1){
        
	    	case 1:
				man.generateWord();
	    	break;
	    	case 2:

				cout << "Enter a letter:" << endl;
				
				getline(cin, letter);

				man.checkLetter(letter);
	    	break;
	    	case 3:
				cin.get();

				cout << "Enter word:" << endl;
				
				getline(cin, word);

				man.checkWord(word);
	    	break;
	    	case 4:
				man.displayGuesses();
	    	
	    	break;
	    	case 5:
				man.displayProgress();
	    	
	    	break;
	    	case 6:
				man.displayAnswer();
	    	
	    	break;
	    	case 7:
				man.displayMan();
	    	
	    	break;
	    	case 8:
				man.resetGame();
	    	
	    	break;
	    	case 9:
				man.giveHint();
	    	
	    	break;
	    	case 10:
				man.changeSubject();
	    	
	    	break;
	    	case 11:
				cout<<"Goodbye!"<<endl;
				flag = false;
				break;
			default: 
				cout<<"Incorrect input"<<endl;
		}
	}
    return 0;
}
