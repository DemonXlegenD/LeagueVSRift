#pragma once

#include "Scenes/SceneGameAbstract.h"

class SceneGameLVSR : public SceneGameAbstract
{
public:
	SceneGameLVSR(sf::RenderWindow* window);
	~SceneGameLVSR();

	void Awake() override;

	void CreateSpawn();
	void ChoiceTower();
	void ChoiceSpawn();
	void Create() override;
	void Delete() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;
	float scale;
private:
	std::vector<GameObject*> spawns;
	bool isChoice = true;
	int index = 0;
};