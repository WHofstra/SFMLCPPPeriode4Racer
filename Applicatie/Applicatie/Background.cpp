#include "Background.h"

Background::Background(sf::Vector2f aPosition, sf::Texture* aTexture, sf::IntRect spriteBounds, float aSpeed)
	: VisualObject(aPosition, aTexture, spriteBounds, aSpeed), spriteHeight(spriteBounds.height), spritePosition(aPosition)
{
	SetSprite(spriteBounds, aTexture, sf::Color(255, 255, 255, 255));
}

Background::~Background()
{

}

int Background::GetTileHeight()
{
	return spriteHeight;
}

void Background::SetSprite(sf::IntRect spriteBounds, sf::Texture* aTexture, sf::Color aColor)
{
	sprite.setTexture(*texture);
	sprite.setTextureRect(spriteBounds);
	sprite.setPosition(position);
	sprite.setColor(aColor);
}

void Background::Update()
{
	if (position.y < 0) {
		position.y += movementSpeed;
	}
	else {
		position.y -= spriteHeight;
	}
}

void Background::Render(sf::RenderWindow* aWindow)
{
	for (int i = 0; i < (aWindow->getSize().y + spriteHeight); i += spriteHeight)
	{
		aWindow->draw(sprite);

		if (i < aWindow->getSize().y) {
			spritePosition.y += spriteHeight;
		}
		else {
			spritePosition.y = position.y;
		}
		sprite.setPosition(spritePosition);
	}
}
