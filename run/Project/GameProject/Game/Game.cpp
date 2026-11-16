#include "Game/Game.h"
#include "Game/Player.h"
#include "Title/Title.h"
#include "Game/Field.h"
#include "Game/puzzle.h"    

Game::Game() : Base(eType_Scene)
{
    new Field();
    new Player(CVector2D(400, 200));
    new Puzzle();
    m_cnt = 0;
}
Game::~Game()
{

}
void Game::Update()
{
    m_cnt--;
    
    if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1))
    {
        Base::KillAll();
        new Title();
    }
}
