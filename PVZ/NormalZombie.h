#pragma once
#include "Zombies.h"
#include "Animation.h"

class NormalZombie :public Zombie {
	Animation* animate;
public:
	NormalZombie()
	{
		animate = nullptr;
		srand((unsigned)time(0));
		this->speed = 5;
		this->damage = 5;
		this->texture.loadFromFile("../Images/Zombie2.png");
		this->sprite.setTexture(this->texture);
		sprite.setTextureRect(IntRect(0, 0, texture.getSize().x / 8, texture.getSize().y / 1));
		this->exists = true;
		this->position.SetX(1010);
		this->position.SetY((550 - (rand() % 5) * 110));
		this->position.SetY(200);
		
	}
};