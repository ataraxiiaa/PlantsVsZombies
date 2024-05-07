#pragma once

#ifndef FumeShroom_H
#define FumeShroom_H

#include "RangedShooter.h" // include necassary header file(s)

class FumeShroom : public RangedShooter
{
protected:

public:
	FumeShroom();
	virtual void Action(sf::RenderWindow& window);
};



#endif // FumeShroom_h