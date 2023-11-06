#include "Components/Inputs/InputGame.h"
#include "SceneManager.h"

InputGame::InputGame() 
{
	this->KeyEscape_ = new PauseCommand();
}
void InputGame::Update(sf::Time _delta)
{
	Component::Update(_delta);
	Command* pauseInput = this->PauseInput();
	if (pauseInput)
	{
		pauseInput->Execute(_delta);
	} 
}

Command* InputGame::PauseInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !isKeyEscapeAlreadyPressed) {
		isKeyEscapeAlreadyPressed = true;
		return KeyEscape_;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		isKeyEscapeAlreadyPressed = false;
	}
	return nullptr;

}

