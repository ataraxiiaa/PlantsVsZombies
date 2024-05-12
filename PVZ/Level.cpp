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
		drawTransition(window); //draws transition and resets grid when transition condition is met
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
void Level::startGamePlay(RenderWindow& window,int &score, int& playerLives) {
	int temp = gamePlay.getKilled();
	text.setString("Level " + to_string(level));
	gamePlay.StartGamePlay(window, this->level, playerLives); //starts game 
	if (temp < gamePlay.getKilled()) {
		score += 20;
	}
	scoreText.setString("Score " + to_string(score));
	window.draw(scoreText);
	window.draw(text);
}