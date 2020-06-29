#pragma once
#include "VisualObject.h"

class Game
{
	public:
		Game(sf::RenderWindow* aWindow);
		~Game();

		void FindTexture(sf::Texture* aTexture, std::string filePath);
		void CheckQuitInput(sf::Event* anEvent);

		void Update();
		void Draw();

	private:
		sf::RenderWindow* window;
		sf::Texture spriteMap;
		sf::Texture mapTerrainTexture;
};

