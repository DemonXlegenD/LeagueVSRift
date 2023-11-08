#include "Scenes/ScenesGame/SceneGameLVSR.h"
#include "SceneManager.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "CameraManager.h"
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


void SceneGameLVSR::Create() 
{
	SceneGameAbstract::Create();
	GameObject* background = CreateBackgroundGameObject("Background", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2, *AssetManager::GetAsset("mapLol"));
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
	
	SceneGameAbstract::Update(_delta);
}
void SceneGameLVSR::Render(sf::RenderWindow* _window) 
{
	SceneGameAbstract::Render(_window);
}