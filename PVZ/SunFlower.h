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
	int* moneyPtr;
public:
	SunFlower(int &money);
	virtual void drawPlant(sf::RenderWindow& window);
	virtual void Action(RenderWindow& window);
	void SetMoney(int& money) { this->moneyPtr = &money; }
	void ProduceSun(RenderWindow& window);
};





#endif // SunFlower_H