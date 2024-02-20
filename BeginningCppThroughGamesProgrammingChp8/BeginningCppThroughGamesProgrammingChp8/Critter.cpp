
#include "Critter.h"
#include <iostream>
using namespace std;

//TASKS:

/*Improve the Critter Caretaker program so that you can enter an unlisted
menu choice that reveals the exact values of the critter’s hunger and
boredom levels.*/

/* Change the Critter Caretaker program so that the critter is more
expressive about its needs by hinting at how hungry and bored it is.*/

Critter::Critter(int hunger, int boredom) :
	m_Hunger(hunger),
	m_Boredom(boredom)
{}

inline int Critter::GetMood() const { return (m_Hunger + m_Boredom); }
inline int Critter::GetHunger() const { return m_Hunger; }
inline int Critter::GetBoredom() const { return m_Boredom;  }

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Stats()
{
	cout << "I’m a critter and my stats are ";
	int hunger = GetHunger();
	int boredom = GetBoredom();

	cout << "\nHunger: " << hunger;
	cout << "\nBoredom: " << boredom;
}

void Critter::Talk()
{
	cout << "I’m a critter and I feel ";
	int mood = GetMood();
	int hunger = GetHunger();
	int boredom = GetBoredom();
	if (mood > 15)
	{
		cout << "mad.\n";
	}
	else if (mood > 10)
	{
		cout << "frustrated.\n";
	}
	else if (mood > 5)
	{
		cout << "okay.\n";
	}
	else
	{
		cout << "happy.\n";
	}
	
	if (hunger > 15)
	{
		cout << "I am Starving.\n";
	}
	else if (hunger > 10)
	{
		cout << "I am hungry.\n";
	}
	else if (hunger > 5)
	{
		cout << "I would like a snack.\n";
	}

	if (boredom > 15)
	{
		cout << "Hey! I'm so bored, play a game with me.\n";
	}
	else if (boredom > 10)
	{
		cout << "I'm a little bored.\n";
	}
	else if (boredom > 5)
	{
		cout << "I could play a game right now.\n";
	}
	PassTime();
}

void Critter::Eat(int food)
{
	cout << "Brruppp.\n";
	m_Hunger -= food;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}
	PassTime();
}

void Critter::Play(int fun)
{
	cout << "Wheee!\n";
	m_Boredom -= fun;
	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}
	PassTime();
}