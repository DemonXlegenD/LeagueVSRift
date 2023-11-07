#pragma once

#include "Commands/CommandsGame.h"
#include "Components/Component.h"


class InputGame : public Component
{
public:
	InputGame();
	void Update(sf::Time _delta) override;
	Command* PauseInput();
	Command* WheelMouseInput();

private:
	Command* KeyEscape_;
	bool isKeyEscapeAlreadyPressed = true;

	Command* WheelMouseScroll_;
	sf::Vector2i lastMousePosition;
};

