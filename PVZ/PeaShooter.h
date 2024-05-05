#pragma once
#ifndef PeaShooter_H
#define PeaShooter_H

#include "Shooter.h" // Include necassary header file(s)
#include "Animation.h"

class PeaShooter : public Shooter
{
public:
	PeaShooter(); // Default constructor 
	int GetX() { return this->position.GetX(); } // Getting X coordinates
	int GetY() { return this->position.GetY(); } // Getting Y coordinates
	bool GetExistence() { return this->exists; }; // Checks if plants exist or not
	virtual void Action(RenderWindow& window); // Defined vritual in header file Plant
	virtual float getDamage() { return this->damage; }
	Pea* getPea() { return this->bullet; }
};




#endif // PeaShooter_H