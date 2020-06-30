#include "Game.h"

//Private functions
//maakt de window aan en zet fps limit. ps en een leuk naampie
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1364, 664), "Huts game: Shiet Shiet", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}




//voegt een leuke texture toe aan de bullets
void Game::initTextures()
{

}

//instantieert de GUI. Zet de font gelijkt aan het correcte font en krijgt ook gelijk de goeie kleur en lettergrootte.
void Game::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";

	//point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(12);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("test");
	std::cout << "huts" << "\n";
}

//maakt de speler aan
void Game::initPlayer()
{
	this->player = new Player();
}

//spawntimer goeroe dingen
void Game::initEnemies()
{
	this->spawnTimerMax = 100.f;
	this->spawnTimer = this->spawnTimerMax;
}

//Constuctor/Destrucor
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initPlayer();
}

//alles wordt gethanos snapped.
Game::~Game()
{
	delete this->window;
	delete this->player;

	//Delete textures
	for (auto& i : this->textures)
	{
		delete i.second;
	}
}

//Functions
//zorgt ervoor dat als de game open staat, alles geupdate wordt.
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

//kijkt of er keys ingedrukt worden om bijvoorbeeld de game te sluiten.
void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

//checked of de speler input geeft, zo ja dan beweegt de speler. Hierdoor wordt er vanuit de andere classes ook de sprites geupdate.
void Game::updateInput()
{
	//Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
}

//leeg lmao. 
void Game::updateGUI()
{

}


//alle update fucnties worden hier gerund
void Game::update()
{
	this->updatePollEvents();

	this->updateInput();

	this->player->update();

	this->updateGUI();
}

//drawed de GUI
void Game::renderGUI()
{
	this->window->draw(this->pointText);
}

//drawed alle leuke vormen en dingen.
void Game::render()
{
	this->window->clear();

	this->player->render(*this->window);

	this->renderGUI();

	this->window->display();
}
