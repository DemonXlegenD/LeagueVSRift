#pragma once
#include "Component.h"
class Ressource: public Component
{
public:

	void SetGold(float _value){ gold = _value; }
	float GetGold() { return gold; }
	
	void SetMana(float _value) { mana = _value; }
	float GetMana() { return mana; }

private: 
	float gold;
	float mana;
};

