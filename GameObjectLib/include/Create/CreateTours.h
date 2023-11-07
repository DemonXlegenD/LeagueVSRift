#pragma once
#include <vector>
#include "GameObject.h"
#include "SceneManager.h"
#include "Components/Ressource.h"

class CreateTours
{
public:
	CreateTours();
	void CreateJiin(float _poisionX, float _positionY, sf::Texture);
	void CreateLulu (float _poisionX, float _positionY, sf::Texture);
	void CreateMalphite(float _poisionX, float _positionY, sf::Texture);
	void CreateXinZhao(float _poisionX, float _positionY, sf::Texture);
	void CreateBat2(float _poisionX, float _positionY, sf::Texture);
	void CreateBat3(float _poisionX, float _positionY, sf::Texture);

private:
	std::vector<GameObject*> tower;
};

