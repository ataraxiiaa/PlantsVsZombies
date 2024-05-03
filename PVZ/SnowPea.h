#pragma once

#include "Shooter.h" // Include neceassary header file(s)
#include "Animation.h"

class SnowPea : public Shooter
{
	Animation* animate;
	bool Ice;
public:
	SnowPea(); // Default constructor 
	void DrawSnowPea(RenderWindow& window);
	virtual void Action(RenderWindow& window, int& money);// Declared abstract virtual in header file Plant
};

