#pragma once
#include <SFML/Graphics.hpp>

class VisualObject
{
	public:
		VisualObject(sf::Vector2f aPosition, sf::Texture* aTexture, sf::IntRect spriteBounds, float aSpeed);
		~VisualObject();

		void SetPosition(sf::Vector2f sPosition);
		void SetSpeed(float aSpeed);

		void Update();
		void Draw();

	protected:
		sf::Vector2f position;
		sf::Vector2f velocity;
		float movementSpeed;
};

