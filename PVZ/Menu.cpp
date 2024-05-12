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
	for (int i = 0; i < 2; ++i)
		text2[i].setFont(font);
	for (int i = 0; i < 3; ++i) {
		scoreText[i].setFont(font);
		scoreText[i].setFillColor(sf::Color::White);
		scoreText[i].setCharacterSize(50);
		//scores[i] = 0;
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
	gameOver = false;
	this->currentState = true;
	this->startGame = false;
}
void MainMenu::DisplayScore(RenderWindow& window) { //displays highscore screen
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
	ifstream file("../PVZ/highscores.txt");
	if (file.is_open()) {
		int index = 0;
		while (index < 3) {
			file >> names[index];
			file >> scores[index];
			++index;
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (scores[j + 1] > scores[j]) { //sorts highest scores
					int temp = scores[j + 1];
					string tempName = names[j + 1];

					scores[j + 1] = scores[j];
					scores[j] = temp;
					names[j + 1] = names[j];
					names[j] = tempName;
				}
			}
		}
		//displays top 3 scores and player names
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
void MainMenu::ShowGameOVer(RenderWindow& window, int score) { //shows gameover screen
	text2[0].setString("Enter your Name: ");
	text2[0].setCharacterSize(30);
	text2[0].setPosition(100, 350);
	text2[0].setFillColor(sf::Color::White);

	text2[1].setString("");
	text2[1].setCharacterSize(30);
	text2[1].setPosition(800, 350);
	text2[1].setFillColor(sf::Color::White);

	window.clear();

	sf::Event e;
	char temp;

	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			window.close();
		}
		if (e.type == sf::Event::TextEntered) {
			if (e.text.unicode <= 122 && e.text.unicode >= 65) {
				temp = e.text.unicode;
				name += temp;
			}
			if (e.text.unicode == 8 && name != "\0")
				name.pop_back();

		}
		if (e.type == sf::Event::KeyReleased) {
			if (e.key.code == sf::Keyboard::Enter)
				nameEntered = true;
		}
	}
	text2[1].setString(name);
	window.draw(text2[0]);
	window.draw(text2[1]);

	if (nameEntered) {
		string tempname[4]{};
		int tempscore[4]{};
		int index = 0;
		int saveScore;
		string saveName;

		fstream file("../PVZ/highscores.txt", ios::in | ios::out);
		while (file >> saveName >> saveScore && index < 3) {
			tempname[index] = saveName;
			tempscore[index] = saveScore;
			index++;
		}
		if (index < 3 || score > scores[index - 1])
		{
			tempscore[index] = score;
			tempname[index] = name;

			for (int i = 0; i < index; ++i) {
				for (int j = index; j > 0; --j) {
					if (tempscore[j] > tempscore[j - 1]) {
						int temp = tempscore[j];
						string tempName = tempname[j];

						tempscore[j] = tempscore[j - 1];
						tempname[j] = tempname[j - 1];
						tempscore[j - 1] = temp;
						tempname[j - 1] = tempName;
					}
				}
			}
			file.close();
			file.open("../PVZ/highscores.txt", ios::out | ios::trunc);
			for (int i = 0; i < index + 1; i++) {
				file << tempname[i] << " " << tempscore[i] << endl;
			}
		}
		this->gameOver = false;
		this->startGame = false;
		this->currentState = true;
		file.close();
	}
	window.display();
}
void MainMenu::DisplayMain(sf::RenderWindow& window) //displays mainmenu
{
	window.clear();
	this->setGameOver(false);
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
				this->startGame = true;
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
	//window.clear();
	if (Settings) {
		BackgroundS.setColor(sf::Color(255, 255, 255, 150));
		window.draw(BackgroundS);
		window.draw(sprite);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			Settings = false;
		}
	}
	if (showScoreBord)
	{
		BackgroundS.setColor(sf::Color(255, 255, 255, 150));
		window.draw(BackgroundS);
		DisplayScore(window);
	}

	else if (!showScoreBord && !Settings)
	{
		window.draw(BackgroundS); // Draws Main menus background
		window.draw(text[0]); // Drawing texts
		window.draw(text[1]);
		window.draw(text[2]);
		window.draw(text[3]);
	}
}