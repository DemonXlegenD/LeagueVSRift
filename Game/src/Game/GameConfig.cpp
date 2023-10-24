#include "Game/GameConfig.h"

GameConfig::GameConfig() {
	this->window = new sf::RenderWindow(sf::VideoMode(600, 600), "RAMBO", sf::Style::Fullscreen);
	this->actualScene = new Scene();
}

void GameConfig::Update() {
	// Mesurer le temps �coul� depuis le dernier frame
	sf::Time delta = clock.restart();

	// Si vous souhaitez limiter � un nombre fixe de FPS
	sf::Time frameTime = sf::seconds(1.0f / FPS);
	//Delta time for the update
	if (delta < frameTime)
	{
		sf::sleep(frameTime - delta);
		delta = frameTime;
	}

	actualScene->Update(delta);

	window->clear(sf::Color::Black);

	actualScene->Render(window);
	window->display();
}

GameConfig::~GameConfig() {
	delete window;
	delete actualScene;
}
