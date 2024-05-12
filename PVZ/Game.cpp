#include "Game.h"

Game::Game()
{
	levels = 1;	
	level = new BeginnersGarden;
	score = 0;
	playerLives = 3;
	playerLivesTexture.loadFromFile("../Images/soul.png");
	for (int i = 0; i < 3; ++i) {
		playerLivesSprite[i].setTexture(playerLivesTexture);
	}
	for (int i = 0; i < 3; ++i) {
		playerLivesSprite[i].setPosition(230 + (i * 50), -200);
		playerLivesSprite[i].setScale(1, 1);
	}
	buffer.loadFromFile("../Sounds/music1.mp3");
	sound.setBuffer(buffer);


}
void Game::createBack(RenderWindow& window,Sprite sprite)
{
	//Drawing the background
	//Image map_image;
	////Will have to change the path to run it properly ig for this too
	//map_image.loadFromFile("../Images/Background3.jpg");
	//Texture map;
	//map.loadFromImage(map_image);
	//Sprite s_map;
	//s_map.setTexture(map);
	//s_map.setPosition(0, 0);
	window.draw(sprite);
}
void Game::createMap(RenderWindow& window, Sprite sprite) {
	//Drawing a map
	Image map_image;
	//Will have to change the path to run it properly ig for this too
	map_image.loadFromFile("../Images/backwindow2.jpg");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(300, 160);
}
void Game::createGrid(RenderWindow& window)
{
	// Adding Grid
	Texture GridT;
	GridT.loadFromFile("../Images/grid2.png");
	Sprite Grid;
	Grid.setTexture(GridT);
	Grid.setPosition(280, 50);
	window.draw(Grid);

}
void Game::Start_Game()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");
	//Game icon
	Image icon;
	//Will have to change the path to run it properly ig
	if (!icon.loadFromFile("../Images/backwindow.jpg")) 
	{
		return;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	/*const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}*/

	Clock timeMoney;
	Clock clock;
	int i = 0;
	sound.play();
	while (window.isOpen())
	{
		if (menu.ShowState() == true)
		{
			menu.DisplayMain(window);
			pause.setState(false);
			//menu.ShowGameOVer(window, 50);
		}
		while (menu.getGameOver()) {
			menu.ShowGameOVer(window, score);
			/*if (menu.getGameOver() == false) {
				menu.setState(true);
			}*/
		}
		if (pause.restartGame()) {
			level->GetGamePlay().resetGame();
			delete level;
			level = new BeginnersGarden;
			levels = 0;
			this->score = 0;
			this->playerLives = 3;
			pause.setResetGame(false);
		}
		if (!menu.ShowState() && !pause.ShowState() && menu.showGame())
		{
			float time = clock.getElapsedTime().asMicroseconds();
			float moneyTime = timeMoney.getElapsedTime().asSeconds();

			clock.restart();
			time = time / 800;

			Event event;
			while (window.pollEvent(event))
				if (event.type == Event::Closed)
					window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				pause.setState(true);


			createGrid(window);
			//Create a background
			createBack(window, level->GetSprite());
			createMap(window, level->GetSprite());
			if (level->GetLevel() == 1 || level->GetLevel()==3) {
				createGrid(window);
			}
			// Create the grid
			if (pause.getCollect())
				level->GetGamePlay().GetSun().SetAutoCollect(true);
			else
				level->GetGamePlay().GetSun().SetAutoCollect(false);

			level->startGamePlay(window, this->score,playerLives);
			level->GetGamePlay().spawnZombies(levels); // , clock);
			level->CreateTransition(window);
			int x = level->GetLevel();
			if (x == 2) {
				level = &zombieOutSkirts;
				level->Action(window);
			} 
			if (x == 3) {
				level = &sunflower;
				level->Action(window);
			}
			for (int i = 0; i < playerLives; ++i) {
				window.draw(playerLivesSprite[i]);
			}
			window.draw(text);
			window.setSize(sf::Vector2u(1100, 680));
		}
		int x = level->GetLevel();
		if (level->GetGamePlay().checkEnd(x,playerLives) && menu.getGameOver() == false) {
			//menu.ShowGameOVer(window, 50);
			menu.setGameOver(true);
			menu.setShowGame(false);
		}
		if (!menu.ShowState() && pause.ShowState())
			pause.displayPausedMenu(window);
		/*else if (!menu.ShowState() && !pause.ShowState() && !level.getStart()) {
			level.displayLevel(window, levels);
		}*/
		window.display();
	}
}

