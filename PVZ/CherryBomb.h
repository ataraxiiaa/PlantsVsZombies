#pragma once

#ifndef CherryBomb_H
#define CherryBomb_H

#include "Explosive.h" // Include neceassary header file(s)

class CherryBomb : public Explosive // Inherit explosive class
{
	Clock clock;
	float scale;
public:
	CherryBomb();
	virtual void Action(RenderWindow& window); // Declared virtual in Plant class
};



#endif // CherryBomb_H