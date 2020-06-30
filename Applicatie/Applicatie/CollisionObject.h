#pragma once
#include "VisualObject.h"

class CollisionObject : public VisualObject
{
	protected:
	    sf::FloatRect bounds;

    public:
	    CollisionObject(sf::Vector2f aPosition, sf::Texture* aTexture, sf::IntRect spriteBounds, float aSpeed,
			            sf::FloatRect objectBounds);
	    ~CollisionObject();

	    sf::FloatRect* GetBounds();
};

