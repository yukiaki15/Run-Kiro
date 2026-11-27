#include "Base/Base.h"
#include "Title/Homu.h"
#include "Game/Game.h"

Homu::Homu() : Base(eType_Homu)
{
	m_img = COPY_RESOURCE("Homu", CImage);
	m_cnt = 0;
    m_character = -1;
}

void Homu::Update()
{
    CVector2D mouaePos = CInput::GetMousePoint();

    // 左のキャラクター
    if (mouaePos.x >= 138 && mouaePos.x <= 612 &&
        mouaePos.y >= 150 && mouaePos.y <= 650)
    {
        if (PUSH(CInput::eMouseL))
        {
            m_character = 0;
        }
    }

    // 真ん中のキャラクター
    if (mouaePos.x >= 690 && mouaePos.x <= 1173 &&
        mouaePos.y >= 150 && mouaePos.y <= 650)
    {
        if (PUSH(CInput::eMouseL))
        {
            m_character = 1;
        }
    }

    // 右のキャラクター
    if (mouaePos.x >= 1244 && mouaePos.x <= 1728 &&
        mouaePos.y >= 150 && mouaePos.y <= 650)
    {
        if (PUSH(CInput::eMouseL))
        {
            m_character = 2;
        }
    }

    // けっていボタン
    if (mouaePos.x >= 622 && mouaePos.x <= 1244 &&
        mouaePos.y >= 750 && mouaePos.y <= 957)
    {
        if (PUSH(CInput::eMouseL))
        {
            if (m_character != -1)
            {
                Base::KillAll();
                new Game(m_character);
            }
        }
    }
}

void Homu::Draw()
{
	m_img.Draw();

}
