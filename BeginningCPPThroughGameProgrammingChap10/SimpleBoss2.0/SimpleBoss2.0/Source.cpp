/* 
Improve the Simple Boss 2.0 program by adding a new class, FinalBoss,
that is derived from the Boss class. The FinalBoss class should define a
new method, MegaAttack(), that inflicts 10 times the amount of damage
as the SpecialAttack() method does
*/

#include <iostream>
using namespace std;

class Enemy
{
public:
	Enemy();
	void Attack() const;
protected:
	int m_Damage;
};

Enemy::Enemy() :
	m_Damage(10)
{}

void Enemy::Attack() const
{
	cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
	Boss();
	void SpecialAttack() const;
protected:
	int m_DamageMultiplier;
};

Boss::Boss() :
	m_DamageMultiplier(3)
{}

void Boss::SpecialAttack() const
{
	cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
	cout << " damage points! \n";
}

class FinalBoss : public Boss
{
public:
	FinalBoss();
	void MegaAttack() const;
private:
	int m_MegaAttackMultiplier;
};

FinalBoss::FinalBoss() :
	m_MegaAttackMultiplier(10)
{}

void FinalBoss::MegaAttack() const
{
	cout << "Mega Attack inflicts " << (m_MegaAttackMultiplier * m_DamageMultiplier * m_Damage);
	cout << " damage points! \n";
}
int main()
{
	cout << "Creating an enemy.\n";
	Enemy enemy1;
	enemy1.Attack();
	
	cout << "\nCreating a boss.\n";
	Boss boss1;
	boss1.Attack();
	boss1.SpecialAttack();

	cout << "\nCreating a Final Boss.\n";
	FinalBoss finalBoss1;
	finalBoss1.Attack();
	finalBoss1.SpecialAttack();
	finalBoss1.MegaAttack();

	return 0;

}