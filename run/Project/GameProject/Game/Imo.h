#pragma once
#include "Base/Base.h"

class Imo : public Base
{
    CImage m_img;

    enum
    {
        eAnimRun,
    };

public:
    Imo(const CVector2D& pos);
    void Update();
    void Draw();
    void Collision(Base* b);

    static TexAnimData _anim_data[];
};