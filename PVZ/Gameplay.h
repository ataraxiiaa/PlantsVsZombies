#pragma once
#ifndef Gameplay_H
#define Gameplay_H

#include "Plants.h" // Include neceassary header file(s)
#include "Zombies.h"
#include "Shop.h"

class Gameplay
{
	Shop shop;
	Plants** Pptr; // Plant pointer
	Zombie* Zptr; // Zombie plant
	const int gridCols, gridRows; // Making Grid
	bool** FIELD_GAME_STATUS; // Bool to track Grid movement
public:
	Gameplay(); // Default Constructor
	~Gameplay(); // Destructor 
	// Creating functions for Gameplay
	
};



#endif // Gameplay_H

