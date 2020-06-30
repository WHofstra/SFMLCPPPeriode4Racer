#pragma once
#include<SFML/System.hpp>
#include<iostream>

#include "CollisionObject.h"

class Player : public CollisionObject
{
private:
	float attackCooldown;
	float attackCooldownMax;

	//Private functions
	void InitVariables();
	void InitTexture();
	void InitSprite();

public:
	Player(sf::Vector2f aPosition, sf::Texture* aTexture, sf::IntRect spriteBounds, float aSpeed,
		   sf::FloatRect objectBounds);
	virtual ~Player();

	//position via pointer en collider via bounds
	const sf::Vector2f& GetPos() const;
	const sf::FloatRect GetBounds() const;

	//Functions
	void move(const float dirX, const float dirY);
	void Update();
	void Render(sf::RenderTarget& target);
};

