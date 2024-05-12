#include "Level.h"

Level::Level(int level) {
	this->level = level;
	start = false;
	srand(time(0));
	transitioning = false;
	font.loadFromFile("../fonts/logofont.otf");
	text.setFont(font);
	text.setFillColor(sf::Color::Yellow);
	text.setCharacterSize(30);
	text.setPosition(1000, 20);
	scoreFont.loadFromFile("../fonts/logofont.otf");
	scoreText.setFont(scoreFont);
	scoreText.setCharacterSize(30);
	scoreText.setPosition(700, 20);
	scoreText.setFillColor(sf::Color::Yellow);
	//option = 0;
	//max = 2;
	//font.loadFromFile("../fonts/logofont.otf");
	//for (int i = 0; i < 2; ++i)
	//{
	//	text[i].setFont(font);
	//	text[i].setFillColor(sf::Color::White);
	//	text[i].setCharacterSize(50); // Loading fonts and setting their sizes
	//}
}
void Level::CreateTransition(RenderWindow& window) {
	if (gamePlay.CheckTransitionCondition(this->level)) {
		drawTransition(window);


		gamePlay.resetGame();
		this->level += 1;
		clock.restart();
	}
	this->score = 0;
}
void Level::drawTransition(RenderWindow& window)
{
	Texture texture;
	Sprite sprite;
	texture.loadFromFile("../Images/transition.png");
	sprite.setTexture(texture);
	sprite.setPosition(350, 50);
	window.draw(sprite);
}
void Level::startGamePlay(RenderWindow& window,int &score) {
	int temp = gamePlay.getKilled();
	text.setString("Level " + to_string(level));
	gamePlay.StartGamePlay(window, this->level);
	if (temp < gamePlay.getKilled()) {
		score += 20;
	}
	scoreText.setString("Score " + to_string(score));
	window.draw(scoreText);
	window.draw(text);
}

//void Level::displayLevel(RenderWindow& window, int level) {
//	static Clock clock;
//	//if (clock.getElapsedTime().asSeconds() >= 10) 
//	//{
//	sf::Event e;
//	while (window.pollEvent(e))
//	{
//		if (e.type == sf::Event::Closed) // Checks if main window is closed or not
//			window.close();
//		if (e.key.code == sf::Keyboard::Enter && e.type == sf::Event::KeyPressed || clock.getElapsedTime().asSeconds() >= 2)
//			start = true;
//	}
//
//	// Setting text
//	text[0].setString("Level " + to_string(level));
//	text[0].setPosition(470, 300);
//	text[1].setString("Press Enter");
//	text[1].setPosition(330, 400);
//
//	// Loading Main backgorund png
//	Texture BackgroundT;
//	Sprite BackgroundS;
//
//	BackgroundT.loadFromFile("../Images/Main2.png");
//	BackgroundS.setTexture(BackgroundT);
//
//	window.clear();
//	window.draw(BackgroundS); // Draws Main menus background
//	window.draw(text[0]); // Drawing texts
//	window.draw(text[1]); // Drawing texts
//	//}
//	//else
//	//{
//		//start = true;
//		//clock.restart();
//	//}
//}