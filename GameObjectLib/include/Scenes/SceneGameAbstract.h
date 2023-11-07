#pragma once
#include "Scene.h"


class SceneGameAbstract : public Scene
{
public:
	SceneGameAbstract(sf::RenderWindow* window);
	~SceneGameAbstract();

	void Awake() override;

	void CreatePlayer();
	void CreateTower();
	void CreateRessource();

	void RemoveEnemy(GameObject* _enemyToRemove);

	void ManagePause();
	void ManageSceneGameButtonsPause(bool _states);
	void CreatePauseMenuButtons();

	//PLAYER 
	GameObject* CreateTowerGameObject(const std::string& name, float positionx, float positiony, const sf::Texture texture, float scalex, float scaley);
	GameObject* CreateBatimantGameObject(const std::string& name, float _x, float _y, const sf::Texture texture, float scalex, float scaley, float prixGold, float prixMana);
	GameObject* CreateBulletGameObject(const std::string& name, const sf::Texture textureBullet, float scalex, float scaley, GameObject* _player);
	GameObject* CreatePlayerRessourceGameObject(const std::string& name, float _x, float _y, const sf::Texture texture, float scalex, float scaley, float ressourceGold, float ressourceMana);
	GameObject* CreateGruntGameObject(const std::string& name, float positionx, float positiony, float scalex, float scaley, sf::Texture _texture);

	GameObject* CreateTurretGameObject(const std::string& name, float positionx, float positiony, float scalex, float scaley, sf::Texture _texture);


	void CreatePlatform(sf::Texture texture);
	void CreateBackground();
	void Create() override;
	void Delete() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;
	std::vector<GameObject*> GetEnemies() { return enemies; }
	GameObject* GetEnemie(int _index) { return enemies[_index]; }

protected:
	std::vector<GameObject*> enemies;
	GameObject* player = nullptr;
	GameObject* jiin = nullptr;
	GameObject* lulu = nullptr;
	GameObject* malphite = nullptr;
	GameObject* xinZhao = nullptr;
	GameObject* bat2 = nullptr;
	GameObject* bat3 = nullptr;
	GameObject* ressource = nullptr;
	GameObject* pausePlayButton = nullptr;
	GameObject* pauseOptionsButton = nullptr;
	GameObject* pauseMenuPrincipalButton = nullptr;
	GameObject* pauseQuitButton = nullptr;
	GameObject* pauseBongoButton = nullptr;
	sf::Texture* texture;
};

