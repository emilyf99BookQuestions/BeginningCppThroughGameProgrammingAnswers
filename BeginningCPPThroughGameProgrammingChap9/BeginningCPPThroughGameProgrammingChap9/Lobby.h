#pragma once
#include "Player.h"
#include <string>

class Lobby
{
	friend std::ostream& operator<<(std::ostream& os, const Lobby& aLobby);

public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();

private:
	Player* m_pHead;
	Player* m_pTail;
};
