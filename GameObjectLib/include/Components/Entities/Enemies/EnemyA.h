#include "Components/Entities/EnemyAbstract.h"
#include "Components/SpriteRenderer.h"

class EnemyA : public EnemyAbstract {
public:
	EnemyA(int _lane);
private:
	Sprite sprite;
};