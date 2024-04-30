#pragma once
#ifndef PeaShooter_H
#define PeaShooter_H

#include "Shooter.h" // Include necassary header file(s)
#include "Animation.h"

class PeaShooter : public Shooter
{
	Animation* animate;
public:
	PeaShooter(); // Default constructor 
	void DrawPeaShooter(sf::RenderWindow& window); // draws peashooter
	int GetX() { return this->position.GetX(); } // Getting X coordinates
	int GetY() { return this->position.GetY(); } // Getting Y coordinates
	bool GetExistence() { return this->exists; }; // Checks if plants exist or not

};




#endif // PeaShooter_H