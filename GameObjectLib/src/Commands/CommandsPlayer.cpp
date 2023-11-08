#include "Commands/CommandsPlayer.h"
#include "Components/Entities/Player.h"
#include "Components/SpriteRenderer.h"

MoveToRightCommand::MoveToRightCommand(GameObject* _player) : Command(_player) {

}
void MoveToRightCommand::Execute(sf::Time _delta) {

	this->entity->SetPosition(this->entity->GetPosition() + Maths::Vector2f::Right + Maths::Vector2f(25, 0) * _delta.asSeconds() );
	this->entity->GetComponent<Player>()->setDirection(Player::Direction::Right);
	this->entity->GetComponent<Sprite>()->PlayerPlayAnimationRun();
}

JumpCommand::JumpCommand(GameObject* _player) : Command(_player) {
}
void JumpCommand::Execute(sf::Time _delta) {
	this->entity->SetPosition(this->entity->GetPosition() + Maths::Vector2f::Down + Maths::Vector2f(0, -130) * _delta.asSeconds() );
}

MoveToLeftCommand::MoveToLeftCommand(GameObject* _player) : Command(_player) {
}

void MoveToLeftCommand::Execute(sf::Time _delta) {
	this->entity->SetPosition(this->entity->GetPosition() + Maths::Vector2f::Left + Maths::Vector2f(-25, 0) * _delta.asSeconds() );
	this->entity->GetComponent<Player>()->setDirection(Player::Direction::Left);
	this->entity->GetComponent<Sprite>()->PlayerPlayAnimationRun();
}

MoveToRightBulletCommand::MoveToRightBulletCommand(GameObject* _player) : Command(_player) {

}

void MoveToRightBulletCommand::Execute(sf::Time _delta) {

}
