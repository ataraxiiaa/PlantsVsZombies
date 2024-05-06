#pragma once

#include "Plants.h" // Include neceassary header file(s)
#include "Animation.h"
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
public:
	Explosive(); // Default constructor to load sprties
	void DrawExplosion(RenderWindow& window, Coordinates position); // Draws the explosions
	void CheckExplosionCollision(Vector<Zombie*>& Zombie);
};

