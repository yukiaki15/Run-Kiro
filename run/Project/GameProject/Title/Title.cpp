#include "Base/Base.h"
#include "Title/Title.h"
#include "Game/Game.h"
#include "Title/Homu.h"

Title::Title() : Base(eType_Title)
{
	m_img = COPY_RESOURCE("Title", CImage);
	m_cnt = 0;
}

void Title::Update()
{
	CVector2D mouaePos = CInput::GetMousePoint();

	if (mouaePos.x >= 550 && mouaePos.x <= 1250 &&
		mouaePos.y >= 500 && mouaePos.y <= 750)
	{
		if (PUSH(CInput::eMouseL))
		{
			Base::KillAll();
			new Homu();
		}
	}
}

void Title::Draw()
{
	m_img.Draw();

}
