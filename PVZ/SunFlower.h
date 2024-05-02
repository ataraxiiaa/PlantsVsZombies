#pragma once
#ifndef SunFlower_H
#define SunFlower_H

#include "Plants.h" // Include neccasary header file(s)
#include "Animation.h"

class SunFlower : public Plants
{
public:
	SunFlower();
	virtual void drawPlant(sf::RenderWindow& window);
	virtual void Action(RenderWindow& window);
};





#endif // SunFlower_H