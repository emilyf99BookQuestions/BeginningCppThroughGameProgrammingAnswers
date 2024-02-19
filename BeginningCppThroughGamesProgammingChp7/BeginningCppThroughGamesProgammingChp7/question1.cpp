#include <string>
#include <iostream>

#include "question1.h"

/*Write a program with a pointer to a pointer to a string object. Use the
pointer to the pointer to call the size() member function of the string
object.
*/
void question1::Question1()
{
	std::string questionString = "Test String";

	std::string* pToString = &questionString;
	std::string* pPtrToPtr = pToString;

	size_t sizeOfString = pPtrToPtr->size();
	std::cout << "String Size " << sizeOfString;
}