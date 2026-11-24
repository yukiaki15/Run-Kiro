#pragma once
#include "Base/Base.h"

class Field : public Base
{
    enum
    {
        eAnimRund,
    };

	CImage m_kusa;
	CImage m_waku;

public:
	Field(const CVector2D& pos);
	void Draw();
	void Update();
	static TexAnimData _anim_data[];
};




