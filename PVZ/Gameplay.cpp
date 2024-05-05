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
    this->money = 1000; // Set accordingly
    for (int i = 0; i < 5; ++i) {
        Guardians.push_back(new HouseGuardian("../Images/LawnMower.png"));
        Coordinates pos(200-(i*3), (i * 120) + 80);
        Guardians.back()->SetSprtePos(pos);
        Guardians.back()->SetCoordinates(pos);
    }

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
void Gameplay::StartGamePlay(RenderWindow& window) {
    for (int i = 0; i < Guardians.GetSize(); ++i) {
        if(Guardians[i]->GetExistance())
            window.draw(Guardians[i]->GetSprite());
        Guardians[i]->CheckCollision(this->zptr);
    }
    shop.DrawShop(window);
    this->checkShopClick(window);
    this->dropToGrid(window);
   
    for (int i = 0; i < ptr.GetSize(); i++)
    {
        ptr[i]->Action(window);
        ptr[i]->drawPlant(window);
    }
    for (int i = 0; i < zptr.GetSize(); i++) {
        zptr[i]->action(window, ptr, this->FIELD_GAME_STATUS);
        this->CheckCollision();
    }
    sun.DrawSun(window, money);
    // Currency Text
    font.loadFromFile("../fonts/comicsans.ttf");
    text.setFont(font);
    text.setCharacterSize(40);
    text.setString(to_string(money));
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(160, 8);
    window.draw(text);
}
void Gameplay::dropToGrid(RenderWindow& window)
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
                mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
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
                mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
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
                        bool spawned = false;

                        // Place the needed plant on the grid
                        if (id[index] == "sunflower" && money >= 50) {
                            ptr.push_back(new SunFlower(money));
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos - 30);
                            money -= ptr.back()->GetCost();
                            spawned = true;
                        }
                        else if (id[index] == "peashooter" && money >= 100) {
                            ptr.push_back(new PeaShooter);
                            cout << "1" << endl;
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos - 30);
                            money -= ptr.back()->GetCost();
                            spawned = true;
                        }
                        else if (id[index] == "wallnut" && money >= 50) {
                            ptr.push_back(new WallNut);
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos - 30);
                            money -= ptr.back()->GetCost();
                            spawned = true;
                        }
                        if (spawned)
                        {
                            FIELD_GAME_STATUS[row][col] = true;
                            ptr.back()->setI(row);
                            ptr.back()->setJ(col);
                        }
                    } 
                    else {
                        cout << "Cant place there" << endl;
                    }
                }
                selected = false;
            }
        }
    }
}
void Gameplay::CheckCollision() {
    for (size_t i = 0; i < ptr.GetSize(); ++i) {
        Plants* plant = ptr[i];
        if (plant->GetType() == "PeaShooter") {
            PeaShooter* shooter = (PeaShooter*)(plant);
            shooter->CheckBulletCollision(zptr);
        }
    }
}


void Gameplay::spawnZombies(int level)
{
    for (int i = 0, j=0; i < level * 5; i++, j++)
    {
        if (j == 5)
            j = 0;
        zptr.push_back(new NormalZombie);
        zptr[i]->setY(zptr[i]->getYPositions()[j]);
    }
    zptr.push_back(new FootballZombie);
    zptr.push_back(new FlyingZombie);
    zptr[0]->setX(1400);
    zptr[1]->setX(2000);
    zptr[2]->setX(2250);
    zptr[3]->setX(2500);  
    zptr[4]->setX(2750);
    zptr[5]->setX(2900);
    zptr[6]->setX(3100);
    zptr[7]->setX(3150);
    zptr[8]->setX(3300);
    zptr[9]->setX(3350);
    zptr[10]->setX(1200);
    zptr[10]->setY(zptr[0]->getYPositions()[0]);
    zptr[11]->setX(1200);
    zptr[11]->setY(zptr[0]->getYPositions()[1]);
}