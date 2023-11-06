#include "Scenes/SceneCreditsMenu.h"
#include "SceneManager.h"
#include "Components/Button.h"
#include "AssetManager.h"
#include "Scenes/SceneMainMenu.h"
#include "Components/SpriteRenderer.h"

SceneCreditsMenu::SceneCreditsMenu(sf::RenderWindow* _window) : Scene(_window) {
	this->Awake();
	Scene::Create();
}

void SceneCreditsMenu::Create() {
	Scene::Create();
	sf::Texture backgroundTexture2;

	if (!backgroundTexture2.loadFromFile("../assets/Sprite_LOL/background/fontaineLOL.jpg"))
	{
		std::cout << "pas d'image" << std::endl;
	}
	GameObject* background2 = CreateBackgroundGameObject("Background2", SceneManager::GetWindowWidth() / 2, SceneManager::GetWindowHeight() / 2, backgroundTexture2);
	this->CreateSceneButtonsMenu();
	//this->CreateCredits();
}

void SceneCreditsMenu::CreateCredits() {
	credits = this->CreateCreditsGameObject("Credits", SceneManager::GetWindowWidth() / 1.8, SceneManager::GetWindowHeight() / 1.65, *AssetManager::GetAsset("championsJin"), 0.5f, 0.5f);
}

void SceneCreditsMenu::Render(sf::RenderWindow* _window) {
	Scene::Render(_window);
}

void SceneCreditsMenu::CreateSceneButtonsMenu() {
	float widthScreen = SceneManager::GetWindow()->getSize().x;
	float heightScreen = SceneManager::GetWindow()->getSize().y;
	creditsButton = CreateButtonGameObject("Crédits", widthScreen / 2, heightScreen / 13, 50);
	backButton = CreateButtonGameObject("Retour", widthScreen / 15, heightScreen / 13, 20);
	//listCredits = CreateButtonGameObject("Game Master : LAHALLE Francois\nDéveloppeur : LAHALLE Francois, LEFORESTIER Quentin, ROY Hugo, NOM Maurad, DIFALLAH Kaïs, BRU Arthur\nSound Production : BRU Arthur\nAssets Production : BRU Arthur\nDiagramme Production : DIFALLAH Kaïs, LEFORESTIER Quentin", widthScreen / 2, heightScreen / 2, 20);
	
	sf::Texture textureFrancois;

	if (!textureFrancois.loadFromFile("../assets/Sprite_LOL/Champions/malphite.png"))
	{
		std::cout << "pas d'image" << std::endl;
	}

	GameObject* imagesFrancois = CreateDecorObject("TextureFrancois1", widthScreen / 1.7, heightScreen / 1.65, 1.0, 1.0, textureFrancois);
	listCredits = CreateButtonGameObject("Game Master : LAHALLE Francois ", widthScreen / 1.7, heightScreen / 1.6, 20);
}

void SceneCreditsMenu::SetOrigin() {
	float widthScreen = SceneManager::GetWindow()->getSize().x;
	float heightScreen = SceneManager::GetWindow()->getSize().y;

	text.setOrigin(sf::Vector2f(widthScreen / 2, heightScreen / 2));
}

void SceneCreditsMenu::Update(sf::Time _delta) {
	Scene::Update(_delta);
	if (backButton->GetComponent<Button>()->IsClicked()) {
		SceneManager::RunScene("SceneMainMenu");
	}
}

GameObject* SceneCreditsMenu::CreateCreditsGameObject(const std::string& name, float _x, float _y, const sf::Texture texture, float scalex, float scaley)
{
	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(_x, _y));


	Player* player = gameObject->CreateComponent<Player>();

	Sprite* sprite = gameObject->CreateComponent<Sprite>();
	sprite->SetTexture(texture);
	sprite->SetScale(scalex, scaley);
	sprite->SetSprite();

	return gameObject;
}
