#pragma once
#include <vector>
#include "GameObject.h"
class CreateRoud
{
public:
	CreateRoud();
	void CreateRoud1();
	void CreateRoud2();
	void CreateRoud3();
	void CreateRoud4();
private:
	std::vector<GameObject*> enemy;
};

