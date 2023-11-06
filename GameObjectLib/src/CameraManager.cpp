#include "CameraManager.h"

CameraManager::CameraManager(sf::RenderWindow* _window) {
	this->window = _window;
	this->view = this->window->getDefaultView();
}

void CameraManager::Update() {
    this->window->setView(view);
}

void CameraManager::Move(float offsetX, float offsetY) {
    this->view.move(offsetX, offsetY);
}

void CameraManager::SetCenter(float x, float y) {
    this->view.setCenter(x, y);
}