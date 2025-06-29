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
	float damage;
	float delay;
public:
	Shooter(int totalBullets=1);
	//void SetBullet();
	void Fire(sf::RenderWindow& window, Coordinates PlantCoords,int index=0); //fires bullet
	void CheckBulletCollision(Vector<Zombie*>& Zombie, int& killed); //checks if bullet hits any zombie
	void Action(RenderWindow& window)
	{
		Fire(window, this->position);
	}
	virtual float getDamage() { return damage; }
};


#endif // Shooter_H