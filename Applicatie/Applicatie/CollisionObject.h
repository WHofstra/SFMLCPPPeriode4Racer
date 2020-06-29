#pragma once
#include "VisualObject.h"

class CollisionObject : VisualObject
{
    public:
	    CollisionObject(sf::Vector2f aPosition, sf::Texture* aTexture, sf::IntRect spriteBounds, float aSpeed,
			            sf::FloatRect objectBounds);
	    ~CollisionObject();

	    sf::FloatRect* GetBounds();

    protected:
	    sf::FloatRect bounds;
};

