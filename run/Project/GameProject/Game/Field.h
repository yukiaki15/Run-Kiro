#pragma once
#include "Base/Base.h"

class Field : public Base
{
	CImage m_kusa;
	CImage m_waku;

public:
	Field();
	void Draw();
};