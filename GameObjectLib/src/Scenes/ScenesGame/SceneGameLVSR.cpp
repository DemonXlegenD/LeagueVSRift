#include "Scenes/ScenesGame/SceneGameLVSR.h"
#include "SceneManager.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "CameraManager.h"
#include "Round/CreateRound.h"

SceneGameLVSR::SceneGameLVSR(sf::RenderWindow* _window) : SceneGameAbstract(_window) {
	scale = 1.0f;
	CameraManager::SetCenter(WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2);
}

SceneGameLVSR::~SceneGameLVSR(){}

void SceneGameLVSR::Awake() 
{
	SceneGameAbstract::Awake();
}


void SceneGameLVSR::Create() 
{
	SceneGameAbstract::Create();
	GameObject* background = CreateBackgroundGameObject("Background", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2, *AssetManager::GetAsset("mapLol"));
}

void SceneGameLVSR::Delete() 
{
	SceneGameAbstract::Delete();
}

void SceneGameLVSR::Update(sf::Time _delta) 
{
	if (round == 0) {
		round++;
		CreateRound round1;
		round1.CreateRound1();
		std::cout << "round started";
	}

	for (int i = 0; i < enemies.size(); i++) {
		GameObject* enemy = enemies[i];
		Entity* enemyComponent = enemy->GetComponent<Entity>();
		Maths::Vector2i goal;

		if (enemyComponent->GetCurrPathPoint() >= lanes[enemyComponent->GetLane()].size()) {
			goal = Maths::Vector2i(480, 840);
		}
		else {
			goal = lanes[enemyComponent->GetLane()][enemyComponent->GetCurrPathPoint()];
		}

		float distance = (enemy->GetPosition() - Maths::Vector2f(goal.x, goal.y)).Magnitude();
		enemyComponent->MoveToPoint(goal, enemyComponent->GetSpeed() / 10);

		if (distance < 10) {
			enemyComponent->SetCurrPathPoint(enemyComponent->GetCurrPathPoint() + 1);
		}
	}

	SceneGameAbstract::Update(_delta);
}
void SceneGameLVSR::Render(sf::RenderWindow* _window) 
{
	SceneGameAbstract::Render(_window);
}