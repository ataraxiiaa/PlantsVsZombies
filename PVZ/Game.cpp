#include "Game.h"

Game::Game()
{
	money = 150;
	//ptr = new Plants * [45];
	//for (int i = 0; i < 45; i++)
		//ptr[i] = nullptr;
	level = 2;
	
}
void Game::createBack(RenderWindow& window)
{
	//Drawing the background
	Image map_image;
	//Will have to change the path to run it properly ig for this too
	map_image.loadFromFile("../Images/Background3.jpg");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}
void Game::createMap(RenderWindow& window) {
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
	gamep.spawnZombies(level);

	while (window.isOpen())
	{
		if (menu.ShowState() == true)
		{
			menu.DisplayMain(window);
			pause.setState(false);
		}
		
		if (!menu.ShowState() && !pause.ShowState())
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



			//Create a background
			createBack(window);
			createMap(window);
			// Create the grid
			createGrid(window);
			if (pause.getCollect())
				gamep.GetSun().SetAutoCollect(true);
			else
				gamep.GetSun().SetAutoCollect(false);

			gamep.StartGamePlay(window);


			window.draw(text);
			window.setSize(sf::Vector2u(1100, 680));
				
				
		}
		else if (!menu.ShowState() && pause.ShowState())
			pause.displayPausedMenu(window);

		window.display();
	}
}

