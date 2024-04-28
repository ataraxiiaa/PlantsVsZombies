#pragma once
#include "Zombies.h"

class DancingZombie :public Zombie {
public:
	DancingZombie()
	{
		srand((unsigned)time(0));
		rand();
		rand();
		rand();
		this->speed = 7.5;
		this->damage = 5;
		this->texture.loadFromFile("../Images/Zombie2.png");
		this->sprite.setTexture(this->texture);
		sprite.setTextureRect(IntRect(0, 0, texture.getSize().x / 8, texture.getSize().y / 1));
		this->exists = true;
		this->position.SetX(700);
		this->position.SetY((600 - (rand() % 5) * 110));
	}
};