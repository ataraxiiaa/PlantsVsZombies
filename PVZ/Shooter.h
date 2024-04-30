#pragma once
#ifndef Shooter_H
#define Shooter_H

#include "Plants.h" // Include necassary header file(s)
#include "Pea.h"


class Shooter : public Plants
{
protected:
	Pea bullet;
	Clock clock;
public:
	Shooter();
	//void SetBullet();
	void Fire(sf::RenderWindow& window, Coordinates PlantCoords);
};


#endif // Shooter_H