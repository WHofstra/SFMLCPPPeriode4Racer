#pragma once
#include <SFML/Graphics.hpp>

class VisualObject
{
	protected:
		//Texture wordt in sprite gestopt
		sf::Texture* texture;

		sf::Sprite sprite;
		sf::Vector2f position;
		sf::Vector2f velocity;
		float movementSpeed;

		void Update();
		void Draw();

	public:
		VisualObject(sf::Vector2f aPosition, sf::Texture* aTexture, sf::IntRect spriteBounds, float aSpeed);
		~VisualObject();

		void SetPosition(sf::Vector2f sPosition);
		void SetSprite(sf::IntRect spriteBounds);
		void SetSpeed(float aSpeed);
};

