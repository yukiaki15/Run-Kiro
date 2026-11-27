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

    m_kaitenn = 0;
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
    // 2個目のブロックの位置
    int dx = 0;
    int dy = -1;

    if (m_kaitenn == 1)
    {
        dx = 1;
        dy = 0;
    }
    else if (m_kaitenn == 2)
    {
        dx = 0;
        dy = 1;
    }
    else if (m_kaitenn == 3)
    {
        dx = -1;
        dy = 0;
    }

    // 左キー
    if (PUSH(CInput::eLeft))
    {
        //移動した2個の座標計算
        int x1 = m_blockX - 1;      //1個目の移動先の横座標
        int x2 = m_blockX + dx - 1; //1個目の移動先の縦座標
        int y1 = m_blockY;          //2個目の移動先の横座標
        int y2 = m_blockY + dy;     //2個目の移動先の縦座標

        //2個ともフィールドの中にいるかの確認
        if (x1 >= 0 && x1 < 6 && 
            x2 >= 0 && x2 < 6 && 
            y1 >= 0 && y1 < 12 &&
            y2 >= 0 && y2 < 12)
        {
            //移動先に固定されたブロックがないか
            if (m_field[y1][x1] == 0 &&
                m_field[y2][x2] == 0)
            {
                m_blockX--;
            }
        }
    }

    // 右キー
    if (PUSH(CInput::eRight))
    {
        //移動した2個の座標計算
        int x1 = m_blockX + 1;      //1個目の移動先の横座標
        int x2 = m_blockX + dx + 1; //1個目の移動先の縦座標
        int y1 = m_blockY;          //2個目の移動先の横座標
        int y2 = m_blockY + dy;     //2個目の移動先の縦座標

        //2個ともフィールドの中にいるかの確認
        if (x1 >= 0 && x1 < 6 &&
            x2 >= 0 && x2 < 6 &&
            y1 >= 0 && y1 < 12 &&
            y2 >= 0 && y2 < 12)
        {
            //移動先に固定されたブロックがないか
            if (m_field[y1][x1] == 0 &&
                m_field[y2][x2] == 0)
            {
                m_blockX++;
            }
        }
    }

    //Zで回転(壁抜き・回転の不具合〇)
    if (PUSH(CInput::eButton1))
    {
        //回転した後の向き　％4であまりを求めて次の向きを考える
        int nextRotation = (m_kaitenn + 1) % 4;

        //回転後の2個目のブロックの位置を計算するための変数
        int nextDx = 0;
        int nextDy = -1;

        //回転の方向を決めている
        if (nextRotation == 1) { nextDx = 1; nextDy = 0; }
        else if (nextRotation == 2) { nextDx = 0; nextDy = 1; }
        else if (nextRotation == 3) { nextDx = -1; nextDy = 0; }

        // 回転後の2個目のブロックの位置
        int nextX = m_blockX + nextDx;
        int nextY = m_blockY + nextDy;

        // 2個目のブロックがフィールド内か確認
        if (nextX >= 0 && nextX < 6 &&
            nextY >= 0 && nextY < 12)
        {
            // 回転先にブロックがないか確認
            if (m_field[nextY][nextX] == 0)
            {
                m_kaitenn = nextRotation;
            }
        }
    }

    // 回転後の向きをもう一度取得
    //回転前の向きのまま落下しない様に
    dx = 0;
    dy = -1;

    if (m_kaitenn == 1) { dx = 1; dy = 0; }
    else if (m_kaitenn == 2) { dx = 0; dy = 1; }
    else if (m_kaitenn == 3) { dx = -1; dy = 0; }

    if (PUSH(CInput::eDown))
    {
        while (true)
        {
            //2個のブロックが1マス下に移動したときの座標
            int x1 = m_blockX;
            int y1 = m_blockY + 1;
            int x2 = m_blockX + dx;
            int y2 = m_blockY + dy + 1;

            //どちらかの移動先にブロックがあったら break で繰り返しを終了
            if (x1 < 0 || x1 >= 6 || y1 < 0 || y1 >= 12 ||
                x2 < 0 || x2 >= 6 || y2 < 0 || y2 >= 12)
                break;
            if (m_field[y1][x1] != 0 ||
                m_field[y2][x2] != 0)
                break;

            //どちらも空いていれば1マス下に落下
            m_blockY++;
        }
    }

    // 自動落下
    m_otiru++;

    if (m_otiru >= 30)
    {
        m_otiru = 0;

        int x1 = m_blockX;
        int y1 = m_blockY + 1;

        int x2 = m_blockX + dx;
        int y2 = m_blockY + dy + 1;

        // 2個とも下に移動できるか確認
        bool canFall = true;

        //どちらか一方でもフィールドの外に出ていたら、落下できない
        if (x1 < 0 || x1 >= 6 || y1 < 0 || y1 >= 12 ||
            x2 < 0 || x2 >= 6 || y2 < 0 || y2 >= 12)
        {
            canFall = false;
        }
        //固定ブロックがないか確認
        else if (m_field[y1][x1] != 0 ||
            m_field[y2][x2] != 0)
        {
            canFall = false;
        }

        //落下できるかどうか
        if (canFall)
        {
            m_blockY++;
        }
        else
        {
            // 2個目のブロックの座標
            int lockX = m_blockX + dx;
            int lockY = m_blockY + dy;

            // 2個ともフィールド内にあるか確認
            if (m_blockX >= 0 && m_blockX < 6 &&
                m_blockY >= 0 && m_blockY < 12 &&
                lockX >= 0 && lockX < 6 &&
                lockY >= 0 && lockY < 12)
            {
                // 1個目のブロックを固定
                m_field[m_blockY][m_blockX] = m_color1;

                // 2個目のブロックを固定
                m_field[lockY][lockX] = m_color2;
            }
            

            // 次のブロックを出す
            m_blockY = 1;
            m_blockX = 2;

            m_color1 = rand() % 4 + 1;
            m_color2 = rand() % 4 + 1;

            m_kaitenn = 0;
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

        //横方向の回転量
        int dx = 0;
        //縦方向の回転量
        int dy = 0;

        // 回転方向によって上ブロックの位置を変える
        if (m_kaitenn == 0)//縦
        {
            dx = 0;
            dy = -1;
        }
        else if (m_kaitenn == 1)//横
        {
            dx = 1;
            dy = 0;
        }
        else if (m_kaitenn == 2)//縦(逆)
        {
            dx = 0;
            dy = 1;
        }
        else if (m_kaitenn == 3)//横(逆)
        {
            dx = -1;
            dy = 0;
        }

        // 下ブロック
        m_img[m_color1 - 1].SetSize(BLOCK_SIZE, BLOCK_SIZE);
        m_img[m_color1 - 1].SetPos(
            CVector2D(
                //横位置の計算
                FIELD_X + m_blockX * BLOCK_SIZE,
                FIELD_Y + m_blockY * BLOCK_SIZE
                //基準ブロックの横位置＋何マス横にずらすか
                //＊1マスの大きさ
            )
        );
        m_img[m_color1 - 1].Draw();

        // もう一つのブロック
        m_img[m_color2 - 1].SetSize(BLOCK_SIZE, BLOCK_SIZE);
        m_img[m_color2 - 1].SetPos(
            CVector2D(
                //縦位置の計算
                FIELD_X + (m_blockX + dx) * BLOCK_SIZE,
                FIELD_Y + (m_blockY + dy) * BLOCK_SIZE
     
            )
        );
        m_img[m_color2 - 1].Draw();
    }
