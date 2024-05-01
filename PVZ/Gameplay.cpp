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

void Gameplay::checkShopClick(RenderWindow& window)
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
			}
		}

	}
}
void Gameplay::dropToGrid(RenderWindow& window, Plants** ptr)
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
				int k = -1;
				for (int i = 0; i < 45; i++)
				{
					if (ptr[i] != NULL)
						k = i;
					else
						break;
				}
				string* id = shop.getIds();
				k++;
				if (id[index] == "sunflower") {
					ptr[k] = new SunFlower;
					ptr[k]->setX(mouse.x);
					ptr[k]->setY(mouse.y);
				}
				else if (id[index] == "peashooter") {
					ptr[k] = new PeaShooter;
					ptr[k]->setX(mouse.x);
					ptr[k]->setY(mouse.y);
				}
				selected = false;
				firstClick = true;
			}
		}
	}
}