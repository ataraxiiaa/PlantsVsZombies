#include "SunFlower.h"
#include <iostream>

SunFlower::SunFlower()
{
	this->exists = true;
	this->time = 10;//placeholder time 
	this->coolDown = 10;
	this->cost = 50;
	this->texture.loadFromFile("../Images/SunFlower.png");
	animate = new Animation;
	this->position.SetX(310);
	this->position.SetY(127.5);
	//	animate->SetSheet(0.125, 6, texture, 8, 1);
	animate->SetSheet(0.125, 5, texture, 6, 1);
	this->lives = 5;
}
void SunFlower::drawPlant(sf::RenderWindow& window)
{
	if (exists)
		Plants::drawPlant(window);
}
void SunFlower::ProduceSun(RenderWindow& window, int& money) 
{
	this->sun.setExists(true);
	Coordinates pos;
	pos.SetX(this->position.GetX() + 25);
	pos.SetY(this->position.GetY() - 25);
	sun.SetPosition(pos);
	
}
void SunFlower::Action(RenderWindow& window, int& money)
{
	if (!sun.getExists())
	{
		//cout << "nigga" << endl;
		if (clock.getElapsedTime().asSeconds() >= this->time)
		{
			cout << "real" << endl;
			Sun sun;
			ProduceSun(window, money);
		}
	}
	else
	{
		sun.DrawSun(window);
		sun.CollectSun(window, money);
		clock.restart();
	}
}