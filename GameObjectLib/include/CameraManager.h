#pragma once
#include <SFML/Graphics.hpp>


class CameraManager
{
public:

    static void SetWindow(sf::RenderWindow* _window);

    static void Update(sf::Time _delta);
    static void Update();

    static void Move(float offsetX, float offsetY);

    static void SetCenter(float x, float y);

    static void Zoom(float factor);

private:
    static sf::RenderWindow* window;
    static sf::View view;
};

