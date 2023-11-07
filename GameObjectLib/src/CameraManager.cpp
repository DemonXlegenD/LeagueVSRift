#include "CameraManager.h"

sf::RenderWindow* CameraManager::window;
sf::View CameraManager::view;


void CameraManager::SetWindow(sf::RenderWindow* _window) {
    CameraManager::window = _window;
    CameraManager::view = CameraManager::window->getDefaultView();
}

void CameraManager::Update() {
    CameraManager::window->setView(view);
}

void CameraManager::Update(sf::Time _delta) {
    CameraManager::window->setView(view);
}

void CameraManager::Move(float offsetX, float offsetY) {
    CameraManager::view.move(offsetX, offsetY);
}

void CameraManager::SetCenter(float x, float y) {
    CameraManager::view.setCenter(x, y);
}

void CameraManager::Zoom(float factor) {
    CameraManager::view.zoom(factor);
}