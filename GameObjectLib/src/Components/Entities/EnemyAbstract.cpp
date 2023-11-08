#include "Components/Entities/EnemyAbstract.h"
#include "WindowManager.h"
#include "SceneManager.h"

EnemyAbstract::EnemyAbstract() : Entity() {}

EnemyAbstract::EnemyAbstract(int _hp, int _damage, int _lane, float _speed,float _attackSpeed, float _range ) : Entity(_hp, _damage, _lane, _speed, _attackSpeed, _range) {}

void EnemyAbstract::Update(sf::Time _delta)
{
	Entity::Update(_delta);

	if (GetOwner()->GetPosition().GetX() > WindowManager::GetWindowWidth()
		|| GetOwner()->GetPosition().GetY() > WindowManager::GetWindowHeight()
		|| GetOwner()->GetPosition().GetY() < 0
		|| GetOwner()->GetPosition().GetX() < 0
		)
	{
		this->Die();
	}
}

void EnemyAbstract::Die()
{
	SceneManager::GetActiveGameScene()->RemoveEnemy(GetOwner());
	Entity::Die();
}

void EnemyAbstract::Attack(GameObject* tour) {
	std::cout << "L'ennemie attaque la tour" << std::endl;
}

