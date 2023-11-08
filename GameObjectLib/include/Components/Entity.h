#pragma once
#include "Component.h"
class Entity : public Component
{
public:
    Entity();
    Entity(int _hp, int _damage, float _speed,float _attackspeed, float _range);

    int GetHealthPoint() const { return healthPoint; }
    int GetMaxHealthPoint() const { return maxHealthPoint; }
    int GetDamage() const { return damage; }
    float GetSpeed() const { return speed; }
    float GetAttackSpeed() const { return attackspeed; }
    float GetRange() const { return range; }

    void SetHealthPoint(const int _hp)  { healthPoint = _hp;}
    void SetMaxHealthPoint(const int _maxHp)  { maxHealthPoint = _maxHp;}
    void SetDamage(const int _damage)  { damage = _damage; }
    void SetSpeed(const float _speed)  {  speed = _speed; }
    void SetAttackSpeed(const float _attackspeed) { speed = _attackspeed; }
    void SetRange(const float _range) { speed = _range; }


    void TakeDamage(int damage);
    virtual void Die();
    void Update(sf::Time _delta) override;

protected:
    int healthPoint;
    int maxHealthPoint;
    int damage;
    float speed;
    float attackspeed;
    float range;


};
