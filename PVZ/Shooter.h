#pragma once
#ifndef Shooter_H
#define Shooter_H

#include "Plants.h" // Include necassary header file(s)
#include "Pea.h"


class Shooter : public Plants
{
protected:
	Pea bullet;
public:
	Shooter(Coordinates position);
	void SetBullet();
	void Fire();
};


#endif // Shooter_H