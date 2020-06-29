#include "VisualObject.h"

VisualObject::VisualObject(sf::Vector2f aPosition, sf::Texture* aTexture, sf::IntRect spriteBounds, float aSpeed)
	: position(aPosition), movementSpeed(aSpeed)
{

}

VisualObject::~VisualObject()
{

}

void VisualObject::SetPosition(sf::Vector2f sPosition)
{

}

void VisualObject::SetSpeed(float aSpeed)
{

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
