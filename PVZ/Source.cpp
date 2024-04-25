#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
using namespace sf;
using namespace std;


struct Coordinates {
	int x;
	int y;
};



//Drawing the background
void createBack(RenderWindow& window) {
	//Drawing the background
	Image map_image;
	//Will have to change the path to run it properly ig for this too
	map_image.loadFromFile("C:/Users/Ali Abdullah/Desktop/PlantsVsZombies/Images/backwindow.jpg"); 
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}

//Drawing the map
void createMap(RenderWindow& window) {
	//Drawing a map
	Image map_image;
	//Will have to change the path to run it properly ig for this too
	map_image.loadFromFile("C:/Users/Ali Abdullah/Desktop/PlantsVsZombies/Images/backwindow.jpg");//load the file for the map
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	s_map.setPosition(300, 160);

	window.draw(s_map);
}


int main()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");
	//Game icon
	Image icon;
	//Will have to change the path to run it properly ig
	if (!icon.loadFromFile("C:/Users/Ali Abdullah/Desktop/PlantsVsZombies/Images/backwindow.jpg")) 
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}

	Clock timeMoney;



	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();

		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//Create a background
		createBack(window);
		createMap(window);




		window.setSize(sf::Vector2u(550, 340));
		window.display();
	}
	return 0;
}