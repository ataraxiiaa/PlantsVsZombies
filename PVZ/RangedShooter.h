#pragma once
#ifndef RangedShooter_H
#define RangedShooter_H

#include "Shooter.h" // Include necassary header file(s)
#include "Zombies.h"

class RangedShooter : public Shooter // This class would handla ny range based shooters
{
protected:
	bool shoot;
	int totalBullets;
public:
	RangedShooter(int totalBullets=1);
	bool CheckRange(Vector<Zombie*>& Zptr);
	bool CheckBulletRange();
	//void Action(sf::RenderWindow& window);
};




#endif // RangedShooter_H
