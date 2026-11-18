#include "Game/puzzle.h"
#include "Base/Base.h"

Puzzle::Puzzle() : Base(eType_Puzzle)
{
	m_img[0] = COPY_RESOURCE("Red", CImage);
	m_img[1] = COPY_RESOURCE("Blue", CImage);
	m_img[2] = COPY_RESOURCE("Green", CImage);
	m_img[3] = COPY_RESOURCE("Yellow", CImage);

    m_blockX = 2;
    m_blockY = 1;

    m_color1 = rand() % 4 + 1;//(出てくる色を
    m_color2 = rand() % 4 + 1;//ランダムに出す)

    m_otiru = 0;//リセット


	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			m_field[y][x] = 0;
		}

	
	//m_field[11][0] = 1;
	//m_field[11][1] = 2;
	//m_field[11][2] = 3;
	//m_field[11][3] = 4;
	
	}
}

void Puzzle::Update()
{
    // 左キー
    if (PUSH(CInput::eLeft))
    {
        int nextX = m_blockX - 1;

        // 左端ではないか確認
        if (nextX >= 0)
        {
            // 上下両方のマスにブロックがないかの確認
            if (m_field[m_blockY][nextX] == 0 &&
                m_field[m_blockY - 1][nextX] == 0)
            {
                m_blockX--;
            }
        }
    }

    // 右キー
    if (PUSH(CInput::eRight))
    {
        int nextX = m_blockX + 1;

        // 右端ではないか確認
        if (nextX < 6)
        {
            // 上下両方のマスにブロックがないかの確認
            if (m_field[m_blockY][nextX] == 0 &&
                m_field[m_blockY - 1][nextX] == 0)
            {
                m_blockX++;
            }
        }
    }

    m_otiru++;

    if (PUSH(CInput::eDown))
    {
        while (true)
        {
            int nextY = m_blockY + 1;

            if (nextY >= 12 || m_field[nextY][m_blockX] != 0)
            {
                break;
            }

            m_blockY++;
        }
    }

    if (m_otiru >= 30)
    {
        m_otiru = 0;

        // 1マス下にブロックがあるか確認
        int nextY = m_blockY + 1;

        //下まで来たかの確認を次の場所にブロックがあるか
        if (nextY >= 12 || m_field[nextY][m_blockX] != 0)
        {
            // 下ブロックを固定
            m_field[m_blockY][m_blockX] = m_color1;

            // 上ブロックを固定
            m_field[m_blockY - 1][m_blockX] = m_color2;

            // 次のブロックを出す
            m_blockY = 1;
            m_blockX = 2;

            m_color1 = rand() % 4 + 1;
            m_color2 = rand() % 4 + 1;
        }
        else
        {
            // 下に何もなければ落下
            m_blockY++;
        }
    }
}
	
    void Puzzle::Draw()
    {
        // マス目を描く
        for (int y = 0; y < 12; y++)
        {
            for (int x = 0; x < 6; x++)
            {
                float px = FIELD_X + x * BLOCK_SIZE;
                float py = FIELD_Y + y * BLOCK_SIZE;

                // 外枠
                Utility::DrawQuad(
                    CVector2D(px, py),
                    CVector2D(BLOCK_SIZE, BLOCK_SIZE),
                    CVector4D(0.4f, 0.3f, 0.4f, 1.0f)
                );

                // 内側
                Utility::DrawQuad(
                    CVector2D(px + 2, py + 2),
                    CVector2D(BLOCK_SIZE - 4, BLOCK_SIZE - 4),
                    CVector4D(0.12f, 0.12f, 0.16f, 1.0f)
                );

                // 固定されたブロック
                if (m_field[y][x] != 0)
                {
                    int index = m_field[y][x] - 1;

                    m_img[index].SetSize(BLOCK_SIZE, BLOCK_SIZE);
                    m_img[index].SetPos(CVector2D(px, py));
                    m_img[index].Draw();
                }
            }
        }

        // 落下中の下ブロック
        m_img[m_color1 - 1].SetSize(BLOCK_SIZE, BLOCK_SIZE);
        m_img[m_color1 - 1].SetPos(
            CVector2D(
                FIELD_X + m_blockX * BLOCK_SIZE,
                FIELD_Y + m_blockY * BLOCK_SIZE
            )
        );
        m_img[m_color1 - 1].Draw();

        // 落下中の上ブロック
        m_img[m_color2 - 1].SetSize(BLOCK_SIZE, BLOCK_SIZE);
        m_img[m_color2 - 1].SetPos(
            CVector2D(
                FIELD_X + m_blockX * BLOCK_SIZE,
                FIELD_Y + (m_blockY - 1) * BLOCK_SIZE
            )
        );
        m_img[m_color2 - 1].Draw();
    }
