//Abstract Creature
//Demonstrates abstract classes
#include <iostream>
using namespace std;


/*Improve the Abstract Creature program by adding a new class, OrcBoss,
which is derived from Orc. An OrcBoss object should start with 180 for
its health data member. You should also override the virtual Greet()
member function so that it displays: The orc boss growls hello.*/

class Creature //abstract class
{
public:
	Creature(int health = 100);
	virtual void Greet() const = 0; //pure virtual member function
	virtual void DisplayHealth() const;
protected:	int m_Health;
};

Creature::Creature(int health) :
	m_Health(health)
{}

void Creature::DisplayHealth() const
{
	cout << "Health: " << m_Health << endl;
}

class Orc : public Creature
{
public:
	Orc(int health = 120);
	virtual void Greet() const;
};

Orc::Orc(int health) :
	Creature(health)
{}

void Orc::Greet() const
{
	cout << "The orc grunts hello.\n";
}

class OrcBoss : public Orc
{
public: 
	OrcBoss(int health = 180);
	virtual void Greet() const override;
};

OrcBoss::OrcBoss(int health) :
	Orc(health)
{}

void OrcBoss::Greet() const
{
	cout << "The orc boss growls hello.\n";
}

int main()
{
	Creature* pCreature = new Orc();
	pCreature->Greet();
	pCreature->DisplayHealth();

	OrcBoss* pOrcBoss = new OrcBoss();
	pOrcBoss->Greet();
	pOrcBoss->DisplayHealth();
	return 0;
}