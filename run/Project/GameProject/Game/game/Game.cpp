#include "Base/Base.h"
#include "Game.h"
#include "Player.h"

Game::Game() : Base(eType_Scene)
{
	//new Field();
	new Player(CVector2D(400, 400));
}
Game::~Game()
{

}
void Game::Update()
{

}