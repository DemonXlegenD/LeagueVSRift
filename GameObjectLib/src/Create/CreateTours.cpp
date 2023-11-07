#include "Create/CreateTours.h"


void CreateTours::CreateJiin(float _poisitionX, float _positionY, sf::Texture _texture) 
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("Jiin")->GetPrixGold() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetRessource() && 
		SceneManager::GetActiveGameScene()->GetGameObject("Jiin")->GetPrixMana() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Jiin", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 30.f));
	}
}
void CreateTours::CreateLulu(float _poisitionX, float _positionY, sf::Texture _texture)
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("Lulu")->GetPrixGold() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetRessource() &&
		SceneManager::GetActiveGameScene()->GetGameObject("Lulu")->GetPrixGold() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Lulu", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 30.f));
	}
}
void CreateTours::CreateMalphite(float _poisitionX, float _positionY, sf::Texture _texture)
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("Malphite")->GetPrixGold() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetRessource() &&
		SceneManager::GetActiveGameScene()->GetGameObject("Malphite")->GetPrixMana() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Malphite", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 30.f));
	}
}
void CreateTours::CreateXinZhao(float _poisitionX, float _positionY, sf::Texture _texture)
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("XinZhao")->GetPrixGold() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetRessource() &&
		SceneManager::GetActiveGameScene()->GetGameObject("XinZhao")->GetPrixMana() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("XinZhao", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 30.f));
	}
}

void CreateTours::CreateBat2(float _poisitionX, float _positionY, sf::Texture _texture)
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("Bat2")->GetPrixGold() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetRessource() &&
		SceneManager::GetActiveGameScene()->GetGameObject("Bat2")->GetPrixGold() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Bat2", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 0.f));
	}
}

void CreateTours::CreateBat3(float _poisitionX, float _positionY, sf::Texture _texture)
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("Bat3")->GetPrixGold() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetRessource() &&
		SceneManager::GetActiveGameScene()->GetGameObject("Bat3")->GetPrixGold() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Bat3", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 5.f));
	}
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               