#include "Scenes/ScenesGame/SceneGameLVSR.h"
#include "SceneManager.h"
#include "AssetManager.h"
#include "AudioManager.h"
#include "WindowManager.h"
#include "CameraManager.h"
#include "Round/CreateRound.h"
#include "SceneManager.h"
#include "Components/Carre.h"
#include "Components/Entities/Enemies/EnemyA.h"
#include "Components/Entities/Towers/Nexus.h"
#include "Components/Carre.h"
#include "Components/Button.h"
#include "Components/Ressource.h"
#include "HUDManager.h"

SceneGameLVSR::SceneGameLVSR(sf::RenderWindow* _window) : SceneGameAbstract(_window) {
	scale = 1.0f;
	CameraManager::SetCenter(WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2);
}

SceneGameLVSR::~SceneGameLVSR(){}

void SceneGameLVSR::Awake() 
{
	SceneGameAbstract::Awake();
}

void SceneGameLVSR::CreateSpawn() {
	spawns.push_back(CreateCarreGameObject("Spawn0", WindowManager::GetWindowWidth() / 2.38, WindowManager::GetWindowHeight() / 1.06));
	spawns.push_back(CreateCarreGameObject("Spawn1", WindowManager::GetWindowWidth() / 3.05, WindowManager::GetWindowHeight() / 1.31));
	spawns.push_back(CreateCarreGameObject("Spawn2", WindowManager::GetWindowWidth() / 3.56, WindowManager::GetWindowHeight() / 1.48));
	spawns.push_back(CreateCarreGameObject("Spawn3", WindowManager::GetWindowWidth() / 5.52, WindowManager::GetWindowHeight() / 1.94));
	spawns.push_back(CreateCarreGameObject("Spawn4", WindowManager::GetWindowWidth() / 2.34, WindowManager::GetWindowHeight() / 1.43));
	spawns.push_back(CreateCarreGameObject("Spawn5", WindowManager::GetWindowWidth() / 3.01, WindowManager::GetWindowHeight() / 1.78));
	spawns.push_back(CreateCarreGameObject("Spawn6", WindowManager::GetWindowWidth() / 1.76, WindowManager::GetWindowHeight() / 1.29));
	spawns.push_back(CreateCarreGameObject("Spawn7", WindowManager::GetWindowWidth() / 2.09, WindowManager::GetWindowHeight() / 1.72));
	spawns.push_back(CreateCarreGameObject("Spawn8", WindowManager::GetWindowWidth() / 2.55, WindowManager::GetWindowHeight() / 2.08));
	spawns.push_back(CreateCarreGameObject("Spawn9", WindowManager::GetWindowWidth() / 3.06, WindowManager::GetWindowHeight() / 2.81));
	spawns.push_back(CreateCarreGameObject("Spawn10", WindowManager::GetWindowWidth() / 2.91, WindowManager::GetWindowHeight() / 3.87));
	spawns.push_back(CreateCarreGameObject("Spawn11", WindowManager::GetWindowWidth() / 2.02, WindowManager::GetWindowHeight() / 2.63));
	spawns.push_back(CreateCarreGameObject("Spawn12", WindowManager::GetWindowWidth() / 1.77, WindowManager::GetWindowHeight() / 2.11));
	spawns.push_back(CreateCarreGameObject("Spawn13", WindowManager::GetWindowWidth() / 1.45, WindowManager::GetWindowHeight() / 1.33));
}

void SceneGameLVSR::ChoiceTower()
{
	for (size_t i = 0; i < HUDManager::GetHudGameObjects().size(); i++)
	{
		if (HUDManager::GetHudGameObject(i)->GetComponent<Button>()->IsClicked() && GetIsActive())
		{
			isChoice = false;
			index = i;
			break;
		}
	}
}

void SceneGameLVSR::ChoiceSpawn()
{
	for (size_t i = 0; i < spawns.size(); i++)
	{
		if (spawns[i]->GetComponent<Carre>()->IsClicked() && GetIsActive() && spawns[i]->GetActive())
		{
			spawns[i]->SetActive(false);
			CreateTower(gameTowers[index]->GetName(), spawns[i]->GetPosition().x, spawns[i]->GetPosition().y);
			isChoice = true;
		}
	}
}

bool SceneGameLVSR::CanPlaceTower(std::string name) {
	if (GetGameObject(name)->GetComponent<Ressource>()->GetGold() <= GetGameObject("Ressources")->GetComponent<Ressource>()->GetGold() &&
		GetGameObject(name)->GetComponent<Ressource>()->GetGold() <= GetGameObject("Ressources")->GetComponent<Ressource>()->GetMana())
	{
		return true;
	}
	return false;
}

