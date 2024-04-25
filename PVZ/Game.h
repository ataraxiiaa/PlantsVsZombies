#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
using namespace sf;
using namespace std;

class Game
{
public:
	Game() = default; // (Default for now will change later on)
	// Function prototypes that are defined in Game.cpp
	void createBack(RenderWindow& window); // Creating Backgrund
	void createMap(RenderWindow& window); // Creating window
	void Start_Game(); // Starts the Game window when called
};

