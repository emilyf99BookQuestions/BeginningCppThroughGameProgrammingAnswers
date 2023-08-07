#include <iostream>
using namespace std;


enum Difficulty {
	Easy = 1,
	Normal = 2,
	Hard = 3
};

int main()
{
	cout << "Difficulty Levels\n\n";
	cout << "1 - Easy\n";
	cout << "2 - Normal\n";
	cout << "3 - Hard\n\n";

	int choice;
	cout << "Choice: ";
	cin >> choice;

	Difficulty playerChoice;

	switch (choice)
	{
	case Easy:
		playerChoice = Easy; 
		cout << "You picked Easy.\n";
		break;
	case Normal:
		playerChoice = Normal;
		cout << "You picked Normal.\n";
		break;
	case Hard:
		playerChoice = Hard;
		cout << "You picked Hard.\n";
		break;
	default:
		cout << "You made an illegal choice.\n";
	}
	return 0;
}