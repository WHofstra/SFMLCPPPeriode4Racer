#include "CollisionObject.h"

CollisionObject::CollisionObject(sf::Vector2f aPosition, sf::Texture* aTexture, sf::IntRect spriteBounds, float aSpeed, sf::FloatRect objectBounds)
    : VisualObject(aPosition, aTexture, spriteBounds, aSpeed), bounds(objectBounds)
{

}

CollisionObject::~CollisionObject()
{

}

sf::FloatRect* CollisionObject::GetBounds()
{
    return &bounds;
}
