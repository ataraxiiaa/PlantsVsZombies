#pragma once
#ifndef Menu_H
#define Menu_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace sf;
using namespace std;

class MainMenu 
{
protected:
	int option; // used to track what option we are on
	int max; // maxiumum options in main
	Font font,font2;    // Used in other Menus
	Texture texture,templateTexture;
	Sprite sprite, templateSprite;
	Text text[4],text2[2];; // for creating text for Screens
	bool currentState; // For tracking what Menu is open right now
	bool Settings;
	int scores[3];
	bool showScoreBord;
	string name;
	Text scoreText[3];
	string names[3];
	Texture ranking[3];
	Sprite rankingSprite[3];
	bool nameEntered;
	bool gameOver;
	bool startGame;
public:
	MainMenu();
	void DisplayMain(sf::RenderWindow& window);
	bool ShowState()const { return currentState; } // Getter for state
	void setState(bool state) { this->currentState = state; } //setter for state
	void DisplayScore(RenderWindow& window);
	void ShowGameOVer(RenderWindow& window,int score);
	bool getGameOver()const { return gameOver; }
	void setGameOver(bool i) { gameOver = i; }
	bool showGame() { return startGame; }
	void setShowGame(bool i) { startGame = i; }
};


#endif // Menu_H