#pragma once
#ifndef RangedShooter_H
#define RangedShooter_H

#include "Shooter.h" // Include necassary header file(s)

class RangedShooter : public Shooter // This class would handla ny range based shooters
{
protected:
	bool shoot;
public:
	RangedShooter();
	void Action(sf::RenderWindow window);
};




#endif // RangedShooter_H
