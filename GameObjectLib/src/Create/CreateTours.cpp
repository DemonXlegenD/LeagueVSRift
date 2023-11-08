#include "Create/CreateTours.h"


void CreateTours::CreateJiin(float _poisitionX, float _positionY, sf::Texture _texture) 
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("Jiin")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetComponent<Ressource>()->GetRessource() &&
		SceneManager::GetActiveGameScene()->GetGameObject("Jiin")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetComponent<Ressource>()->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Jiin", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 30.f));
	}
}
void CreateTours::CreateLulu(float _poisitionX, float _positionY, sf::Texture _texture)
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("Lulu")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetComponent<Ressource>()->GetRessource() &&
		SceneManager::GetActiveGameScene()->GetGameObject("Lulu")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetComponent<Ressource>()->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Lulu", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 30.f));
	}
}
void CreateTours::CreateMalphite(float _poisitionX, float _positionY, sf::Texture _texture)
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("Malphite")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetComponent<Ressource>()->GetRessource() &&
		SceneManager::GetActiveGameScene()->GetGameObject("Malphite")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetComponent<Ressource>()->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Malphite", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 30.f));
	}
}
void CreateTours::CreateXinZhao(float _poisitionX, float _positionY, sf::Texture _texture)
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("XinZhao")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetComponent<Ressource>()->GetRessource() &&
		SceneManager::GetActiveGameScene()->GetGameObject("XinZhao")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetComponent<Ressource>()->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("XinZhao", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 30.f));
	}
}

void CreateTours::CreateBat2(float _poisitionX, float _positionY, sf::Texture _texture)
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("Bat2")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetComponent<Ressource>()->GetRessource() &&
		SceneManager::GetActiveGameScene()->GetGameObject("Bat2")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetComponent<Ressource>()->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Bat2", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 0.f));
	}
}

void CreateTours::CreateBat3(float _poisitionX, float _positionY, sf::Texture _texture)
{
	if (SceneManager::GetActiveGameScene()->GetGameObject("Bat3")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Gold")->GetComponent<Ressource>()->GetRessource() &&
		SceneManager::GetActiveGameScene()->GetGameObject("Bat3")->GetComponent<Ressource>()->GetRessource() <= SceneManager::GetActiveGameScene()->GetGameObject("Mana")->GetComponent<Ressource>()->GetRessource())
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Bat3", _poisitionX, _positionY, _texture, 4.f, 4.f, 400.f, 5.f));
	}
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               