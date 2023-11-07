#pragma once

#include "Command.h"

class PauseCommand : public Command
{
public:
	PauseCommand();
	void Execute(sf::Time _delta) override;
};


class ZoomCommand : public Command
{
public:
	ZoomCommand();
	void Execute(sf::Time _delta) override;
};


class DezoomCommand : public Command
{
public:
	DezoomCommand();
	void Execute(sf::Time _delta) override;
};