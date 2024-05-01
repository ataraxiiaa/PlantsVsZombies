#pragma once
#ifndef Shooter_H
#define Shooter_H

#include "Plants.h" // Include necassary header file(s)
#include "Pea.h"


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
};


#endif // Shooter_H