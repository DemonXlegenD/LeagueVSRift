#include "Scenes/ScenesGame/SceneGameLVSR.h"
#include "SceneManager.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "CameraManager.h"
#include "SceneManager.h"
#include "Components/Carre.h"
#include "Components/Entities/Enemies/EnemyA.h"
#include "Components/Carre.h"
#include "Components/Button.h"
#include "Create/CreateTours.h"
#include "HUDManager.h"


SceneGameLVSR::SceneGameLVSR(sf::RenderWindow* _window) : SceneGameAbstract(_window){
	scale = 1.f;
	CameraManager::SetCenter(WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight()/2);
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
		if (spawns[i]->GetComponent<Carre>()->IsClicked() && GetIsActive())
		{
			std::cout << index;
			CreateTours::CreateTower(index, spawns[i]->GetPosition().x, spawns[i]->GetPosition().y);
			isChoice = true;
		}
	}
}


void SceneGameLVSR::Create() 
{
	SceneGameAbstract::Create();
	GameObject* background = CreateBackgroundGameObject("Background", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2, *AssetManager::GetAsset("mapLol"));
	SceneGameLVSR::CreateSpawn();
	SceneGameAbstract::CreateTower();
	SceneGameAbstract::CreateRessource();
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
	/*EnemyA enemya;
	enemya.Check();*/
	SceneGameAbstract::Update(_delta);
	if(isChoice)
	{
		ChoiceTower();
	}
	else
	{
		ChoiceSpawn();
	}
}
void SceneGameLVSR::Render(sf::RenderWindow* _window) 
{
	SceneGameAbstract::Render(_window);
}