#include "Gameplay.h" // Include header file

Gameplay::Gameplay(): gridCols(9), gridRows(5)
{
	FIELD_GAME_STATUS = new bool*[gridRows];
	for (int i = 0; i < gridRows; ++i)
	{
		FIELD_GAME_STATUS[i] = new bool[gridCols];
	}
	for (int i = 0; i < gridRows; i++)
		for (int j = 0; j < gridCols; j++)
			FIELD_GAME_STATUS[i][j] = false;
	firstClick = true;
}
Gameplay::~Gameplay() {
	for (int i = 0; i < gridRows; ++i)
		delete[] FIELD_GAME_STATUS[i];

	delete[] FIELD_GAME_STATUS;
}

void Gameplay::checkShopClick(RenderWindow& window, Sun& sun)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		Sprite* sprites = shop.getSprite();
		sf::FloatRect* bounds = new sf::FloatRect[6];
		for (int i = 0; i < 6; i++)
			bounds[i] = sprites[i].getGlobalBounds();
		for (int i = 0; i < 6; i++)
		{
			if (bounds[i].contains(mouse))
			{
				selected = true;
				index = i;
				cout << "1" << endl;
			}
		}

	}
}
void Gameplay::dropToGrid(RenderWindow& window, Vector<Plants*> &ptr, Sun& sun)
{
	if (selected)
	{
		sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (firstClick)
			{
				firstClick = false;
			}
			else {
				/*int k = -1;
				for (int i = 0; i < 45; i++)
				{
					if (ptr[i] != NULL)
						k = i;
					else
						break;
				}*/
				string* id = shop.getIds();
				//k++;
				//each box is 90x100 
				if (id[index] == "sunflower") {
					if (mouse.x > 270 && mouse.x < 1050 && mouse.y > 80 && mouse.y < 650)
					{
						sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
						ptr.push_back(new SunFlower);						
						for (int i = 270; i < 1100; i += 92)
						{
							sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
							if (mouse.x >= i && mouse.x <= i + 92)
								ptr[ptr.GetSize() - 1]->setX((2 * i + 80)/2);
						}
						for (int i = 80; i < 650; i += 106)
						{
							sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
							if (mouse.y >= i && mouse.y <= i + 106)
								ptr[ptr.GetSize() - 1]->setY((2 * i + 95) / 2);
						}
						cout << "spawned" << endl;
					}
				}
				else if (id[index] == "peashooter") {
					if (mouse.x > 270 && mouse.x < 1050 && mouse.y > 80 && mouse.y < 650)
					{
						sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
						ptr.push_back(new PeaShooter);
						for (int i = 270; i < 1100; i += 92)
						{
							sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
							if (mouse.x >= i && mouse.x <= i + 92)
								ptr[ptr.GetSize() - 1]->setX((2 * i + 80) / 2);
						}
						for (int i = 80; i < 650; i += 106)
						{
							sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
							if (mouse.y >= i && mouse.y <= i + 106)
								ptr[ptr.GetSize() - 1]->setY((2 * i + 95) / 2);
						}
						cout << "spawned" << endl;
					}
				}
				selected = false;
				firstClick = true;
			}
		}
	}
}