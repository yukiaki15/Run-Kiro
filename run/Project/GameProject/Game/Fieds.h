#pragma once
#include "Base/Base.h"

class Fieds : public Base
{
	CImage m_img;

public:
	Fieds(const CVector2D& pos);
	void Draw();
};