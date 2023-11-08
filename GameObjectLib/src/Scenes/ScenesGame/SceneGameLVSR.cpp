#include "Scenes/ScenesGame/SceneGameLVSR.h"
#include "SceneManager.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "CameraManager.h"
#include "SceneManager.h"
#include "Components/Carre.h"


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
}

void SceneGameLVSR::Delete() 
{
	SceneGameAbstract::Delete();
}

void SceneGameLVSR::Update(sf::Time _delta) 
{
	
	SceneGameAbstract::Update(_delta);
}
void SceneGameLVSR::Render(sf::RenderWindow* _window) 
{
	SceneGameAbstract::Render(_window);
}