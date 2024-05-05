#pragma once

#ifndef Repeater_H
#define Repeater_H
#include "Shooter.h" // Include necessary header file(s)
#include "Animation.h"

class Repeater : public Shooter
{
	Clock clock; // to handle stuff 
public:
	Repeater(); // Default construcotr
	//void DrawRepeater(RenderWindow& window); // drawing repeater 
	virtual void Action(RenderWindow& window); // firing 
};



#endif // Repeater_H