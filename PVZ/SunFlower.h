#pragma once
#ifndef SunFlower_H
#define SunFlower_H

#include "Plants.h" // Include neccasary header file(s)

class SunFlower : public Plants
{

public:
	SunFlower()
	{
		this->exists = true;
		this->coolDown = 10;
		this->cost = 50;
		this->position.SetX(300);
		this->position.SetY(200);
	}
};





#endif // SunFlower_H