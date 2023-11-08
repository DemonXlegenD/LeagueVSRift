#include "Round/CreateRound.h"
#include "SceneManager.h"

CreateRound::CreateRound()
{
	CreateRound1();
	CreateRound2();
	CreateRound3();
	CreateRound4();
};
void CreateRound::CreateRound1()
{
	enemy.push_back(SceneManager::GetActiveGameScene()->CreateEnemyGameObject("Jiin", 2530, 1061, "../assets/Sprite_LOL/Champions/jin.png"));
};
void CreateRound::CreateRound2()
{

};
void CreateRound::CreateRound3()
{

};
void CreateRound::CreateRound4()
{

};