/* Using default arguments, write a function that asks the user for a
number and returns that number. The function should accept a string
prompt from the calling code. If the caller doesn’t supply a string for the
prompt, the function should use a generic prompt. Next, using function
overloading, write a function that achieves the same results.*/

#include<iostream>
#include<string>

using namespace std;

int getInput(const string& prompt = "(Default) Enter a Number: ");
void outputNumber(int);

int main()
{
	int defaultNum = getInput();
	outputNumber(defaultNum);
	
	int overloadNum = getInput("(Overload) Enter a Number: ");
	outputNumber(overloadNum);

	return 0;
}

int getInput(const string& prompt)
{
	int number;
	cout << prompt;
	cin >> number;

	return number;
}

void outputNumber(int number)
{
	cout << "Your number is " << number << endl;
}