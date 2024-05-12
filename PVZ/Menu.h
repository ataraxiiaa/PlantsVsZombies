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
	void DisplayMain(sf::RenderWindow& window); //displays main menu
	bool ShowState()const { return currentState; } // Getter for state
	void setState(bool state) { this->currentState = state; } //setter for state
	void DisplayScore(RenderWindow& window); //displays highscore
	void ShowGameOVer(RenderWindow& window,int score); //prompts player to enter name when game is over
	bool getGameOver()const { return gameOver; } //getter for gameOver
	void setGameOver(bool i) { gameOver = i; } //setter for gameOver
	bool showGame() { return startGame; } //getter for startGame
	void setShowGame(bool i) { startGame = i; } //setter for startGame

};


#endif // Menu_H