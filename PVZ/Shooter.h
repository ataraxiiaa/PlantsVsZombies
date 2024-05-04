#pragma once
#ifndef Shooter_H
#define Shooter_H

#include "Plants.h" // Include necassary header file(s)
#include "Pea.h"
#include "Zombies.h"
#include "Vector.h"
#include "NormalZombie.h"

class Shooter : public Plants
{
protected:
	Pea* bullet;
	Clock clock;
	int totalBullets;
	float delay;
public:
	Shooter(int totalBullets=1);
	//void SetBullet();
	void Fire(sf::RenderWindow& window, Coordinates PlantCoords,int index=0);
	void CheckBulletCollision(NormalZombie& Zombie);
	void Action(RenderWindow& window, int& money)
	{
		Fire(window, this->position);
	}
};


#endif // Shooter_H