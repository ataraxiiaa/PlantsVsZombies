#pragma once
#ifndef WallNut_H
#define WallNut_H

#include "Plants.h" // include neceassary header file(s)
#include "Animation.h"

class WallNut : public Plants // Inherit plant class
{
	Animation* animate;
public:
	WallNut(); // Default constructor 
	void DrawWallNut(RenderWindow& window); // For drawing window

int getY()
{
	return this->position.GetY();
}
};

#endif // WallNut_H