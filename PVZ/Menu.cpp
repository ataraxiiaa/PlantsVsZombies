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
void MainMenu::DisplayScore(RenderWindow& window) {

}

void MainMenu::DisplayMain(sf::RenderWindow& window)
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
				this->currentState = false; // Exists menu into the game
			}
			if (option == 1)
			{
				this->Settings = true;
			}
			if (option == 2) {
				exit(0);
			}
		}
	}

	// Setting text
	text[0].setString("Play");
	text[0].setPosition(470, 300);
	text[1].setString("Settings");
	text[1].setPosition(380, 400);
	text[2].setString("Exit");
	text[2].setPosition(470, 500);

	// Loading Main backgorund png
	Texture BackgroundT;
	Sprite BackgroundS;
	Texture texture;
	texture.loadFromFile("../Images/instructions6.png");
	Sprite sprite(texture);
	sprite.setScale(1, 0.79);

	//sf::Vector2i mouse = sf::Mouse::getPosition(window);

	BackgroundT.loadFromFile("../Images/Main2.png");
	BackgroundS.setTexture(BackgroundT);
	BackgroundS.setColor(sf::Color(255, 255, 255, 200));
	for (int i = 0; i < 3; ++i)
	{
		//		if (sunBounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		if (text[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
		{
			text[i].setFillColor(sf::Color::Yellow);
			option = i; // Update current option based on mouse hover
		}
		else
		{
			text[i].setFillColor(sf::Color::White);
		}
	}
	window.clear();
	if (Settings) {
		BackgroundS.setColor(sf::Color(255, 255, 255, 150));
		window.draw(BackgroundS);
		window.draw(sprite);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			Settings = false;
		}
	}
		
	else {
		window.draw(BackgroundS); // Draws Main menus background
		window.draw(text[0]); // Drawing texts
		window.draw(text[1]);
		window.draw(text[2]);
	}
}