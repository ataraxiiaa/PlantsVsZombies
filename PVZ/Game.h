#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include "Menu.h"
#include "Sun.h"
#include "Shop.h"
#include "Paused.h"
#include "Level.h"
#include "Gameplay.h"
#include "Vector.h"
#include "BeginnersGarden.h"
#include "ZombieOutskirts.h"
#include "SunflowerFields.h"
#include <string>
using namespace sf;
using namespace std;

class Game
{
	MainMenu menu;
	Paused pause;
	Level* level;
	PeaShooter peaShooter;
	ZombieOutskirts zombieOutSkirts;
	BeginnersGarden beginner;
	SunflowerFields sunflower;
	Texture playerLivesTexture;
	Sprite playerLivesSprite[3];
	Shop shop;
	CherryBomb bomb;
	Repeater repeat;
	WallNut nutty;
	Sun sun;
	int money;
	Font font;
	Text text;
	int levels;
	int score;
	int playerLives;
	sf::SoundBuffer buffer;
	sf::Sound sound;
public:
	Game(); 
	// Function prototypes that are defined in Game.cpp
	void createBack(RenderWindow& window, Sprite sprite); // Creating Background
	void createMap(RenderWindow& window, Sprite sprite); // Creating window
	void createGrid(RenderWindow& window); // Creating a grid
	void Start_Game(); // Starts the Game window when called
};

