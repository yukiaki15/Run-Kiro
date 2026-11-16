#pragma once
#include "Base/Base.h"

class Puzzle : public Base
{
    CImage m_img[4];
    int m_field[12][6];
    int m_otiru;

    const int BLOCK_SIZE = 75;
    const int FIELD_X = 1215;
    const int FIELD_Y = 90;

    int m_color1;
    int m_color2;

    int m_blockX;
    int m_blockY;

public:
    Puzzle();

    void Update();
    void Draw();
};