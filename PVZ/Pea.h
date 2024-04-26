#pragma once
#ifndef Pea_H
#define Pea_H

#include <SFML/Graphics.hpp> // Include necassary header file(s)
#include <SFML/Audio.hpp>
#include "Coordinates.h"
using namespace sf;

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
	void MovePea();

};



#endif // Pea_H