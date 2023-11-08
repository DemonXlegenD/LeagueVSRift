#include "Game/GameState.h"
#include "SceneManager.h"
#include "AudioManager.h"
#include "AssetManager.h"
#include "SceneMainMenu.h"
#include "SceneSuccessMenu.h"
#include "SceneCreditsMenu.h"
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
	SceneManager::AddScene("SceneCreditsMenu", new SceneCreditsMenu(this->window));
	SceneManager::AddScene("SceneGameLVSR", new SceneGameLVSR(this->window));
}

void GameState::PreloadAssets() {
	//Map
	AssetManager::AddAsset("mapLol", "../assets/Sprite_LOL/Map/map.jpg");
	//BackGrund
	AssetManager::AddAsset("backgroundMenu", "../assets/Sprite_LOL/Background/background_lol.png");
	AssetManager::AddAsset("backgroundOtherMenu", "../assets/Sprite_LOL/Background/background2_lol.png");
	//Boss
	AssetManager::AddAsset("bossErald", "../assets/Sprite_LOL/Boss/erald.png");
	AssetManager::AddAsset("bossVeigar", "../assets/Sprite_LOL/Boss/veigar.png");
	//Champions
	AssetManager::AddAsset("championsJin", "../assets/Sprite_LOL/Champions/jin.png");
	AssetManager::AddAsset("championsLulu", "../assets/Sprite_LOL/Champions/lulu.png");
	AssetManager::AddAsset("championsMalphite", "../assets/Sprite_LOL/Champions/malphite.png");
	AssetManager::AddAsset("championsXinZhao", "../assets/Sprite_LOL/Champions/xinZhao.png");
	//Minions
	AssetManager::AddAsset("minionMage", "../assets/Sprite_LOL/Minions/minion_mage.png");
	AssetManager::AddAsset("minionMelee", "../assets/Sprite_LOL/Minions/minion_melee.png");
	AssetManager::AddAsset("minionSiege", "../assets/Sprite_LOL/Minions/minion_siege.png");
	//Batiments
	for (size_t i = 0; i < 3; i++)
	{
		AssetManager::AddAsset("batiments" + std::to_string(i), "../assets/Sprite_LOL/Batiments/batiments_" + std::to_string(i) + ".png");
	}
	//Bullet
	for (size_t i = 0; i < 6; i++)
	{
		AssetManager::AddAsset("bullet" + std::to_string(i), "../assets/Sprite_LOL/Bullet/bullet_" + std::to_string(i) + ".png");
	}
	//Credits
	for (size_t i = 0; i < 6; i++)
	{
		AssetManager::AddAsset("credits" + std::to_string(i), "../assets/Sprite_LOL/Credits/credits_" + std::to_string(i) + ".png");
	}
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

