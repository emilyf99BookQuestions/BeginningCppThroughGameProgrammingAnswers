// Hangman
// The classic game of hangman
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

//Declarations
char getGuess();
void addWords(vector<string>& words);
void inputGuess(char, string& ,const string&, string&, int&);
void gameEnd(int&, const int, const string&);

//Globals
char guess;
const int MAX_WRONG = 8; //maximum number of incorrect guesses allowed
vector<string> words; //collection of possible words to guess

int main()
{
	addWords(words);
	
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0]; //word to guess
	int wrong = 0; //number of incorrect guesses
	string soFar(THE_WORD.size(), '-'); //word guessed so far
	string used = ""; //letters already guessed
	cout << "Welcome to Hangman. Good luck!\n";

	//main loop
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou�ve used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is:\n" << soFar << endl;

		guess = getGuess();
		
		inputGuess(guess, used, THE_WORD, soFar, wrong);
		
	}
	gameEnd(wrong, MAX_WRONG,THE_WORD);
	return 0;
}

char getGuess()
{
	cout << "\n\nEnter your guess: ";
	cin >> guess;
	return guess;
}

void addWords(vector<string>& words)
{
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
}

void inputGuess(char guess, string& used,const string& THE_WORD, string& soFar, int& wrong)
{
	guess = toupper(guess); //make uppercase since secret word in uppercase
	while (used.find(guess) != string::npos)
	{
		cout << "\nYou�ve already guessed " << guess << endl;
		cout << "Enter your guess: ";
		cin >> guess;
		guess = toupper(guess);
	}
	used += guess;
	if (THE_WORD.find(guess) != string::npos)
	{
		cout << "That�s right! " << guess << " is in the word.\n";
		//update soFar to include newly guessed letter
		for (int i = 0; i < THE_WORD.length(); ++i)
		{
			if (THE_WORD[i] == guess)
			{
				soFar[i] = guess;
			}
		}
	}
	else
	{
		cout << "Sorry, " << guess << " isn�t in the word.\n";
		++wrong;
	}
}

void gameEnd(int& wrong, const int MAX_WRONG, const string& THE_WORD)
{
	if (wrong == MAX_WRONG)
	{
		cout << "\nYou�ve been hanged!";
	}
	else
	{
		cout << "\nYou guessed it!";
	}
	cout << "\nThe word was " << THE_WORD << endl;
}