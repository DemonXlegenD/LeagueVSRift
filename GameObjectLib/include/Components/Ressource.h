#pragma once
#include "Component.h"
class Ressource: public Component
{
public:

	void SetGold(float _value){ gold = _value; }
	float GetGold() { return gold; }
	
	void SetMana(float _value) { mana = _value; }
	float GetMana() { return mana; }

	void SetMaxMana(float _value) { maxMana = _value; }
	float GetMaxMana() { return maxMana; }

private: 
	float gold;
	float mana;
	float maxMana = 300.f;
};

