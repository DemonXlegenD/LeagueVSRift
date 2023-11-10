#include "Round/CreateRound.h"
#include "SceneManager.h"
#include "AssetManager.h"
#include "AudioManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

CreateRound::CreateRound()
{
	round = 1;
};

void CreateRound::setRound(int _round) {
	round = _round;
}

int CreateRound::getRound() {
	return round;
}

void CreateRound::SetRoundInfos(int _roundInt) {
	std::ifstream fichier("../assets/Save/Round.txt");
	if (fichier.is_open()) {
		std::string ligne;
		while (getline(fichier, ligne)) {
			char comma;
			int Round, Waves, Ennemies, TimeBetweenWaves;
			std::istringstream lineValue(ligne);
			if (lineValue >> Round >> comma >> Waves >> comma >> Ennemies >> comma >> TimeBetweenWaves) {
				if (Round == _roundInt) {
					this->Info.Round = Round;
					this->Info.Waves = Waves;
					this->Info.Ennemies = Ennemies;
					this->Info.TimeBetweenWaves = TimeBetweenWaves;
				}
			}
		}
	}
	fichier.close();
};

void CreateRound::CreateRound1(sf::Time _delta)
{
	/*AudioManager::Play("round_start");*/
	/*CreateRound::SetRoundInfos(1);*/
	TimeInRound += _delta.asSeconds();
	CreateRound::SetRoundInfos(1);
	CreateRound::SpawnEnemy();
	
	
};
void CreateRound::CreateRound2(sf::Time _delta)
{
	TimeInRound += _delta.asSeconds();
	CreateRound::SetRoundInfos(2);
	CreateRound::SpawnEnemy();
};
void CreateRound::CreateRound3(sf::Time _delta)
{
	TimeInRound += _delta.asSeconds();
	CreateRound::SetRoundInfos(3);
	CreateRound::SpawnEnemy();
};
void CreateRound::CreateRound4(sf::Time _delta)
{
	TimeInRound += _delta.asSeconds();
	CreateRound::SetRoundInfos(4);
	CreateRound::SpawnEnemy();
};

void CreateRound::SpawnEnemy() {
	srand(static_cast<unsigned int>(time(0)));
	if (TimeInRound > TimeToWait) {
		TimeToWait = 1.f;
		int EnnemyType = rand() % 3 + 1;
		int Lane = rand() % 3;
		if (EnnemyType == 1) {
			GameObject* EnemyA = SceneManager::GetActiveGameScene()->CreateEnemyAGameObject("Jin", 1411, 150, 0.1, 0.1, Lane, *AssetManager::GetAsset("minionMelee"));
		}
		else if (EnnemyType == 2) {
			GameObject* EnemyB = SceneManager::GetActiveGameScene()->CreateEnemyBGameObject("Jin", 1411, 150, 0.1, 0.1, Lane, *AssetManager::GetAsset("minionSiege"));
		}
		else {
			GameObject* EnemyC = SceneManager::GetActiveGameScene()->CreateEnemyCGameObject("Jin", 1411, 150, 0.1, 0.1, Lane, *AssetManager::GetAsset("minionMage"));
		}
		TimeInRound = 0.f;
		EnemiesSpawnedInWave++;
		std::cout << "Ennemies spawned =" << EnemiesSpawnedInWave << std::endl;
		if (EnemiesSpawnedInWave == Info.Ennemies) {
			std::cout << "end wave" << std::endl;
			TimeToWait = static_cast<float>(Info.TimeBetweenWaves);
			WavesSpawned++;
			EnemiesSpawnedInWave = 0;
		}
		if (WavesSpawned == Info.Waves) {
			std::cout << "end round" << std::endl;
			WavesSpawned = 0;
			round++;
			EnemiesSpawnedInWave = 0;

		}
	}
}