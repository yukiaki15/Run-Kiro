#include "Game/Fieds.h"

Fieds::Fieds(const CVector2D& pos) : Base(eType_ura)
{
	m_img = COPY_RESOURCE("ura", CImage);
	m_img.SetCenter(500,540);
	m_img.SetSize(1000, 1080);
	m_pos = pos;
}
void Fieds::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}