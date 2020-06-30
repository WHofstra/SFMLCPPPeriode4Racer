#include "VisualObject.h"

VisualObject::VisualObject(sf::Vector2f aPosition, sf::Texture* aTexture, sf::IntRect spriteBounds, float aSpeed)
	: position(aPosition), texture(aTexture), movementSpeed(aSpeed)
{
	
}

VisualObject::~VisualObject()
{

}

void VisualObject::SetPosition(sf::Vector2f sPosition)
{
	position = sPosition;
}

void VisualObject::SetSprite(sf::IntRect spriteBounds)
{
}

void VisualObject::SetSpeed(float aSpeed)
{
	movementSpeed = aSpeed;
}

void VisualObject::Update()
{
	//Update Object Properties
}

void VisualObject::Draw()
{
	//Draw Objects Here
	//window->draw();
}
