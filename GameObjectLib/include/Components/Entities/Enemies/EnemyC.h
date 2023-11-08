#include "Components/Entities/EnemyAbstract.h"
#include "Components/SpriteRenderer.h"

class EnemyC : public EnemyAbstract {
public:
	EnemyC(int _lane);
private:
	Sprite sprite;
};