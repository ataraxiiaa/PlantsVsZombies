#include "Menu.h"


MainMenu::MainMenu()
{
	option = 0; // For tracking which button we are on
	max = 4; // Maximum options in Main menu
	currentState = true; 
	font.loadFromFile("../fonts/logofont.otf");
	font2.loadFromFile("../fonts/Impostograph-Regular.ttf");
	for (int i = 0; i < 4; ++i)
	{
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(50); // Loading fonts and setting their sizes
	}
	for (int i = 0; i < 3; ++i) {
		scoreText[i].setFont(font);
		scoreText[i].setFillColor(sf::Color::White);
		scoreText[i].setCharacterSize(50);
		scores[i] = 0;
	}
	showScoreBord = false;
	ranking[0].loadFromFile("../Images/gold.png");
	ranking[1].loadFromFile("../Images/silver.png");
	ranking[2].loadFromFile("../Images/bronze.png");
	for (int i = 0; i < 3; ++i) {
		rankingSprite[i].setTexture(ranking[i]);
	}
	templateTexture.loadFromFile("../Images/template.png");
	templateSprite.setTexture(templateTexture);
	templateSprite.setPosition(300, 200);
}
void MainMenu::DisplayScore(RenderWindow& window) {
	Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed)
			window.close();
		if (e.key.code == sf::Keyboard::Escape) {
			showScoreBord = false;
			currentState = true;
		}
	}
	templateSprite.setScale(1.2, 1);
	window.draw(templateSprite);
	ifstream file("../PVZ/highscore.txt");
	if (file.is_open()) {
		int index = 0;
		while (index < 3) {
			file >> names[index]; 
			file >> scores[index];
			++index;
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (scores[j + 1] > scores[j]) {
					int temp = scores[j + 1];
					string tempName = names[j + 1];

					scores[j + 1] = scores[j];
					scores[j] = temp;
					names[j + 1] = names[j];
					names[j] = tempName;
				}
			}
		}

		for (int i = 0; i < 3; ++i) {
			scoreText[i].setString(names[i] + "  " + to_string(scores[i]));
			scoreText[i].setPosition(450, 300 + (i * 100));
			window.draw(scoreText[i]);
		}
		for (int i = 0; i < 3; ++i) {
			rankingSprite[i].setScale(0.25, 0.25);
			rankingSprite[i].setPosition(360, 300 + (i * 100));
			window.draw(rankingSprite[i]);
		}
		file.close();
	}
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
			if (option == 1) {
				this->showScoreBord = true;
				this->Settings = false;
			}
			if (option == 2)
			{
				this->Settings = true;
				this->showScoreBord = false;
			}
			if (option == 3) {
				exit(0);
			}
		}
	}

	// Setting text
	text[0].setString("Play");
	text[0].setPosition(470, 300);
	text[1].setString("Leaderboard");
	text[1].setPosition(300, 400);
	text[2].setString("Instructions");
	text[2].setPosition(290, 500);
	text[3].setString("Exit");
	text[3].setPosition(470, 600);

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
	for (int i = 0; i < 4; ++i)
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
	if (showScoreBord)
	{
		BackgroundS.setColor(sf::Color(255, 255, 255, 150));
		window.draw(BackgroundS);
		DisplayScore(window);
	}
		
	else if(!showScoreBord && !Settings)
	{
		window.draw(BackgroundS); // Draws Main menus background
		window.draw(text[0]); // Drawing texts
		window.draw(text[1]);
		window.draw(text[2]);
		window.draw(text[3]);
	}
}