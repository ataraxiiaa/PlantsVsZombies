#include "SunFlower.h"
#include <iostream>

SunFlower::SunFlower(int &money)
{
	this->exists = true;
	this->time = 10;//placeholder time 
	this->coolDown = 10;
	this->cost = 100;
	this->texture.loadFromFile("../Images/SunFlower.png");
	animate = new Animation;
	this->position.SetX(310);
	this->position.SetY(127.5);
	//	animate->SetSheet(0.125, 6, texture, 8, 1);
	animate->SetSheet(0.125, 5, texture, 6, 1);
	this->lives = 50;
	this->moneyPtr = &money;
	Type = "Sunflower";
}
void SunFlower::drawPlant(sf::RenderWindow& window)
{
	if (exists)
		Plants::drawPlant(window);
}
void SunFlower::ProduceSun(RenderWindow& window) 
{
	this->sun.setExists(true);
	Coordinates pos;
	pos.SetX(this->position.GetX() + 25);
	pos.SetY(this->position.GetY() - 25);
	sun.SetPosition(pos);
	
}
void SunFlower::Action(RenderWindow& window)
{
	if (!sun.getExists() && this->exists)
	{
		//cout << "nigga" << endl;
		if (clock.getElapsedTime().asSeconds() >= this->time)
		{
			ProduceSun(window);
		}
	}
	else if (sun.getExists() && this->exists)
	{
		sun.DrawSun(window);
		sun.CollectSun(window, *this->moneyPtr);
		clock.restart();
	}
}