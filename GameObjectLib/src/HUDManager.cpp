#include "HUDManager.h"
#include "WindowManager.h"

std::vector<sf::Vector2f> HUDManager::line;


HUDManager::HUDManager() {
	int width = WindowManager::GetWindowWidth();
	int height = WindowManager::GetWindowHeight();
	for (int i = 0; i < 16; i++) {
		HUDManager::column.push_back(sf::Vector2f(width / 16 * i, width / 16 * (i+1)));
	}
	for (int i = 0; i < 9; i++) {
		HUDManager::line.push_back(sf::Vector2f(height / 9 * i, height / 9 * (i + 1)));
	}
}