#pragma once

#include "Level.h" 

class SunflowerFields : public Level
{
	RectangleShape rectangle;
public:
	SunflowerFields();
	void Action(RenderWindow& window);
};

