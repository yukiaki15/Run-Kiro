#include "Game/puzzle.h"
#include "Base/Base.h"

Puzzle::Puzzle() : Base(eType_Puzzle)
{
	m_img[0] = COPY_RESOURCE("Red", CImage);
	m_img[1] = COPY_RESOURCE("Blue", CImage);
	m_img[2] = COPY_RESOURCE("Green", CImage);
	m_img[3] = COPY_RESOURCE("Yellow", CImage);

    m_color1 = 1;
    m_color2 = 2;

    m_blockX = 2;
    m_blockY = 1;

    m_otiru = 0;


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
    m_otiru++;

    if (m_otiru >= 30)
    {
        m_blockY++;
        m_otiru = 0;
    }
}

void Puzzle::Draw()
{
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 6; x++)
		{
            float px = FIELD_X + x * BLOCK_SIZE;
            float py = FIELD_Y + y * BLOCK_SIZE;

            // マス目の外枠
            Utility::DrawQuad(
                CVector2D(px, py),
                CVector2D(BLOCK_SIZE, BLOCK_SIZE),
                CVector4D(0.4f, 0.3f, 0.4f, 1.0f)
            );

            // マス目の内側
            Utility::DrawQuad(
                CVector2D(px + 2, py + 2),
                CVector2D(BLOCK_SIZE - 4, BLOCK_SIZE - 4),
                CVector4D(0.85f, 0.75f, 0.85f, 1.0f)
            );
        }
    }

    for (int y = 0; y < 12; y++)
    {
        for (int x = 0; x < 6; x++)
        {
            if (m_field[y][x] == 0)
                continue;

            int index = m_field[y][x] - 1;

            m_img[index].SetPos(
                CVector2D(
                    FIELD_X + x * BLOCK_SIZE,
                    FIELD_Y + y * BLOCK_SIZE
                )
            );
            m_img[index].SetSize(BLOCK_SIZE, BLOCK_SIZE);

            m_img[index].Draw();

            m_img[m_color1 - 1].SetSize(BLOCK_SIZE, BLOCK_SIZE);
            m_img[m_color1 - 1].SetPos(
                CVector2D(
                    FIELD_X + m_blockX * BLOCK_SIZE,
                    FIELD_Y + m_blockY * BLOCK_SIZE
                )
            );
            m_img[m_color1 - 1].Draw();

            m_img[m_color2 - 1].SetSize(BLOCK_SIZE, BLOCK_SIZE);
            m_img[m_color2 - 1].SetPos(
                CVector2D(
                    FIELD_X + m_blockX * BLOCK_SIZE,
                    FIELD_Y + (m_blockY - 1) * BLOCK_SIZE
                )
            );
            m_img[m_color2 - 1].Draw();

		}
	}

}