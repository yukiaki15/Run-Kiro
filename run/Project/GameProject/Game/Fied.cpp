#include "Game/Field.h"

Field::Field() : Base(eType_Field)
{
	m_kusa = COPY_RESOURCE("kusa", CImage);
	m_waku = COPY_RESOURCE("waku", CImage);
}
void Field::Draw()
{
	//m_kusa.Draw();
	m_waku.Draw();
}