#pragma once
#include "Game.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Level : public MainMenu {
	bool start;
	int level;
public:
	Level(int level = 1);
	void displayLevel(RenderWindow& window, int level);
	bool getStart() { return this->start; }
	int getLevel() { return this->level; }
	void setStart(bool start) { this->start = start; }
	void setLevel(int level) { this->level = level; }
};