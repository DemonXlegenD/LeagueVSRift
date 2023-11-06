#include "Game/GameState.h"
#include "SceneManager.h"
#include "AudioManager.h"
#include "AssetManager.h"
#include "SceneMainMenu.h"
#include "SceneSuccessMenu.h"
#include "SceneRankMenu.h"
#include "SceneGameLVSR.h"

GameState::GameState(sf::RenderWindow* _window, int _FPS) {
	this->window = _window;
	this->FPS = _FPS;
	SceneManager::SetFps(this->FPS);
}


void GameState::Preload() {
	
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
}

void GameState::PreloadAudio() {

}


void GameState::Update() {
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window->close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::LAlt) if (event.key.code == sf::Keyboard::F4) window->close();
		}
	}
	// Mesurer le temps écoulé depuis le dernier frame
	sf::Time delta = this->clock.restart();

	// limiter à un nombre fixe de FPS
	sf::Time frameTime = sf::seconds(1.0f / FPS);
	//Delta time for the update
	if (delta < frameTime)
	{
		sf::sleep(frameTime - delta);
		delta = frameTime;
	}

	SceneManager::GetActiveScene()->Update(delta);

	this->window->clear(sf::Color::Black);

	SceneManager::GetActiveScene()->Render(this->window);
	this->window->display();
}

GameState::~GameState() {
}

