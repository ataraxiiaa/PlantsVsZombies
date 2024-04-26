#pragma once
#include "Zombies.h"
#include "Animation.h"

class NormalZombie :public Zombie {
	Animation* animate;
public:
	NormalZombie()
	{
		texture.loadFromFile("../Images/Zombie2.png");
		this->sprite.setTexture(this->texture);
		sprite.setTextureRect(IntRect(0, 0, texture.getSize().x / 8, texture.getSize().y / 1));
		this->position.SetX(800);
		this->position.SetY(500);
		this->exists = true;
	}
	void DrawNormalZombie(sf::RenderWindow& window)
	{
		sprite.setPosition(position.GetX(), position.GetY());
		window.draw(sprite);
	}
	
};