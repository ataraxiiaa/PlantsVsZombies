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
	dragging = false;
    // Setting up rectange
    rectangle.setSize(sf::Vector2f(50, 100));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(5);

}
Gameplay::~Gameplay() {
	for (int i = 0; i < gridRows; ++i)
		delete[] FIELD_GAME_STATUS[i];

	delete[] FIELD_GAME_STATUS;
}

void Gameplay::checkGrid(int& row, int& col, float& xPos, float& yPos, RenderWindow& window, sf::Vector2f& mouse)
{
	mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (mouse.x > 270 && mouse.x < 1100 && mouse.y > 80 && mouse.y < 680)
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
		for (int i = 80, j = 0; i < 680 && j < 5; i += 106, j++)
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
void Gameplay::dropToGrid(RenderWindow& window, Vector<Plants*>& ptr, int& money)
{
    Sprite* sprites = shop.getSprite();
    Vector<Sprite> SelectedSprite = shop.getSelectedSprite();
    if (selected)
    {
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (!dragging)
            {
                // Start dragging if the left mouse button is pressed and not already dragging
                dragging = true;
                Sprite temp = sprites[index];
                temp.setTextureRect(sprites[index].getTextureRect());
                temp.setPosition(mouse);

                window.draw(temp);
                window.draw(SelectedSprite[index]);
            }
            else
            {
                Sprite temp = sprites[index];
                temp.setTextureRect(sprites[index].getTextureRect());
                temp.setPosition(mouse);

                window.draw(temp);
                window.draw(SelectedSprite[index]);
            }
        }
        else
        {
            if (dragging)
            {
                // If the left mouse button is released
                dragging = false;

                int row = 0, col = 0;
                float xPos = 0, yPos = 0;
                string* id = shop.getIds();

                // Check if the mouse is within the playable grid area
                if (mouse.x > 270 && mouse.x < 1100 && mouse.y > 80 && mouse.y <= 700)
                {
                    checkGrid(row, col, xPos, yPos, window, mouse);
                    // Check if the target grid cell is empty
                    if (!FIELD_GAME_STATUS[row][col])
                    {
                        FIELD_GAME_STATUS[row][col] = true;

                        // Place the needed plant on the grid
                        if (id[index] == "sunflower") {
                            ptr.push_back(new SunFlower);
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos-30);
                        }
                        else if (id[index] == "peashooter") {
                            ptr.push_back(new PeaShooter);
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos-30);
                        }
                        else if (id[index] == "wallnut") {
                            ptr.push_back(new WallNut);
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos - 30);
                        }

                        cout << "placed" << endl;
                    }
                    else
                    {
                        cout << "already there" << endl;
                    }
                }
                else
                {
                    cout << "out of bounds" << endl;
                }
                selected = false;
            }
        }
    }
}
