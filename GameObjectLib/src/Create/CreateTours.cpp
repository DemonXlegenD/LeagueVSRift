#include "Create/CreateTours.h"
#include "AssetManager.h"

std::vector<GameObject*> CreateTours::tower;

void CreateTours::CreateTower(int _index, float _positionX, float _positionY)
{
	switch (_index) {
	case 0:
		CreateVarus(_positionX, _positionY);
		break;
	case 1:
		CreateLulu(_positionX, _positionY);
		break;
	case 2:
		CreateMalphite(_positionX, _positionY);
		break;
	case 3:
		CreateXinZhao(_positionX, _positionY);
		break;
	case 4:
		CreateBat2(_positionX, _positionY);
		break;
	case 5:
		CreateBat3(_positionX, _positionY);
		break;
	default:
		break;
	}
}

bool CreateTours::CanPlaceTower(std::string name) {
	std::cout << SceneManager::GetActiveGameScene()->GetGameObject(name)->GetComponent<Ressource>()->GetGold();
	std::cout << SceneManager::GetActiveGameScene()->GetGameObject("Ressources")->GetComponent<Ressource>()->GetGold();
	if (SceneManager::GetActiveGameScene()->GetGameObject(name)->GetComponent<Ressource>()->GetGold() <= SceneManager::GetActiveGameScene()->GetGameObject("Ressources")->GetComponent<Ressource>()->GetGold() &&
		SceneManager::GetActiveGameScene()->GetGameObject(name)->GetComponent<Ressource>()->GetGold() <= SceneManager::GetActiveGameScene()->GetGameObject("Ressources")->GetComponent<Ressource>()->GetMana())
	{
		return true;
	}
	return false;
}

void CreateTours::CreateVarus(float _positionX, float _positionY)
{
	if (CreateTours::CanPlaceTower("Varus"))
	{
		std::cout << " JIN PLACE ZOIJZPOY";
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Varus", _positionX, _positionY, *AssetManager::GetAsset("Varus"), 1.0f, 1.0f, 400.f, 30.f));
	}
}
void CreateTours::CreateLulu(float _positionX, float _positionY)
{
	if (CreateTours::CanPlaceTower("Lulu"))
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Lulu", _positionX, _positionY, *AssetManager::GetAsset("Lulu"), 1.0f, 1.0f, 400.f, 30.f));
	}
}
void CreateTours::CreateMalphite(float _positionX, float _positionY)
{
	if (CreateTours::CanPlaceTower("Malphite"))
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Malphite", _positionX, _positionY, *AssetManager::GetAsset("Malphite"), 1.0f, 1.0f, 400.f, 30.f));
	}
}
void CreateTours::CreateXinZhao(float _positionX, float _positionY)
{
	if (CreateTours::CanPlaceTower("XinZhao"))
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("XinZhao", _positionX, _positionY, *AssetManager::GetAsset("XinZhao"), 1.0f, 1.0f, 400.f, 30.f));
	}
}

void CreateTours::CreateBat2(float _positionX, float _positionY)
{
	if (CreateTours::CanPlaceTower("Bat2"))
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Bat2", _positionX, _positionY, *AssetManager::GetAsset("Varus"), 1.0f, 1.0f, 400.f, 0.f));
	}
}

void CreateTours::CreateBat3(float _positionX, float _positionY)
{
	if (CreateTours::CanPlaceTower("Bat3"))
	{
		tower.push_back(SceneManager::GetActiveGameScene()->CreateBatimantGameObject("Bat3", _positionX, _positionY, *AssetManager::GetAsset("Varus"), 1.0f, 1.0f, 400.f, 5.f));
	}
}