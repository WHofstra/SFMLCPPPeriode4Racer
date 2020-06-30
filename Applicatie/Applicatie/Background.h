#pragma once
#include <iostream>
#include "VisualObject.h"

class Background : public VisualObject
{
	protected:
		int spriteHeight;
		sf::Vector2f spritePosition;

	public:
		Background(sf::Vector2f aPosition, sf::Texture* aTexture, sf::IntRect spriteBounds, float aSpeed);
		~Background();

		void SetSprite(sf::IntRect spriteBounds, sf::Texture* aTexture, sf::Color aColor);
		int GetTileHeight();

		void Update();
		void Render(sf::RenderWindow* aWindow);
};

