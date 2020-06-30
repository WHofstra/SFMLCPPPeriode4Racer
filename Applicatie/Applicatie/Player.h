#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

class Player
{
private:
	//texture wordt in sprite gestopt
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

	float attackCooldown;
	float attackCooldownMax;

	//Private functions
	void initVariables();
	void initTexture();
	void initSprite();

public:
	Player();
	virtual ~Player();

	//position via pointer en collider via bounds
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;

	//Functions
	void move(const float dirX, const float dirY);
	void update();
	void render(sf::RenderTarget& target);
};

