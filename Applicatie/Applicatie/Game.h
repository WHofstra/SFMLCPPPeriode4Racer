#pragma once

#include<map>
#include"Player.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;

	//Resources map, omdat je hier makkelijk dingen in en uit kan halen met een eigen key, zonder dat het veel geheugen steelt
	std::map<std::string, sf::Texture*> textures;

	//GUI
	sf::Font font;
	sf::Text pointText;

	//Player
	Player* player;

	//Enemies
	float spawnTimer;
	float spawnTimerMax;

	//Private functions
	void initWindow();
	void initTextures();
	void initGUI();

	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();

	//Functions
	void run();

	//de reden dat er zoveel update zijn is, omdat er anders een hele grootte onoverzichtelijke spagetti onstaat.
	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void update();
	void renderGUI();
	void render();
};

