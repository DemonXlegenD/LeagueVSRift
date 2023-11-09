#pragma once

#include "Scenes/SceneGameAbstract.h"

class SceneGameLVSR : public SceneGameAbstract
{
public:
	SceneGameLVSR(sf::RenderWindow* window);
	~SceneGameLVSR();

	void Awake() override;

	void CreateSpawn();
	void CreateActiveSpawn();
	void Create() override;
	void Delete() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;
	float scale;
private:
	std::vector<GameObject*> spawns;
};