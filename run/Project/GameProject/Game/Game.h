#pragma once
#include "Base/Base.h"

class Game : public Base
{
	int m_character;
	int m_cnt;

public:
	Game(int character);
	~Game();
	void Update();
};