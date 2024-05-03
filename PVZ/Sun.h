#pragma once
#ifndef Sun_H
#define Sun_H

#include <SFML/Graphics.hpp> // Inlcude necessary header file(s)
#include "Coordinates.h"
using namespace std;
using namespace sf;

class Sun
{
	Sprite sunSprite,sunSprite2;
	Texture sunTexture, sunTexture2;
	Sprite sunSpriteShop;
	Texture sunTextureShop;
	bool exist;
	float fallSpeed;
	Coordinates position;
	Clock clock;
	bool autoCollect;
	int money;
protected:
	
public:
	Sun();
	void DrawSun(sf::RenderWindow& window, int& money);
	void DrawSun(sf::RenderWindow& window);
	void DropSun(); // For Spawning Sun at random positions
	void CollectSun(sf::RenderWindow& window, int& money);
	void SetAutoCollect(bool check) { autoCollect = check; }
	void setExists(bool exists) { this->exist = exists; }
	void SetPosition(Coordinates position) { this->position = position; }
	bool getExists() { return this->exist; }
};


#endif // Sun_H