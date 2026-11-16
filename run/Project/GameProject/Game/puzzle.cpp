#include "Game/puzzle.h"
#include "Base/Base.h"

Puzzle::Puzzle() : Base(eType_Puzzle)
{
	m_img[0] = COPY_RESOURCE("Red", CImage);
	m_img[1] = COPY_RESOURCE("Blue", CImage);
	m_img[2] = COPY_RESOURCE("Green", CImage);
	m_img[3] = COPY_RESOURCE("Yellow", CImage);

	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			m_field[y][x] = 0;
		}

	
	m_field[11][0] = 1;
	m_field[11][1] = 2;
	m_field[11][2] = 3;
	m_field[11][3] = 4;
	
	}
}

void Puzzle::Update()
{

}

void Puzzle::Draw()
{
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			if (m_field[y][x] == 0)
				continue;

			m_img[m_field[y][x] - 1].SetPos
			(CVector2D(1100 + x * 48, 150 + y * 48));

			m_img[m_field[y][x] - 1].Draw();

		}
	}

}