/*  Write a new version of the Guess My Number program in which the
player and the computer switch roles. That is, the player picks a number
and the computer must guess what it is.*/

// Guess My Number
// The classic number guessing game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int computerGuess();

int main() {
	srand(static_cast<unsigned int>(time(0)));

	const int MAX_NUMBER = 100 ;
	int secretNumber;
	int tries = 0;
	int guess = 1;

	cout << "\tWelcome to Guess My Number\n\n";
	cout << "Enter a Secret Number between 1 and 100, the computer will guess your number" << endl;
	cin >> secretNumber;

	if (secretNumber <= MAX_NUMBER) {
		do {
			guess = computerGuess();
			cout << guess; 
			++tries;

			if (guess > secretNumber) {
				cout << " Too high!\n\n";
			}
			else if (guess < secretNumber) {
				cout << " Too Low!\n\n";
			}
			else {
				cout << "\nThat's it! You got it in " << tries << " guesses!\n";
			}
		} while (guess != secretNumber);
	}

	else {
		cout << "Error: Your Number is not between range";
	}
	
	return 0;
}

int computerGuess() {
	return rand() % 100 + 1;
}