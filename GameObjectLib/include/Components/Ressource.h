#pragma once
#include "Component.h"
class Ressource: public Component
{
public:

	void SetRessource(float _ressource){ ressource = _ressource; }
	float GetRessource() { return ressource; }

private: 
	float ressource; 
};

