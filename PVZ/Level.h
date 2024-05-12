#pragma once
#ifndef Level_H
#define Level_H

#include "Menu.h"
#include "Gameplay.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Level { // Abstract class
protected:
	Vector<Sprite> transition;
	Gameplay gamePlay;
	Texture levelTexture;
	Sprite levelSprite;
	Text text, scoreText;
	Font font, scoreFont;
	bool start;
	int level;
	Clock clock,clock2;
	Texture texture;
	bool transitioning;
	int score;
public:
	Level(int level = 1);
	//getters
	bool getStart() { return this->start; }
	virtual int GetLevel() { return this->level; }
	Gameplay& GetGamePlay() { return this->gamePlay; }
	virtual Sprite GetSprite() { return levelSprite; }
	//setters
	void setStart(bool start) { this->start = start; }
	void setLevel(int level) { this->level = level; }

	void startGamePlay(RenderWindow& window, int& score, int& playerLives);//starts game

	void CreateTransition(RenderWindow& window); //creates a transition between levels
	void drawTransition(RenderWindow& window); //draws the transition
	
	virtual void DrawLevels(RenderWindow& window) { //draws the levels sprite
		window.draw(levelSprite);
	}
	virtual void Action(RenderWindow& window) = 0;
};


#endif