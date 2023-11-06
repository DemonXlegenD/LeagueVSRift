#pragma once

#include "Command.h"

class PauseCommand : public Command
{
public:
	PauseCommand();
	void Execute(sf::Time _delta) override;
};

