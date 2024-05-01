#include "Gameplay.h" // Include header file

Gameplay::Gameplay(): gridCols(9), gridRows(5)
{
	// Used to set up the grid 
	Pptr = new Plants * [45];
	for (int i = 0; i < 45; i++)
		Pptr[i] = nullptr;
	FIELD_GAME_STATUS = new bool*[gridRows];
	for (int i = 0; i < gridRows; ++i)
	{
		FIELD_GAME_STATUS[i] = new bool[gridCols];
	}
	for (int i = 0; i < gridRows; i++)
		for (int j = 0; j < gridCols; j++)
			FIELD_GAME_STATUS[i][j] = false;
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
				cout << "hit" << endl;
				index = i;
			}
		}
		if (selected)
		{
			cout << "sel" << endl;
			sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//if (sf::Mouse::getPosition().x > 200 && sf::Mouse::getPosition().y > 110)
				//{
				int k = -1;
				for (int i = 0; i < 45; i++)
				{
					if (Pptr[i] != NULL)
						k = i;
					else
						break;
				}
				string* id = shop.getIds();
				k++;
				if (id[index] == "sunflower")
					Pptr[k] = new SunFlower;
				selected = false;
				//}
				for (int i = 0; Pptr[i] != NULL; i++)
				{
					Sprite x;
					cout << Pptr[i][0].GetX() << ", " << Pptr[i][0].GetY() << endl;
					x = Pptr[i][0].getSprite();
					x.setPosition(Pptr[i][0].GetX(), Pptr[i][0].GetY());
					window.draw(x);
				}
			}
		}

	}
}

void Gameplay::dropToGrid(RenderWindow& window)
{

	
	
}