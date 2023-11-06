#include "SceneManager.h"


PauseCommand::PauseCommand() {

}

void PauseCommand::Execute(sf::Time _delta) {
	std::cout << "Pause" << std::endl;
	SceneManager::GetActiveGameScene()->SetIsActive(!SceneManager::GetActiveGameScene()->GetIsActive());
}