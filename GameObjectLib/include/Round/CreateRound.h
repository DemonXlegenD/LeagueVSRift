#pragma once
#include <vector>
#include "GameObject.h"
class CreateRound
{
public:
	CreateRound();
	void CreateRound1();
	void CreateRound2();
	void CreateRound3();
	void CreateRound4();
private:
	int count;
	std::vector<GameObject*> enemy;
};