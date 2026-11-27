#pragma once
#include "Base/Base.h"

class Player : public Base
{
    CImage m_img;

    enum
    {
        eAnimRun,
    };

public:
    Player(const CVector2D& pos, int character);

    void Update();
    void Draw();

    static TexAnimData _anim_data[];
};