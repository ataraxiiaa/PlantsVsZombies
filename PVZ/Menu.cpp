#include "Menu.h"


MainMenu::MainMenu()
{
	option = 0; // For tracking which button we are on
	max = 3; // Maximum options in Main menu
	currentState = true; 
	font.loadFromFile("../fonts/logofont.otf");
	for (int i = 0; i < 3; ++i)
	{
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(50); // Loading fonts and setting their sizes
	}
}
void MainMenu::MoveUp()
{
	if (option == 0) {
		text[option].setFillColor(sf::Color::White);
		option = max - 1;
		text[option].setFillColor(sf::Color::Yellow);
	}
	else if (option > 0) {
		text[option].setFillColor(sf::Color::White);
		text[--option].setFillColor(sf::Color::Yellow);
	}
}
void MainMenu::MoveDown()
{
	if (option == max - 1)
	{
		text[0].setFillColor(sf::Color::Yellow);
		text[option].setFillColor(sf::Color::White);
		option = 0;
	}
	else if (option < max - 1)
	{
		text[option].setFillColor(sf::Color::White);
		text[++option].setFillColor(sf::Color::Yellow);
		
	}
}

void MainMenu::DisplayMain(sf::RenderWindow& window)
{
	sf::Event e;
	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed) // Checks if main window is closed or not
			window.close();
		if (e.key.code == sf::Keyboard::Enter)
		{
			if (option == 0) // Enters into the game
			{
				currentState = false; // Exists menu into the game
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
	text[0].setString("Play");
	text[0].setPosition(470, 300);
	text[1].setString("Settings");
	text[1].setPosition(380, 400);
	text[2].setString("Help");
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