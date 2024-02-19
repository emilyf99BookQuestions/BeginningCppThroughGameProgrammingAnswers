#pragma once
#include <string>

class question2 
{
	public:
		static void Main();
		static std::string* askText(std::string prompt);
		static int* askNumber(std::string prompt);
		static void tellStory(std::string* name, std::string* noun, int* number, std::string* bodyPart, std::string* verb);
};