#pragma once
#ifndef Sun_H
#define Sun_H

#include <SFML/Graphics.hpp> // Inlcude necessary header file(s)
#include "Coordinates.h"
using namespace std;
using namespace sf;

class Sun
{
	Sprite sunSprite;
	Texture sunTexture;
	bool exist;
	float fallSpeed;
	Coordinates position;
	Clock clock;
protected:
	
public:
	Sun();
	void DrawSun(sf::RenderWindow& window);
	void DropSun(); // For Spawning Sun at random positions
	void CollectSun(sf::RenderWindow& window);
};


#endif // Sun_H