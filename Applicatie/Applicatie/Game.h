#pragma once
#include<map>

#include "Player.h"
#include "Background.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;

	//Resources map, omdat je hier makkelijk dingen in en uit kan halen met een eigen key, zonder dat het veel geheugen steelt
	std::map<std::string, sf::Texture*> textures;

	//Background
	Background* background;

	//GUI
	sf::Font font;
	sf::Text pointText;
	sf::Texture mapTexture;
	sf::Texture spriteSheet;

	//Player
	Player* player;

	//Enemies
	float spawnTimer;
	float spawnTimerMax;

	//Private functions
	void InitWindow();
	void InitTexture(sf::Texture* aTexture, std::string filePath);
	void InitBackground();
	void InitGUI(std::string filePath);

	void InitPlayer();
	void InitEnemies();

public:
	Game();
	virtual ~Game();

	//Functions
	void Run();

	//de reden dat er zoveel Update zijn is, omdat er anders een hele grootte onoverzichtelijke spagetti onstaat.
	void UpdatePollEvents();
	void UpdateInput();
	void UpdateGUI();
	void Update();
	void RenderGUI();
	void Render();
};

