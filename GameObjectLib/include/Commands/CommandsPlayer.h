#pragma once
#include "Components/Inputs/InputPlayer.h"

class InputPlayer;

class MoveToRightCommand : public Command
{
public:
	MoveToRightCommand(GameObject* _player);
	void Execute(sf::Time _delta) override;

};

class MoveToLeftCommand : public Command
{
public:
	MoveToLeftCommand(GameObject* _player);

	void Execute(sf::Time _delta) override;

};

class JumpCommand : public Command
{
public:
	JumpCommand(GameObject* _player);
	void Execute(sf::Time _delta) override;

};

class MoveToRightBulletCommand : public Command
{
public:
	MoveToRightBulletCommand(GameObject* _player);
	void Execute(sf::Time _delta) override;

};


