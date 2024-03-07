#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const string& name) :
	m_Name(name),
	m_pNext(0),
	m_pTail(0)
{}

string Player::GetName() const
{
	return m_Name;
}

Player* Player::GetNext() const
{
	return m_pNext;
}

void Player::SetNext(Player* next)
{
	m_pNext = next;
}

std::ostream& operator<<(std::ostream& os, const Player& aPlayer)
{
	os << aPlayer.m_Name; 
	return os;
}
