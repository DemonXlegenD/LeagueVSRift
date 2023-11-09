#include "SceneManager.h"
#include "CameraManager.h"

PauseCommand::PauseCommand() {

}

void PauseCommand::Execute(sf::Time _delta) {
	SceneManager::GetActiveGameScene()->SetIsActive(!SceneManager::GetActiveGameScene()->GetIsActive());
}

ZoomCommand::ZoomCommand() {

}

void ZoomCommand::Execute(sf::Time _delta) {
	CameraManager::Zoom(0.95f);
}

DezoomCommand::DezoomCommand() {
}

void DezoomCommand::Execute(sf::Time _delta) {
	CameraManager::Zoom(1.05f);
}