#include "Player.h"
#include "Base/Base.h"

static TexAnim _run[] =
{
	{ 0,9 },
	{ 1,9 },
};

TexAnimData Player::_anim_data[] =
{
	ANIMDATA(_run),
};

Player::Player(const CVector2D& pos) : Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = pos;
	m_img.ChangeAnimation(eAnimRun);
	m_img.SetCenter(175,270);
}
void::Player::Update()
{
	m_img.UpdateAnimation();
}

void::Player::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}

void::Player::Collision(Base* b)
{

}
