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

	Game()
	{
		
	}
	//Function prototypes that are defined in Game.cpp
	void createBack(RenderWindow& window);
	void createMap(RenderWindow& window);
	void Start_Game();
};

