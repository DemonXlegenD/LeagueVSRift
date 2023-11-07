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
	float widthScreen = static_cast<float>(SceneManager::GetWindow()->getSize().x);
	float heightScreen = static_cast<float>(SceneManager::GetWindow()->getSize().y);
	creditsButton = CreateButtonGameObject("Crédits", widthScreen / 2, heightScreen / 13, 50);
	backButton = CreateButtonGameObject("Retour", widthScreen / 15, heightScreen / 13, 20);
	//listCredits = CreateButtonGameObject("Game Master : LAHALLE Francois\nDéveloppeur : LAHALLE Francois, LEFORESTIER Quentin, ROY Hugo, NOM Maurad, DIFALLAH Kaïs, BRU Arthur\nSound Production : BRU Arthur\nAssets Production : BRU Arthur\nDiagramme Production : DIFALLAH Kaïs, LEFORESTIER Quentin", widthScreen / 2, heightScreen / 2, 20);

	sf::Texture textureFrancois;

	if (!textureFrancois.loadFromFile("../assets/Sprite_LOL/Champions/malphite.png"))
	{
		std::cout << "pas d'image" << std::endl;
	}

	imagesFrancois = CreateDecorObject("TextureFrancois1", widthScreen / 1.7, heightScreen / -4, 1.0, 1.0, textureFrancois);

	creditsFrancois = CreateButtonGameObject("Game Master : LAHALLE François\nDéveloppeur : LAHALLE François\n", widthScreen / 1.7, heightScreen / -4.9, 20);
}

void SceneCreditsMenu::SetOrigin() {
	float widthScreen = SceneManager::GetWindow()->getSize().x;
	float heightScreen = SceneManager::GetWindow()->getSize().y;

	text.setOrigin(sf::Vector2f(widthScreen / 2, heightScreen / 2));
}

void SceneCreditsMenu::AnimFrancois(float _deltaSeconds, float _iteration, int _totalLoop)
{
	float startPosFrancoisX = imagesFrancois->GetPosition().x;
	float startPosFrancoisY = imagesFrancois->GetPosition().y;
	std::cout << _deltaSeconds << "\n";
	if (_deltaSeconds < _totalLoop)
	{
		if (startPosFrancoisY != 500.f)
		{
			this->imagesFrancois->SetPosition(this->imagesFrancois->GetPosition() + Maths::Vector2f::Up);
			this->creditsFrancois->SetPosition(this->creditsFrancois->GetPosition() + Maths::Vector2f::Up);
		}

		//if (elapsedTime > sf::seconds(15.0f))
		//{
		//	std::cout << "15sec";
		//	if (elapsedTime >= updateTime)
		//	{
		//		this->imagesFrancois->SetPosition(this->imagesFrancois->GetPosition() + Maths::Vector2f::Up * Maths::Vector2f(0, 25) * _delta.asSeconds() * speed);
		//		this->creditsFrancois->SetPosition(this->creditsFrancois->GetPosition() + Maths::Vector2f::Up * Maths::Vector2f(0, 25) * _delta.asSeconds() * speed);

		//		elapsedTime = sf::Time::Zero;
		//	}
		//}

	}
	else if (_deltaSeconds > _totalLoop)
	{
		if (startPosFrancoisX > -250.f)
		{
			this->imagesFrancois->SetPosition(this->imagesFrancois->GetPosition() + Maths::Vector2f::Left);
			this->creditsFrancois->SetPosition(this->creditsFrancois->GetPosition() + Maths::Vector2f::Left);
		}
		else
		{
			goodPosCredits = true;
		}
	}
}

void SceneCreditsMenu::Update(sf::Time _delta) {
	Scene::Update(_delta);

	deltaSeconds += _delta.asSeconds();

	if (goodPosCredits)
	{
		deltaSeconds = 0;
		goodPosCredits = false;
	}

	this->AnimFrancois(deltaSeconds, iteration, totalLoop);

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
