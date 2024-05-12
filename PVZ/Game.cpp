#include "Game.h"

Game::Game()
{
	levels = 1;	
	level = new BeginnersGarden; //sets first levels sprite
	score = 0; 
	playerLives = 3; //set lives for player
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
	sound.setVolume(0);
}
void Game::createBack(RenderWindow& window,Sprite sprite)
{
	window.draw(sprite);
}
void Game::createMap(RenderWindow& window, Sprite sprite) {
	//Drawing a map
	Image map_image;
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
	if (!icon.loadFromFile("../Images/backwindow.jpg")) 
	{
		return;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	Clock timeMoney;
	Clock clock;
	int i = 0;
	sound.play();
	while (window.isOpen())
	{
		if (menu.ShowState() == true) //display start menu if not entered into game
		{
			menu.DisplayMain(window); 
			pause.setState(false);
			//menu.ShowGameOVer(window, 50);
		}
		while (menu.getGameOver()) { //display end screen when game ended
			menu.ShowGameOVer(window, score);
			/*if (menu.getGameOver() == false) {
				menu.setState(true);
			}*/
		}
		if (pause.restartGame()) { //restarts game if option selected
			level->GetGamePlay().resetGame();
			delete level;
			level = new BeginnersGarden;
			levels = 0;
			this->score = 0;
			this->playerLives = 3;
			pause.setResetGame(false);
		}
		if (!menu.ShowState() && !pause.ShowState() && menu.showGame()) //enters into game
		{
			float time = clock.getElapsedTime().asMicroseconds();
			float moneyTime = timeMoney.getElapsedTime().asSeconds();

			clock.restart();
			time = time / 800;

			Event event;
			while (window.pollEvent(event))
				if (event.type == Event::Closed)
					window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //displays pause screen if escape pressed
				pause.setState(true);


			createGrid(window);
			//Create a background
			createBack(window, level->GetSprite());
			createMap(window, level->GetSprite());
			if (level->GetLevel() == 1 || level->GetLevel()>=3) {
				createGrid(window);
			}
			// Create the grid
			if (pause.getCollect())
				level->GetGamePlay().GetSun().SetAutoCollect(true);
			else
				level->GetGamePlay().GetSun().SetAutoCollect(false);

			level->startGamePlay(window, this->score,playerLives); //starts game 
			level->GetGamePlay().spawnZombies(levels); // , clock); //spawns zombies
			level->CreateTransition(window); //creates transition to next level
			int x = level->GetLevel(); //sets background sprite according to level
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
		if (level->GetGamePlay().checkEnd(x,playerLives) && menu.getGameOver() == false) { //checks ending condition of game 
			menu.setGameOver(true);
			menu.setShowGame(false);
		}
		if (!menu.ShowState() && pause.ShowState())
			pause.displayPausedMenu(window); //displays pause screen
		window.display();
	}
}

