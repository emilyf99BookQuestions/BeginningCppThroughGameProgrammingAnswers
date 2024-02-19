
#include "question2.h"
#include <iostream>
#include <string>

/* Rewrite the Mad Lib Game project from Chapter 5, “Functions: Mad
Lib, ” so that no string objects are passed to the function that tells the
story.Instead, the function should accept pointers to string objects.*/ 

void question2::Main()
{
	std::cout << "Welcome to Mad Lib.\n\n";
	std::cout << "Answer the following questions to help create a new story.\n";
	std::string* name = askText("Please enter a name: ");
	std::string* noun = askText("Please enter a plural noun: ");
	int* number = askNumber("Please enter a number: ");
	std::string* bodyPart = askText("Please enter a body part: ");
	std::string* verb = askText("Please enter a verb: ");
	tellStory(name, noun, number, bodyPart, verb);
}

std::string* question2::askText(std::string prompt)
{
	std::string* text = new std::string;
	std::cout << prompt;
	std::cin >> *text;
	return text;
}


int* question2::askNumber(std::string prompt)
{
	int* num = new int;
	std::cout << prompt;
	std::cin >> *num;
	return num;
}

void question2::tellStory(std::string* name, std::string* noun, int* number, std::string* bodyPart,
	std::string* verb)
{
	std::cout << "\nHere’s your story:\n";
	std::cout << "The famous explorer ";
	std::cout << *name;
	std::cout << " had nearly given up a life-long quest to find\n";
	std::cout << "The Lost City of ";
	std::cout << *noun;
	std::cout << " when one day, the ";
	std::cout << *noun;
	std::cout << " found the explorer.\n";
	std::cout << "Surrounded by ";
	std::cout << *number;
	std::cout << " " << *noun;
	std::cout << ", a tear came to ";
	std::cout << *name << "’s ";
	std::cout << *bodyPart << ".\n";
	std::cout << "After all this time, the quest was finally over. ";
	std::cout << "And then, the ";
	std::cout << *noun << "\n";
	std::cout << "promptly devoured ";
	std::cout << *name << ". ";
	std::cout << "The moral of the story? Be careful what you ";
	std::cout << *verb;
	std::cout << " for.";
}