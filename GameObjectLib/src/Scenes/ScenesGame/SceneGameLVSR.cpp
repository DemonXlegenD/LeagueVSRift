#include "Scenes/ScenesGame/SceneGameLVSR.h"
#include "SceneManager.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "CameraManager.h"
#include "Round/CreateRound.h"
#include "SceneManager.h"
#include "Components/Carre.h"
#include "Components/Entities/Enemies/EnemyA.h"
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


void SceneGameLVSR::CreateActiveSpawn()
{
	for (size_t i = 0; i <= towers.size(); i++)
	{
		if (GetGameObject("Spawn" + std::to_string(i))->GetComponent<Carre>()->IsClicked() && GetIsActive())
		{
			std::cout << "c'est bon";
		}
	}
}

void SceneGameLVSR::Create() 
{
	SceneGameAbstract::Create();
	SceneGameLVSR::CreateSpawn();
	GameObject* background = CreateBackgroundGameObject("Background", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2, *AssetManager::GetAsset("mapLol"));
	GameObject* enemy = CreateEnemyAGameObject("enemy", 1411.f, 157.f, 0.3f , 0.3f,*AssetManager::GetAsset("EnemyA"));
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

void SceneGameLVSR::Update(sf::Time _delta) 
{
	if (round == 0) {
		round++;
		CreateRound round1;
		round1.CreateRound1();
		std::cout << "round started";
	}

	for (int i = 0; i < enemies.size(); i++) {
		GameObject* enemy = enemies[i];
		Entity* enemyComponent = enemy->GetComponent<Entity>();
		Maths::Vector2i goal;

		if (enemyComponent->GetCurrPathPoint() >= lanes[enemyComponent->GetLane()].size()) {
			goal = Maths::Vector2i(480, 840);
		}
		else {
			goal = lanes[enemyComponent->GetLane()][enemyComponent->GetCurrPathPoint()];
		}

		float distance = (enemy->GetPosition() - Maths::Vector2f(goal.x, goal.y)).Magnitude();
		enemyComponent->MoveToPoint(goal, enemyComponent->GetSpeed() / 10);

		if (distance < 10) {
			enemyComponent->SetCurrPathPoint(enemyComponent->GetCurrPathPoint() + 1);
		}
	}
	SceneGameAbstract::Update(_delta);
}
void SceneGameLVSR::Render(sf::RenderWindow* _window) 
{
	SceneGameAbstract::Render(_window);
}