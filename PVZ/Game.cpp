#include "Game.h"

Game::Game()
{
	money = 0;
	//ptr = new Plants * [45];
	//for (int i = 0; i < 45; i++)
		//ptr[i] = nullptr;
	
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

			// Currency Text
			font.loadFromFile("../fonts/comicsans.ttf");
			text.setFont(font);
			text.setCharacterSize(40);
			text.setString(to_string(money));
			text.setFillColor(sf::Color::Yellow);
			text.setPosition(160, 8);

			//Create a background
			createBack(window);
			createMap(window);
			// Create the grid
			createGrid(window);
			if (pause.getCollect())
				sun.SetAutoCollect(true);
			else
				sun.SetAutoCollect(false);
			shop.DrawShop(window);
			game.checkShopClick(window, money);
			game.dropToGrid(window, ptr, money);
			game.CheckCollision(normal);
			//peaShooter.DrawPeaShooter(window);
			normal.drawZombie(window);
			//football.drawZombie(window);
			//football.moveZombie(ptr);
			//football.drawZombie(window);
			//flying.drawZombie(window);
			//dancing.drawZombie(window);
			//dolphin.drawZombie(window);
			//dancing.drawZombie(window);
			//dancing.moveZombie(ptr);
			normal.moveZombie(ptr);
			//sp.DrawSnowPea(window);
			//football.moveZombie(ptr);
			//flying.moveZombie();
			//dancing.moveZombie();
			//dolphin.moveZombie();
			//peaShooter.animate->DrawAnimation(window);
			// Drawing Sun
			//bomb.DrawCherryBomb(window);
			sun.DrawSun(window, money);
			//nutty.drawPlant(window);
			//nutty.Action(window);
			window.draw(text);
			window.setSize(sf::Vector2u(1100, 680));
			for (int i = 0; i < ptr.GetSize(); i++) 
			{
				ptr[i]->Action(window, money);
				ptr[i]->drawPlant(window);
			}
		}
		else if (!menu.ShowState() && pause.ShowState())
			pause.displayPausedMenu(window);

		window.display();
	}
}

