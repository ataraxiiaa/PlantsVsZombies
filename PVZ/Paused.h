#pragma once
#include "Game.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Paused: public MainMenu{
	bool collect;
	bool temp;
	bool On, Off;
	bool restart;
public:
	Paused()
	{
		option = 0;
		max = 3;
		collect = false;
		temp = collect;
		font.loadFromFile("../fonts/logofont.otf");
		for (int i = 0; i < 3; ++i)
		{
			text[i].setFont(font);
			text[i].setFillColor(sf::Color::White);
			text[i].setCharacterSize(50); // Loading fonts and setting their sizes
		}
		this->restart = false;
	}
	void displayPausedMenu(RenderWindow& window)
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) // Checks if main window is closed or not
				window.close();
			if (sf::Mouse::isButtonPressed(Mouse::Button::Left))
			{
				if (option == 0) // Enters into the game
				{
					currentState = false; // Exists menu into the game
				}
				else if (option == 2)
				{
					window.close();
				}
				else if (option == 1)
				{
					collect = !collect; //toggles autocollect sun option
				}
				else if (option == 3) 
				{
					this->restart = true;
					this->startGame = true;
					currentState = false;
				}
			}
		}

		// Setting text
		text[0].setString("Return");
		text[0].setPosition(400, 300);
		text[1].setString("Auto Collect Sun : ");

		Text texton;
		texton.setFont(font);
		texton.setCharacterSize(50);
		texton.setString("ON");
		texton.setPosition(1000, 400);
		Text textoff;
		textoff.setFont(font);
		textoff.setCharacterSize(50);
		textoff.setString("OFF");
		textoff.setPosition(1000, 400);

		text[1].setPosition(150, 400);
		text[2].setString("Exit");
		text[2].setPosition(470, 600);
		text[3].setString("Restart");
		text[3].setPosition(400, 500);
		//sf::Vector2i mouse = sf::Mouse::getPosition(window);
		for (int i = 0; i < 4; ++i)
		{
			//		if (sunBounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			if (text[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				text[i].setFillColor(sf::Color::Yellow);
				option = i; 
			}
			else
			{
				text[i].setFillColor(sf::Color::White);
			}
		}
		// Loading Main backgorund png
		Texture BackgroundT;
		Sprite BackgroundS;

		BackgroundT.loadFromFile("../Images/Main2.png");
		BackgroundS.setTexture(BackgroundT);
		window.clear();
		window.draw(BackgroundS); // Draws Main menus background
		window.draw(text[0]); // Drawing texts
		window.draw(text[1]);
		if (collect) {
			//window.clear();
			window.draw(texton);
		}
		else {
			//window.clear();
			window.draw(textoff);
		}

		window.draw(text[2]);
		window.draw(text[3]);
	}
	bool getCollect() { return this->collect; }
	bool restartGame() { return restart; }
	void setResetGame(bool i) { this->restart = i; }
};