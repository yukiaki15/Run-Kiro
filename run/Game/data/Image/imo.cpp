#include "Game/imo.h"
#include "Base/Base.h"


static TexAnim _run[] = {
	{ 0,11 },
	{ 1,11 },
	{ 2,11 },
	{ 3,11 },
	{ 2,11 },
	{ 1,11 },
};
TexAnimData Imo::_anim_data[] = {
	ANIMDATA(_run),
};
Player::Player(const CVector2D& pos) : Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
	m_pos = pos;
	m_img.ChangeAnimation(eAnimRun);
	//m_img.SetCenter(200, 425);
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
void Player::Collision(Base* b)
{

}