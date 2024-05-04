#pragma once

#include "Explosive.h" // Include neceassary header file(s)
#include "Animation.h"

class CherryBomb : public Explosive // Inherit explosive class
{
	Animation* animate;
	Clock clock;
public:
	CherryBomb();
	virtual void Action(RenderWindow& window); // Declared virtual in Plant class
};


