#include "Game/Player.h"
#include "Base/Base.h"


static TexAnim _run[] = {
	{ 0,11 },
	{ 1,11 },
	{ 2,11 },
	{ 3,11 },
	{ 2,11 },
	{ 1,11 },
};
TexAnimData Player::_anim_data[] = {
	ANIMDATA(_run),
};
Player::Player(const CVector2D& pos, int character)
    : Base(eType_Player)
{
    if (character == 0)
    {
        m_img = COPY_RESOURCE("Player", CImage);
    }
    else if (character == 1)
    {
        m_img = COPY_RESOURCE("Imo", CImage);
    }
    else if (character == 2)
    {
        m_img = COPY_RESOURCE("Tako", CImage);
    }

    m_pos = pos;
    m_img.ChangeAnimation(eAnimRun);
    m_img.SetSize(400, 850);
}
void Player::Update()
{
	m_img.UpdateAnimation();
}

void Player::Draw()
{
	//m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetPos(m_pos);
	m_img.Draw();
}
