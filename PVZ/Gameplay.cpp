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

void Gameplay::checkGrid(int& row, int& col, float& xPos, float& yPos, RenderWindow& window, sf::Vector2f& mouse)
{
	mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (mouse.x > 270 && mouse.x < 1100 && mouse.y > 80 && mouse.y < 650)
	{
		mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		for (int i = 270, j = 0; i < 1100 && j < 9; i += 92, j++)
		{
			mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			//check which jth index of grid is selected by mouse
			if (mouse.x >= i && mouse.x <= i + 92)
			{
				col = j;
				xPos = (2 * i + 80) / 2;
			}
		}
		for (int i = 80, j = 0; i < 650 && j < 5; i += 106, j++)
		{
			mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			//check which ith index of grid is selected by mouse
			if (mouse.y >= i && mouse.y <= i + 106)
			{
				row = j;
				yPos = (2 * i + 95) / 2;
			}
		}
	}
}

void Gameplay::checkShopClick(RenderWindow& window, int& money)
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
				cout << "sel" << endl;
			}
		}

	}
}
void Gameplay::dropToGrid(RenderWindow& window, Vector<Plants*> &ptr, int& money)
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
			else 
			{
				int row = 0, col = 0;
				float xPos = 0, yPos = 0;
				string* id = shop.getIds();
				//each box is 90x100 
				if (id[index] == "sunflower") 
				{
					checkGrid(row, col, xPos, yPos, window, mouse);
					//check if any plant exists at that position. if no, then spawn new plant
					if (!FIELD_GAME_STATUS[row][col])
					{
						FIELD_GAME_STATUS[row][col] = true;
						ptr.push_back(new SunFlower);
						
						if (xPos == 0 && yPos == 0)
						{
							xPos = 310;
							yPos = 127.5;
						}
						ptr[ptr.GetSize() - 1]->setX(xPos);
						ptr[ptr.GetSize() - 1]->setY(yPos);
						cout << "spaned" << endl;
					}
					else
						cout << "no" << endl;
				}
				else if (id[index] == "peashooter") 
				{
					checkGrid(row, col, xPos, yPos, window, mouse);
					//check if any plant exists at that position. if no, then spawn new plant
					if (!FIELD_GAME_STATUS[row][col])
					{
						FIELD_GAME_STATUS[row][col] = true;
						ptr.push_back(new PeaShooter);
						ptr[ptr.GetSize() - 1]->setX(xPos);
						ptr[ptr.GetSize() - 1]->setY(yPos);
					}
				}
				else if (id[index] == "wallnut")
				{
					checkGrid(row, col, xPos, yPos, window, mouse);
					if (!FIELD_GAME_STATUS[row][col])
					{
						FIELD_GAME_STATUS[row][col] = true;
						ptr.push_back(new WallNut);
						ptr[ptr.GetSize() - 1]->setX(xPos);
						ptr[ptr.GetSize() - 1]->setY(yPos);
					}
				}
				else if (id[index] == "repeater")
				{
					checkGrid(row, col, xPos, yPos, window, mouse);
					if (!FIELD_GAME_STATUS[row][col])
					{
						FIELD_GAME_STATUS[row][col] = true;
						ptr.push_back(new Repeater);
						ptr[ptr.GetSize() - 1]->setX(xPos);
						ptr[ptr.GetSize() - 1]->setY(yPos);
					}
				}
				else if (id[index] == "cherrybomb")
				{
					checkGrid(row, col, xPos, yPos, window, mouse);
					if (!FIELD_GAME_STATUS[row][col])
					{
						FIELD_GAME_STATUS[row][col] = true;
						ptr.push_back(new CherryBomb);
						ptr[ptr.GetSize() - 1]->setX(xPos);
						ptr[ptr.GetSize() - 1]->setY(yPos);
					}
				}
				else if (id[index] == "snowpea")
				{
					checkGrid(row, col, xPos, yPos, window, mouse);
					if (!FIELD_GAME_STATUS[row][col])
					{
						FIELD_GAME_STATUS[row][col] = true;
						ptr.push_back(new SnowPea);
						ptr[ptr.GetSize() - 1]->setX(xPos);
						ptr[ptr.GetSize() - 1]->setY(yPos);
					}
				}


				selected = false;
				firstClick = true;
			}
		}
	}
}