void SceneGameLVSR::CreateTower(std::string towerName, float _positionX, float _positionY)
{
	if (CanPlaceTower(towerName))
	{
		float scale = GetGameObject(towerName)->GetComponent<Sprite>()->GetSize().x > 200 ? 0.2f : 0.5f;
		CreateBatimentGameObject(towerName, _positionX, _positionY, *AssetManager::GetAsset(towerName), scale, scale, 400.f, 30.f);
	}
}

void SceneGameLVSR::Create() 
{
	SceneGameAbstract::Create();
	GameObject* background = CreateBackgroundGameObject("Background", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2, *AssetManager::GetAsset("mapLol"));

	SceneGameLVSR::CreateSpawn();
	SceneGameAbstract::CreateTower();
	SceneGameAbstract::CreateRessource();

	//GameObject* enemy = CreateEnemyAGameObject("enemy", 1411.f, 157.f, 0.3f , 0.3f, 1, *AssetManager::GetAsset("EnemyA"));
	GameObject* nexus = CreateNexusGameObject();


	HUDManager::AddGameObjectHud(CreateButtonGameObject("Tour 1", HUDManager::GetSquareCenter("8").x, HUDManager::GetSquareCenter("8").y, 20));
	HUDManager::AddGameObjectHud(CreateButtonGameObject("Tour 2", HUDManager::GetSquareCenter("17").x, HUDManager::GetSquareCenter("17").y, 20));
	HUDManager::AddGameObjectHud(CreateButtonGameObject("Tour 3", HUDManager::GetSquareCenter("26").x, HUDManager::GetSquareCenter("26").y, 20));
	HUDManager::AddGameObjectHud(CreateButtonGameObject("Tour 4", HUDManager::GetSquareCenter("35").x, HUDManager::GetSquareCenter("35").y, 20));
	HUDManager::AddGameObjectHud(CreateButtonGameObject("Tour 5", HUDManager::GetSquareCenter("44").x, HUDManager::GetSquareCenter("44").y, 20));
}

void SceneGameLVSR::Delete() 
{
	SceneGameAbstract::Delete();
}


void SceneGameLVSR::TakeNexusDamage(int damage) {
	nexus->GetComponent<Entity>()->SetHealthPoint(nexus->GetComponent<Entity>()->GetHealthPoint() - damage);
	AudioManager::Play("nexus_under_attack");
}

void SceneGameLVSR::Update(sf::Time _delta) 
{
	SceneGameAbstract::Update(_delta);
	if (nexus->GetComponent<Nexus>()->GetHealthPoint() == 0) {
		GameEnd(false, _delta);
		if (isChoice)
		{
			ChoiceTower();
		}
		else
		{
			ChoiceSpawn();
		}
	}

	if (round.getRound() == 1) {
		this->round.CreateRound1(_delta);
	}
	else if (round.getRound() == 2) {
		this->round.CreateRound2(_delta);
	}
	else if (round.getRound() == 3) {
		this->round.CreateRound3(_delta);
	}
	else {
		this->round.CreateRound4(_delta);
	}

	for (int i = 0; i < enemies.size(); i++) {
		GameObject* enemy = enemies[i];
		Entity* enemyComponent = enemy->GetComponent<Entity>();
		Maths::Vector2i goal;
		bool isGoalNexus = enemyComponent->GetCurrPathPoint() >= lanes[enemyComponent->GetLane()].size();

		if (isGoalNexus) {
			goal = Maths::Vector2i(480, 840);
		}
		else {
			goal = lanes[enemyComponent->GetLane()][enemyComponent->GetCurrPathPoint()];
		}

		float distance = (enemy->GetPosition() - Maths::Vector2f(goal.x, goal.y)).Magnitude();
		enemyComponent->MoveToPoint(goal, enemyComponent->GetSpeed() / 10);

		if (distance < 10) {
			if (isGoalNexus) {
				TakeNexusDamage(enemyComponent->GetHealthPoint());
				std::cout << "LE NEXUS A PRIT " << enemyComponent->GetHealthPoint() << " DEGATS. IL LUI RESTE " << nexus->GetComponent<Entity>()->GetHealthPoint() << " PV" << std::endl;
				enemyComponent->Die();
			}
			else {
				enemyComponent->SetCurrPathPoint(enemyComponent->GetCurrPathPoint() + 1);
			}
		}
	}
}

void SceneGameLVSR::Render(sf::RenderWindow* _window) 
{
	SceneGameAbstract::Render(_window);
}

