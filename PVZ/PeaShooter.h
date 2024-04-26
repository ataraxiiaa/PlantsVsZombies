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
};




#endif // PeaShooter_H