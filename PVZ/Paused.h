#pragma once
#include "Game.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Paused: public MainMenu{
	bool collect;
	bool temp;
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
	}
	void displayPausedMenu(RenderWindow& window)
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) // Checks if main window is closed or not
				window.close();
			if (e.key.code == sf::Keyboard::Enter && e.type==sf::Event::KeyPressed)
			{
				if (option == 0) // Enters into the game
				{
					currentState = false; // Exists menu into the game
				}
				else if (option == 2)
				{
					window.close();
				}
				else
				{
					collect = !collect;
				}
			}
			if (option == 0)
			{
				text[0].setFillColor(sf::Color::Yellow);
			}
			if (e.type == sf::Event::KeyReleased)
			{
				if (e.key.code == sf::Keyboard::Down) // tracks keyboard up and down
					MoveDown();
				if (e.key.code == sf::Keyboard::Up)
					MoveUp();
			}
		}

		// Setting text
		text[0].setString("Return");
		text[0].setPosition(470, 300);
		text[1].setString("Auto Collect Sun");
		if (collect)
		{
			text[1].setFillColor(sf::Color::Red);
		}
		text[1].setPosition(300, 400);
		text[2].setString("Exit");
		text[2].setPosition(470, 500);

		// Loading Main backgorund png
		Texture BackgroundT;
		Sprite BackgroundS;

		BackgroundT.loadFromFile("../Images/Main2.png");
		BackgroundS.setTexture(BackgroundT);

		window.clear();
		window.draw(BackgroundS); // Draws Main menus background
		window.draw(text[0]); // Drawing texts
		window.draw(text[1]);
		window.draw(text[2]);
	}
	bool getCollect() { return this->collect; }
};