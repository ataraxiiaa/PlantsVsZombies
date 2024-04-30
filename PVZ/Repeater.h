#pragma once

#ifndef Repeater_H
#define Repeater_H
#include "Shooter.h" // Include necessary header file(s)
#include "Animation.h"

class Repeater : public Shooter
{
	Animation* animate;
	Clock clock; // to handle stuff 
public:
	Repeater(); // Default construcotr
	void DrawRepeater(RenderWindow& window); // drawing repeater 
	void action(RenderWindow& window); // firing 
};



#endif // Repeater_H