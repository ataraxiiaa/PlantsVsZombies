#pragma once
#ifndef SunFlower_H
#define SunFlower_H

#include "Plants.h" // Include neccasary header file(s)

class SunFlower : public Plants
{

public:
	SunFlower()
	{
		this->exists = true;
		this->coolDown = 10;
		this->cost = 50;
		this->texture.loadFromFile("../Images/SunFlower.png");
		this->sprite.setTexture(texture);
		this->sprite.setTextureRect(sf::IntRect(0, 0, 67, 100));
		this->position.SetX(300);
		this->position.SetY(200);
	}
};





#endif // SunFlower_H