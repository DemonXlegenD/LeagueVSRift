#include "Scenes/ScenesGame/SceneGameLVSR.h"
#include "SceneManager.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "CameraManager.h"


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
	GameObject* enemy = CreateEnemyAGameObject("enemy", 1411.f, 157.f, 0.3f , 0.3f,*AssetManager::GetAsset("EnemyA"));
	GameObject* nexus = CreateNexusGameObject();
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