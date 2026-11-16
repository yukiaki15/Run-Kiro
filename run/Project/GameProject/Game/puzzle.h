#pragma once
#include "Base/Base.h"

class Puzzle : public Base
{
    CImage m_img[4];

    int m_field[12][6];

public:
    Puzzle();

    void Update();
    void Draw();
};