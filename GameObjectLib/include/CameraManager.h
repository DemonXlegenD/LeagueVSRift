#pragma once
#include <SFML/Graphics.hpp>


class CameraManager
{
public:
	CameraManager(sf::RenderWindow* _window);

    void Update();

    void Move(float offsetX, float offsetY);

    void SetCenter(float x, float y);

private:
    sf::RenderWindow* window;
    sf::View view;
};

