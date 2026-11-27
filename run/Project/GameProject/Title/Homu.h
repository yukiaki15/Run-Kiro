#pragma once
#include "Base/Base.h"

class Homu : public Base
{
	CImage m_img;
	int m_character;
	int m_cnt;

public:
	Homu();
	void Update();
	void Draw();
};