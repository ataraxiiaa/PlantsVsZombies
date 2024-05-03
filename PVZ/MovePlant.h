#pragma once
#include "Plants.h" // Include necassary header file(s)

class MovePlant : public Plants
{
	float movingSpeed;
public:
	MovePlant();
	void MovingPlant(); // Moving any plant in general
};

