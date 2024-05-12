#pragma once
#ifndef WallNut_H
#define WallNut_H

#include "MovePlant.h" // include neceassary header file(s)
#include "Animation.h"

class WallNut : public MovePlant // Inherit plant class
{

public:
	WallNut(); // Default constructor 
	
	virtual void Action(RenderWindow& window); // Declared virtual in Plant calss
	
};

#endif // WallNut_H