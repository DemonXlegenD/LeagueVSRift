#pragma once
#include <vector>
#include "GameObject.h"
#include "SceneManager.h"
#include "Components/Ressource.h"

class CreateTours
{
public:
	static bool CanPlaceTower(std::string name);
	static void CreateTower(int _index, float _poisionX, float _positionY);
	static void CreateVarus(float _poisionX, float _positionY);
	static void CreateLulu (float _poisionX, float _positionY);
	static void CreateMalphite(float _poisionX, float _positionY);
	static void CreateXinZhao(float _poisionX, float _positionY);
	static void CreateBat2(float _poisionX, float _positionY);
	static void CreateBat3(float _poisionX, float _positionY);
	

	CreateTours();
	void CreateVarus(float _poisionX, float _positionY, sf::Texture);
	void CreateLulu (float _poisionX, float _positionY, sf::Texture);
	void CreateMalphite(float _poisionX, float _positionY, sf::Texture);
	void CreateXinZhao(float _poisionX, float _positionY, sf::Texture);
	void CreateBat2(float _poisionX, float _positionY, sf::Texture);
	void CreateBat3(float _poisionX, float _positionY, sf::Texture);
private:
	static std::vector<GameObject*> tower;
	static sf::Texture* texture;
};

