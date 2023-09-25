#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Declarations
void explainProgram();
void listGames();
void addGame();
void removeGame();
void swapGame();

//Setup 
vector<string> topGames;
vector<string>::iterator TGIterator;
string input{};

//Main Game Loop
int main()
{
	topGames.reserve(20);
	//Explain to user
	explainProgram();
	getline(cin, input);
	//Main Game Loop
	while (input != "exit")
	{
		if (input == "list")
		{
			listGames();
		}

		if (input == "add")
		{
			addGame();
		}

		if (input == "remove")
		{
			removeGame();
		}

		if (input == "swap")
		{
			swapGame();
		}

		cout << "Please enter your next instruction" << endl;
		getline(cin, input);
	}
	//Exit Code
	return 0;
}

void explainProgram()
{
	cout << "This program allows you to list and order your favourite games." << endl;
	cout << "When Prompted enter \'add\', \'list\', \'swap\' or \'remove\' to alter your list." << endl;
	cout << "Enter \'exit\' to quit." << endl;
}

void listGames()
{
	//print all in vector
	cout << "Your Top Games List:" << endl;
	for (TGIterator = topGames.begin(); TGIterator != topGames.end(); ++TGIterator)
	{
		cout << *TGIterator << endl;
	}
}

void addGame()
{
	string addInput{};
	cout << "Add the Game Title for the entry or \`cancel\`" << endl;
	getline(cin, addInput);

	if (addInput != "cancel")
	{
		topGames.push_back(addInput);
		cout << "Game Added" << endl;
	}
}

void removeGame()
{
	string removeInput{};
	cout << "Add the Game Title to remove or \`cancel\`" << endl;
	getline(cin, removeInput);

	TGIterator = find(topGames.begin(), topGames.end(), removeInput);

	if (TGIterator != topGames.end())
	{
		topGames.erase(TGIterator);
		cout << "Game Removed" << endl;
	}
}

void swapGame()
{
	string swapGameNumber1{};
	string swapGameNumber2{};

	cout << "Input the game you would like to swap, or \`cancel\`" << endl;
	getline(cin, swapGameNumber1);

	if (swapGameNumber1 != "cancel")
	{
		cout << "Input the game you would like to swap it with, or \`cancel\`" << endl;
		getline(cin, swapGameNumber2);

		if (swapGameNumber2 != "cancel")
		{
			auto findGame1Iterator = find(topGames.begin(), topGames.end(), swapGameNumber1);
			auto findGame2Iterator = find(topGames.begin(), topGames.end(), swapGameNumber2);

			if (findGame1Iterator != topGames.end() && findGame2Iterator != topGames.end())
			{
				// Swap the positions of the games
				iter_swap(findGame1Iterator, findGame2Iterator);
				cout << "Games swapped." << endl;
			}
			else
			{
				cout << "One or both of the games were not found." << endl;
			}
		}
	
	}		
	
}
