#include "Components/Inputs/InputGame.h"
#include "SceneManager.h"

InputGame::InputGame() 
{
	sf::Vector2i lastMousePosition = sf::Mouse::getPosition();
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

	Command* wheelScroll = this->WheelMouseInput();
	if (wheelScroll)
	{
		std::cout << "wheel" << std::endl;
		wheelScroll->Execute(_delta);
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

Command* InputGame::WheelMouseInput()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition();
	sf::Vector2i delta = mousePosition - lastMousePosition;

	if (delta.y > 0) {
		WheelMouseScroll_ = new DezoomCommand();
		return WheelMouseScroll_;
	}
	else if (delta.y < 0) {
		WheelMouseScroll_ = new ZoomCommand();
		return WheelMouseScroll_;
	}
	return nullptr;

}




