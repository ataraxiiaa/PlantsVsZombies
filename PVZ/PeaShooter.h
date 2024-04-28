#pragma once
#ifndef PeaShooter_H
#define PeaShooter_H

#include "Shooter.h" // Include necassary header file(s)
#include "Animation.h"

class PeaShooter : public Shooter
{
	Animation* animate;
public:
	PeaShooter();
	void DrawPeaShooter(sf::RenderWindow& window);
	int GetX()
	{
		return this->position.GetX();
	}
	int GetY()
	{
		return this->position.GetY();
	}
	bool GetExistence()
	{
		return this->exists;
	}
};




#endif // PeaShooter_H