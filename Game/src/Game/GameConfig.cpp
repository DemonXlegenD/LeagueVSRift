#include "Game/GameConfig.h"
#include "SceneManager.h"
#include "AudioManager.h"
#include "WindowManager.h"


GameConfig::GameConfig() {
	this->FPS = 240;
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "RAMBO", sf::Style::Fullscreen);
	WindowManager::SetWindow(this->window);
	WindowManager::SetFps(this->FPS);
	AudioManager::AddMusic(std::string("soundtrack"), std::string("../assets/Sounds/soundtrack.ogg"));
	AudioManager::AddMusic(std::string("round_start"), std::string("../assets/Sounds/round_start.ogg"));
	AudioManager::AddMusic(std::string("nexus_under_attack"), std::string("../assets/Sounds/nexus_under_attack.ogg"));
	AudioManager::AddMusic(std::string("tower_placed"), std::string("../assets/Sounds/tower_placed.ogg"));
	AudioManager::AddMusic(std::string("tower_already_placed"), std::string("../assets/Sounds/tower_already_placed.ogg"));
	AudioManager::AddMusic(std::string("Lulu_attack"), std::string("../assets/Sounds/Lulu/Lulu_Select_SFX.ogg"));
	AudioManager::AddMusic(std::string("Malphite_attack"), std::string("../assets/Sounds/Malphite/Malphite_Select_SFX.ogg"));
	AudioManager::AddMusic(std::string("Varus_attack"), std::string("../assets/Sounds/Varus/Varus_Select_SFX.ogg"));
	AudioManager::AddMusic(std::string("XinZhao_attack"), std::string("../assets/Sounds/Xin_Zhao/Xin_Zhao_Select_SFX.ogg"));
	AudioManager::AddMusic(std::string("Bat1_attack"), std::string("../assets/Sounds/Bat_SFX.ogg"));
	AudioManager::AddMusic(std::string("Bat2_attack"), std::string("../assets/Sounds/Bat_SFX.ogg"));
	//AudioManager::AddSound(std::string("dead"), std::string("../Sounds/pas_ma_guerre.mp3"));
	//AudioManager::Play(std::string("valkyrieApocalypse"));
	/*AudioManager::AddMusic(std::string("valkyrieApocalypse"), std::string("../Sounds/valkyrie.mp3"));
	AudioManager::AddSound(std::string("dead"), std::string("../Sounds/pas_ma_guerre.mp3"));*/
	AudioManager::Play(std::string("soundtrack"));
}

GameConfig::~GameConfig() {
	delete this->window;
}
