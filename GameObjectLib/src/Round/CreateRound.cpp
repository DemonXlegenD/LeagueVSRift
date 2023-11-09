#include "Round/CreateRound.h"
#include "SceneManager.h"
#include "AssetManager.h"
#include "AudioManager.h"

CreateRound::CreateRound()
{
	count = 0;
};

void CreateRound::CreateRound1()
{
	AudioManager::Play("round_start");

	GameObject* EnemyA = SceneManager::GetActiveGameScene()->CreateEnemyAGameObject("Jin", 1411, 150, 0.1, 0.1, 0, *AssetManager::GetAsset("minionMelee"));

	GameObject* EnemyB = SceneManager::GetActiveGameScene()->CreateEnemyBGameObject("Jin", 1411, 150, 0.1, 0.1, 1, *AssetManager::GetAsset("minionSiege"));

	GameObject* EnemyC = SceneManager::GetActiveGameScene()->CreateEnemyCGameObject("Jin", 1411, 150, 0.1, 0.1, 2, *AssetManager::GetAsset("minionMage"));
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