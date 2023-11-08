#pragma once

#include "Scenes/SceneGameAbstract.h"

class SceneGameLVSR : public SceneGameAbstract
{
public:
	SceneGameLVSR(sf::RenderWindow* window);
	~SceneGameLVSR();

	void Awake() override;

	void Create() override;
	void Delete() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;
	float scale;

private:
	int round = 0;
	std::vector<Maths::Vector2i> lane1 = { Maths::Vector2i(1364, 138), Maths::Vector2i(696, 150) , Maths::Vector2i(578, 219), Maths::Vector2i(483, 646) };
	std::vector<Maths::Vector2i> lane2 = { Maths::Vector2i(1373, 203), Maths::Vector2i(1092, 418) , Maths::Vector2i(931, 524), Maths::Vector2i(720, 686) };
	std::vector<Maths::Vector2i> lane3 = { Maths::Vector2i(1474, 195), Maths::Vector2i(1534, 741) , Maths::Vector2i(1400, 890), Maths::Vector2i(750, 900) };
	std::vector<std::vector<Maths::Vector2i>> lanes = { lane1, lane2, lane3 };
};