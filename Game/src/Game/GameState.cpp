#include "Game/GameState.h"
#include "SceneManager.h"
//#include "AudioManager.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "CameraManager.h"
#include "HUDManager.h"
#include "EventManager.h"
#include "SceneMainMenu.h"
#include "SceneSuccessMenu.h"
#include "SceneRankMenu.h"
#include "SceneGameLVSR.h"

GameState::GameState(sf::RenderWindow* _window, int _FPS) {
	this->window = _window;
	this->FPS = _FPS;
	WindowManager::SetFps(this->FPS);
	CameraManager::SetWindow(this->window);
	EventManager::SetEvent(this->event);
}


void GameState::Preload() {
	HUDManager::Preload();
	this->PreloadScenes();
	this->PreloadAudio();
	this->PreloadAssets();
}

void GameState::Create() {
	SceneManager::RunScene("SceneMainMenu");

}

void GameState::PreloadScenes() {
	SceneManager::AddScene("SceneMainMenu", new SceneMainMenu(this->window));
	SceneManager::AddScene("SceneSuccessMenu", new SceneSuccessMenu(this->window));
	SceneManager::AddScene("SceneRankMenu", new SceneRankMenu(this->window));
	SceneManager::AddScene("SceneGameLVSR", new SceneGameLVSR(this->window));
}

void GameState::PreloadAssets() {
	AssetManager::AddAsset("mapLol", "../assets/Sprite_LOL/Map/map.jpg");
	AssetManager::AddAsset("Varus", "../assets/Sprite_LOL/Champions/varus.png");
	AssetManager::AddAsset("Lulu", "../assets/Sprite_LOL/Champions/lulu.png");
	AssetManager::AddAsset("Malphite", "../assets/Sprite_LOL/Champions/malphite.png");
	AssetManager::AddAsset("XinZhao", "../assets/Sprite_LOL/Champions/xin_zhao.png");
	AssetManager::AddAsset("Gold", "../assets/Sprite_LOL/Ressources/Gold.png");
}

void GameState::PreloadAudio() {

}


void GameState::Update() {
	
	sf::Time delta = this->clock.restart();

	// limiter à un nombre fixe de FPS
	sf::Time frameTime = sf::seconds(1.0f / FPS);
	//Delta time for the update
	if (delta < frameTime)
	{
		sf::sleep(frameTime - delta);
		delta = frameTime;
	}

	EventManager::Update(delta);
	SceneManager::GetActiveScene()->Update(delta);

	this->window->clear(sf::Color::Black);

	SceneManager::GetActiveScene()->Render(this->window);
	this->window->display();
}

GameState::~GameState() {
}

