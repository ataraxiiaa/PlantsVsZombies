#pragma once
#ifndef SunFlower_H
#define SunFlower_H

#include "Plants.h" // Include neccasary header file(s)
#include "Animation.h"
#include "Sun.h"

class SunFlower : public Plants
{
	Sun sun;
	int time; //time between sun spawning
	Clock clock;
public:
	SunFlower();
	virtual void drawPlant(sf::RenderWindow& window);
	virtual void Action(RenderWindow& window, int& money);
	void ProduceSun(RenderWindow& window, int& money);
};





#endif // SunFlower_H