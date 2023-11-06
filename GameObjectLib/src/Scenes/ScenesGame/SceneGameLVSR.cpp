#include "Scenes/ScenesGame/SceneGameLVSR.h"
#include "SceneManager.h"
#include "AssetManager.h"


SceneGameLVSR::SceneGameLVSR(sf::RenderWindow* _window) : SceneGameAbstract(_window){
	
}
SceneGameLVSR::~SceneGameLVSR(){}

void SceneGameLVSR::Awake() 
{
	SceneGameAbstract::Awake();
}


void SceneGameLVSR::Create() 
{
	SceneGameAbstract::Create();
	GameObject* background = CreateBackgroundGameObject("Background", SceneManager::GetWindowWidth() / 2, SceneManager::GetWindowHeight() / 2, *AssetManager::GetAsset("mapLol"));
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