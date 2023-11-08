#pragma once

#include <SFML/Graphics.hpp>
class HUDManager
{
public:
	HUDManager();
	static sf::View GetHud() { return hudView; }
private:
	static sf::View hudView;
	static std::vector<sf::Vector2f> column;
	static std::vector<sf::Vector2f> line;
};

