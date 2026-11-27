#include "Game/Field.h"

static TexAnim _rund[] =
{
	{ 0,10 },
	{ 1,10 },
	{ 2,10 },
	{ 3,10 },
};
TexAnimData Field::_anim_data[] = {
	ANIMDATA(_rund),
};

Field::Field(const CVector2D& pos) : Base(eType_Field)
{
	m_kusa = COPY_RESOURCE("kusa", CImage);
	m_waku = COPY_RESOURCE("waku", CImage);
	m_pos = pos;
	m_kusa.ChangeAnimation(eAnimRund);
	//m_kusa.SetCenter(500, 540);
	m_kusa.SetSize(950, 1080);
}
void Field::Update()
{
	m_kusa.UpdateAnimation();
}

void Field::Draw()
{
	m_kusa.SetPos(m_pos);
	m_kusa.Draw();
	m_waku.Draw();
}