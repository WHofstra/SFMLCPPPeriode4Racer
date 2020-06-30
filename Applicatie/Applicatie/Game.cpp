#include "Game.h"

//Private functions
//Maakt de window aan en zet fps limit. ps en een leuk naampie
void Game::InitWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(1364, 664), "Huts game: Shiet Shiet", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(144);
	window->setVerticalSyncEnabled(false);
}

//Voegt een leuke texture toe aan de bullets
void Game::InitTexture(sf::Texture* aTexture, std::string filePath)
{
	if (!(*aTexture).loadFromFile(filePath)) {
		window->close();
	}
}

//Instantieert de GUI. Zet de font gelijk aan het correcte font en krijgt ook gelijk de goeie kleur en lettergrootte.
void Game::InitGUI(std::string filePath)
{
	//Load font
	//if (!font.loadFromFile("Fonts/PixellettersFull.ttf"))
	//	std::cout << "ERROR::GAME::Failed to load font" << "\n";

	//Er is geen font in de Repository gestopt.
	//Ik gebruik er zelf wel één.
	if (!font.loadFromFile(filePath)) {
		window->close();
	}

	//Point text
	pointText.setFont(font);
	pointText.setCharacterSize(32);
	pointText.setFillColor(sf::Color::White);
	pointText.setString("test");
	std::cout << "huts" << "\n";
}

//Maakt de speler aan
void Game::InitPlayer()
{
	player = new Player(sf::Vector2f(0.f, 0.f), &spriteSheet, sf::IntRect(0, 0, 848, 1200), 5.f,
		                sf::FloatRect(0.f, 0.f, 0.f, 0.f));
}

//Spawntimer goeroe dingen
void Game::InitEnemies()
{
	spawnTimerMax = 100.f;
	spawnTimer = spawnTimerMax;
}

//Constuctor/Destrucor
Game::Game()
{
	InitWindow();
	InitTexture(&spriteSheet, "Textures/car.png");
	InitGUI("Fonts/retganon.ttf");
	InitPlayer();
}

//Alles wordt gethanos snapped.
Game::~Game()
{
	delete window;
	delete player;

	//Delete textures
	for (auto& i : textures)
	{
		delete i.second;
	}
}

//Functions
//Zorgt ervoor dat als de game open staat, alles geUpdate wordt.
void Game::Run()
{
	while (window->isOpen())
	{
		Update();
		Render();
	}
}

//Kijkt of er keys ingedrukt worden om bijvoorbeeld de game te sluiten.
void Game::UpdatePollEvents()
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			window->close();

		//Druk 'Escape' om af te sluiten
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			window->close();
	}
}

//Checked of de speler input geeft, zo ja dan beweegt de speler.
//Hierdoor wordt er vanuit de andere classes ook de sprites geupdate.S
void Game::UpdateInput()
{
	//Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player->move(0.f, 1.f);
}

//Leeg lmao. 
void Game::UpdateGUI()
{

}

//Alle update fucnties worden hier gerund
void Game::Update()
{
	UpdatePollEvents();

	UpdateInput();

	player->Update();

	UpdateGUI();
}

//Drawed de GUI
void Game::RenderGUI()
{
	window->draw(pointText);
}

//Drawed alle leuke vormen en dingen.
void Game::Render()
{
	
	window->clear();

	player->Render(*window);

	RenderGUI();

	window->display();
}
