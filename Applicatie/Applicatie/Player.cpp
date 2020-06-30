#include "Player.h"

//Zet de variable
void Player::InitVariables()
{
	attackCooldownMax = 10.f;
	attackCooldown = attackCooldownMax;
}

//Checked of de texture correct is
void Player::InitTexture()
{
	//Laad de texture vanaf file
	if (!(*texture).loadFromFile("Textures/car.png"))
	{
		std::cout << "ERROR::PLAYER::InitTEXTURE::Could not load texture file." << "\n";
	}
	else {
		texture->setSmooth(true);
	}

	//Eén gehele texture wordt al in de 'Game'-class geladen.
	//Andere classes kunnen dan van deze texture hun sprites halen.
}

//Zet de sprite gelijk aan de inhoud van de texture, en bepaald de scale
void Player::InitSprite()
{
	//Zet de sprite gelijk aan de inhoud van de texture
	sprite.setTexture(*texture);

	//Resized de sprite
	sprite.scale(0.1f, 0.1f);
}

//Roept de functies aan, zodra de speler wordt aangemaakt
Player::Player(sf::Vector2f aPosition, sf::Texture* aTexture, sf::IntRect spriteBounds, float aSpeed, sf::FloatRect objectBounds)
	: CollisionObject(aPosition, aTexture, spriteBounds, aSpeed, objectBounds)
{
	InitVariables();
	//InitTexture();
	InitSprite();
}

Player::~Player()
{

}

//Geeft de positie van de speler terug
const sf::Vector2f& Player::GetPos() const
{
	return sprite.getPosition();
}

//Geeft de bouds/collider van de speler terug
const sf::FloatRect Player::GetBounds() const
{
	return sprite.getGlobalBounds();
}

//Beweegt de sprite als er imput is
void Player::move(const float dirX, const float dirY)
{
	sprite.move(movementSpeed * dirX, movementSpeed * dirY);
}


//Update de cooldown
void Player::Update()
{

}

//Tekent de sprite van de speler op de correcte positie
void Player::Render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
