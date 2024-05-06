#pragma once

#include "Plants.h" // Include neceassary header file(s)
#include "Animation.h"
class Explosive : public Plants // Inherit Plant Class
{
protected:
	// Adding Graphics
	Sprite ExplosionSprite;
	Texture ExplosionTexture;
	bool explode;
	Coordinates position;
public:
	Explosive(); // Default constructor to load sprties
	void DrawExplosion(RenderWindow& window, Coordinates position); // Draws the explosions
};

