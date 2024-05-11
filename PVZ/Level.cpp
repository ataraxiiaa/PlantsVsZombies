#include "Level.h"

Level::Level(int level) {
	this->level = level;
	start = false;
	option = 0;
	max = 2;
	font.loadFromFile("../fonts/logofont.otf");
	for (int i = 0; i < 2; ++i)
	{
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(50); // Loading fonts and setting their sizes
	}
}
void Level::displayLevel(RenderWindow& window, int level) {
	static Clock clock;
	//if (clock.getElapsedTime().asSeconds() >= 10) 
	//{
	sf::Event e;
	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed) // Checks if main window is closed or not
			window.close();
		if (e.key.code == sf::Keyboard::Enter && e.type == sf::Event::KeyPressed || clock.getElapsedTime().asSeconds() >= 2)
			start = true;
	}

	// Setting text
	text[0].setString("Level " + to_string(level));
	text[0].setPosition(470, 300);
	text[1].setString("Press Enter");
	text[1].setPosition(330, 400);

	// Loading Main backgorund png
	Texture BackgroundT;
	Sprite BackgroundS;

	BackgroundT.loadFromFile("../Images/Main2.png");
	BackgroundS.setTexture(BackgroundT);

	window.clear();
	window.draw(BackgroundS); // Draws Main menus background
	window.draw(text[0]); // Drawing texts
	window.draw(text[1]); // Drawing texts
	//}
	//else
	//{
		//start = true;
		//clock.restart();
	//}
}