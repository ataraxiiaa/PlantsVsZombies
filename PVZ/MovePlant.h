#pragma once
#include "Plants.h" // Include necassary header file(s)
#include "Zombies.h"

class MovePlant : public Plants
{
protected:
	float movingSpeed;
	float damage;
public:
	MovePlant();
	void MovingPlant(); // Moving any plant in general
	void CheckCollision(Vector<Zombie*>& Zombie, int& killed);
};

