#pragma once
#include "Scene.h"
#include "SceneGameAbstract.h"

class SceneCreditsMenu : public Scene
{
public:
	SceneCreditsMenu(sf::RenderWindow* window);

	void CreateSceneButtonsMenu();

	GameObject* CreateCreditsGameObject(const std::string& name, float positionx, float positiony, const sf::Texture texture, float scalex, float scaley);
	void CreateCredits();

	void AnimFrancois(float _deltaSeconds, float _iteration, int _totalLoop);

	void SetOrigin();

	void Create() override;
	void Render(sf::RenderWindow* _window) override;
	void Update(sf::Time _delta) override;
private:
	GameObject* creditsButton = nullptr;
	GameObject* backButton = nullptr;
	GameObject* creditsFrancois = nullptr;
	GameObject* credits = nullptr;
	GameObject* imagesFrancois = nullptr;
	sf::Text text;

	sf::Time delta;
	float deltaSeconds = 0.f;
	int down = 0;
	int up = 0;
	float speed = 500.f;
	int nombreSeconds = 1;
	float iteration = 2.f;
	int totalLoop = 20;
	bool goodPosCredits;
};


