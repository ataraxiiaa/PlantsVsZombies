#pragma once

#ifndef Repeater_H
#define Repeater_H
#include "Shooter.h" // Include necessary header file(s)
#include "Animation.h"

class Repeater : public Shooter
{
	Animation* animate;
	Clock clock;
public:
	Repeater();
	void DrawRepeater(RenderWindow& window);
	void action(RenderWindow& window);
};



#endif // Repeater_H