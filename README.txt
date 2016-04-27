Project Summary
	My program is a hangman game operated through the menu. It utilizes linked lists to store data and access it. Users will be able to generate a random word from 5 different subjects and guess what each of those words are. They are limited by the number of incorrect guesses they can have. The user has many different options to try and guess the word.


How to Run
	In order to run my program successfully you need to download the Wordlist.txt file as well as Final.cpp,Hangman.cpp, and Hangman.h. Once these files are in the same location you can run my program. It will automatically open up the Wordlist.txt and retrieve words from there. Afterwards you will need to generate a word. This is option 1 from the menu. Once a word has been randomly selected you may attempt to guess letters or the entire word using options 2 and 3. After selecting either option the program will prompt you for a letter or word. You will be informed of whether or not your guess was correct. You have 6 incorrect guesses before the game ends and you must reset it. You also have the option to display previous guesses if you have forgotten them. Option 5 displays how much progress you've made on your word. The output will be similar to this:

5
Here's how much progress you've made.
_ _ _ _ a _ _ _ _

Underscores indicate that the letter hasn't been guessed yet. If the blank is filled in you have already guessed that letter. You may also display the answer if you have given up, although the program will automatically display it if you lose. Option 7 will display the hangman, showing you have many guesses you have remaining. Option 8 resets the game. This is necessary to reset the amount of guesses you have as well as generate a new word. All parameters will be reset. Option 9 allows you to receive a free letter in your word at the cost of 2 guesses. The program will not allow you to use this option if you have less than 3 correct guesses remaining as that will cause you to lose the game. The output for this option is as shown:

9
The letter in spot number 1 has been revealed.
You now have 4 guesses remaining.

The final option is to change the subject of the words you are reveiving. There are 5 subjects total: fruits, sports, methods of transportation, animals, and colors. Selecting this option will reset parameters and give you a new word within the new subject. Changing subjects will show this output:

10
Your word has 6 letters.
The subject is sports.
Subject has been changed! You have been given a new word.

Option 11 is to exit the program.


Dependencies
	Everything is the same as a normal assignment. All files are either .cpp, .h, or .txt files. 


System requirements
	There are no system requirements.


Group members
	None.


Contributors
	None.


Open issues/bugs
	None that I can think of.

