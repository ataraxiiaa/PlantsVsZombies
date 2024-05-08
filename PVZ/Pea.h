#pragma once
#ifndef Pea_H
#define Pea_H

#include <SFML/Graphics.hpp> // Include necassary header file(s)
#include <SFML/Audio.hpp>
#include <string>
#include "Coordinates.h"
#include "Zombies.h"
using namespace sf;
using namespace std;

class Pea
{
protected:
	bool fire;
	float speed;
	Sprite bulletSprite;
	Texture bulletTexture;
	Coordinates position;
public:
	Pea();
	Coordinates GetPosition()const { return position; }
	void SetPosition(Coordinates pos) { this->position = pos; }

	void SetSprite(Sprite sprite) { this->bulletSprite = sprite; }
	bool ShowFire()const { return fire; }
	float GetSpeed()const { return speed; }

	void SetFire(bool firing) { fire = firing; }
	void setSpeed(float speed) { this->speed = speed; }
	
	void SetTexture(Texture texture) {this->bulletTexture = texture; }
	void DrawPea(sf::RenderWindow& window);

	bool CheckForCollision(Zombie*& ptr);

	Texture GetTexture() { return bulletTexture; }
	Sprite GetSprite() { return bulletSprite; }

	void SetSprite(Texture& texture) { this->bulletSprite.setTexture(texture); }
};



#endif // Pea_H