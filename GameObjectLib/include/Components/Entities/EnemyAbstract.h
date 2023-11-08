#pragma once
#include "Components/Entity.h"
#include "Scene.h"

class EnemyAbstract : public Entity {
public:
    EnemyAbstract();
    EnemyAbstract(int _hp, int _damage, int _lane, float _speed, float _attackSpeed);

    void Update(sf::Time _delta) override;

    void Die() override;

    void Attack(GameObject* tour);
};