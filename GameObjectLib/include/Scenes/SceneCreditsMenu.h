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

	void SetOrigin();

	void Create() override;
	void Render(sf::RenderWindow* _window) override;
	void Update(sf::Time _delta) override;
private:
	GameObject* creditsButton = nullptr;
	GameObject* backButton = nullptr;
	GameObject* listCredits = nullptr;
	GameObject* listCredits2 = nullptr;
	GameObject* credits = nullptr;
	sf::Text text;
};


