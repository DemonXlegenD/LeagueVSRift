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
	sf::Texture testSbireTexture;

	if (!testSbireTexture.loadFromFile("../assets/Sprite_LOL/Sbires/minion_melee.png"))
	{
		std::cout << "pas d'image" << std::endl;
	}

	SceneManager::GetActiveGameScene()->CreateEnemyAGameObject("Jin", 1411, 150, 0.1, 0.1, 0, testSbireTexture);

	SceneManager::GetActiveGameScene()->CreateEnemyBGameObject("Jin", 1411, 150, 0.1, 0.1, 1, testSbireTexture);

	SceneManager::GetActiveGameScene()->CreateEnemyCGameObject("Jin", 1411, 150, 0.1, 0.1, 2, testSbireTexture);
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