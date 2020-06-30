#include "Player.h"

//zet de variable
void Player::initVariables()
{
	this->movementSpeed = 5.f;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;
}

//checked of de texture correct is
void Player::initTexture()
{
	//laad de texture vanaf file
	if (!this->texture.loadFromFile("Textures/car.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

//zet de sprite gelijk aan de inhoud van de texture, en bepaald de scale
void Player::initSprite()
{
	//zet de sprite gelijk aan de inhoud van de texture
	this->sprite.setTexture(this->texture);

	//Resized de sprite
	this->sprite.scale(0.1f, 0.1f);
}

//roept de functies aan, zodra de speler wordt aangemaakt
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

//geeft de positie van de speler terug
const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

//geeft de bouds/collider van de speler terug
const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

//beweegt de sprite als er imput is
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}


//update de cooldown
void Player::update()
{

}

//tekent de sprite van de speler op de correcte positie
void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
