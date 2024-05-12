#pragma once
#include "Plants.h" // Include necassary header file(s)

class MovePlant : public Plants
{
protected:
	float movingSpeed;
	float damage;
public:
	MovePlant();
	void MovingPlant(); // Moving any plant in general
};

