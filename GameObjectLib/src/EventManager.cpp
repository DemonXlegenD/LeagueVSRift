#include "EventManager.h"
#include "WindowManager.h"
#include "CameraManager.h"
#include <iostream>
sf::Event EventManager::event = sf::Event();
bool isDragging = false;
sf::Vector2i lastMousePos;

void EventManager::Update(sf::Time _delta)
{
	sf::RenderWindow* window = WindowManager::GetWindow();

	while (window->pollEvent(EventManager::event))
	{
		if (event.type == sf::Event::Closed) window->close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::LAlt) if (event.key.code == sf::Keyboard::F4) window->close();
		}
		CameraManager::Event(event);
		
	}
	CameraManager::Update(_delta);
}