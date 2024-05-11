#pragma once
#ifndef Menu_H
#define Menu_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
using namespace sf;
using namespace std;
class Menu
{
protected:
	Font font;    // Used in other Menus
	Texture texture;
	Sprite sprite;
	Text text[3]; // for creating text for Screens
	bool currentState; // For tracking what Menu is open right now
	bool Settings;
public:
	bool ShowState()const { return currentState; } // Getter for state
	void setState(bool state) { this->currentState = state; } //setter for state

};


// Main Menu Class 
class MainMenu : public Menu
{
protected:
	int option; // used to track what option we are on
	int max; // maxiumum options in main
public:
	MainMenu();
	void DisplayMain(sf::RenderWindow& window);
	void MoveDown();
	void MoveUp();
};


#endif Menu_H // Menu_H