#pragma once

#ifndef Explosive_H
#define Explosive_H

#include "Plants.h" // Include neceassary header file(s)
#include "Vector.h"
#include "Zombies.h"

class Explosive : public Plants // Inherit Plant Class
{
protected:
	// Adding Graphics
	Sprite ExplosionSprite;
	Texture ExplosionTexture;
	bool explode;
	Clock explosionClock;
	Coordinates ExplosionPosition;

public:
	Explosive(); // Default constructor to load sprties
	void DrawExplosion(RenderWindow& window, Coordinates position); // Draws the explosions
	void CheckExplosionCollision(Vector<Zombie*>& Zombie, int& killed); //checks if any zombies are killed by explosion
};


#endif // Explosive_H 