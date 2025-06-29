#include "Gameplay.h" // Include header file

Gameplay::Gameplay(): gridCols(9), gridRows(5)
{
    xRange = 1100;
    endZombies = 0;
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
    cooldown = new Clock[7];
    // Setting up rectange
    rectangle.setSize(sf::Vector2f(50, 100));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineThickness(5);
    this->money = 1500; // Set accordingly
    this->zombiesSpawned = 0;
    this->zombiesKilled = 0;
    restart = false;
    texture = new Texture[7];
    texture[0].loadFromFile("../Images/SunFlowerShop2.png");
    texture[1].loadFromFile("../Images/PeaShooterShop2.png");
    texture[2].loadFromFile("../Images/potshape.png");
    texture[3].loadFromFile("../Images/CherryBombShop.png");
    texture[4].loadFromFile("../Images/RepeaterShop.png");
    texture[5].loadFromFile("../Images/snowPeaShop.png");
    texture[6].loadFromFile("../Images/fumeshroomshop.png");

    int yPositions[5];
    yPositions[0] = 97.5 - 40;
    yPositions[1] = 203 - 40;
    yPositions[2] = 309 - 40;
    yPositions[3] = 415 - 30;
    yPositions[4] = 521 - 20;
    for (int i = 0; i < 5; ++i) {
        Guardians.push_back(new HouseGuardian("../Images/LawnMower.png"));
        Coordinates pos1(200 - (i * 3), (i * 120) + 95);
        Coordinates pos2(200 - (i * 3), yPositions[i]);
        Guardians.back()->SetSpritePosGuard(pos1);
        Guardians.back()->SetSprtePos(pos1);
        Guardians.back()->SetCoordinates(pos2);
    }

    this->score = 0;
    this->zombiesKilled = 0;
    font.loadFromFile("../fonts/comicsans.ttf");
    text.setFont(font);
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(130, 20);
    font.loadFromFile("../fonts/logofont.otf");
}
Gameplay::~Gameplay() {
    for (int i = 0; i < gridRows; ++i) {
        if(FIELD_GAME_STATUS[i] != nullptr)
        delete[] FIELD_GAME_STATUS[i];
    }
    if (FIELD_GAME_STATUS != nullptr)
        delete[] FIELD_GAME_STATUS;
}

void Gameplay::checkGrid(int& row, int& col, float& xPos, float& yPos, RenderWindow& window, sf::Vector2f& mouse) //function to check where player clicks with mouse
{
    mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (mouse.x > 270 && mouse.x < xRange && mouse.y > 80 && mouse.y < 680) //legal area for game
    {
        mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        for (int i = 270, j = 0; i < xRange && j < 9; i += 92, j++)
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

void Gameplay::checkShopClick(RenderWindow& window) //function to check which sprite from shop is clicked
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        Sprite* sprites = shop.getSprite();
        sf::FloatRect* bounds = new sf::FloatRect[7];
        for (int i = 0; i < shop.getElement(); i++)
            bounds[i] = sprites[i].getGlobalBounds();
        for (int i = 0; i < shop.getElement(); i++)
        {
            if (bounds[i].contains(mouse))
            {
                selected = true;
                index = i; //sets index of shop sprite that is clicked
            }
        }

    }
}

void Gameplay::checkRemoverClick(RenderWindow& window) //function to check if remover sprite is clicked
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        Sprite sprites = shovel.getSprite();
        sf::FloatRect bounds;
        bounds = sprites.getGlobalBounds();
        if (bounds.contains(mouse)) { //if clicked, toggles removers selected bool
            shovel.setSelect(!shovel.getSelect());
        }
    }
}

void Gameplay::removePlant(RenderWindow& window) { //function to remove plant with remover
    if (shovel.getSelect()) //checks if remover is selected
    {
        int row = 0, col = 0;
        Event e;
        float xPos = 0, yPos = 0;
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        checkGrid(row, col, xPos, yPos, window, mouse); //checks which index of grid is clicked
        for (int i = 0; i < ptr.GetSize(); i++) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //if left button is clicked, removes plant with same coordinates if it exists
            {
                if (ptr[i]->GetPosition().GetX() == xPos && ptr[i]->GetPosition().GetY() == yPos - 30
                    && ptr[i]->CheckExistance() && FIELD_GAME_STATUS[row][col])
                {
                    ptr[i]->setExistence(false);
                    ptr.Destroy(i);
                    shovel.setSelect(false);
                }
            }
        }

    }
}
void Gameplay::dropToGrid(RenderWindow& window) //function to drop plant from shop to grid
{
    Sprite* sprites = shop.getSprite();
    Vector<Sprite> SelectedSprite = shop.getSelectedSprite(); 
    //sets shop sprites to greyed out ones to give effect of cooldown
    if (cooldown[0].getElapsedTime().asSeconds() >= 5) {
        sprites[0].setTexture(texture[0]);
        sprites[0].setTextureRect(sf::IntRect(0, 0, 114, 101));
        sprites[0].setPosition(-10, 50);
    }
    if (cooldown[1].getElapsedTime().asSeconds() >= 5) {
        sprites[1].setTexture(texture[1]);
        sprites[1].setTextureRect(sf::IntRect(0, 0, 85, 101));
    }
    if (cooldown[2].getElapsedTime().asSeconds() >= 5) {
        sprites[2].setTexture(texture[2]);
        sprites[2].setTextureRect(sf::IntRect(0, 0, 94, 95));
    }
    if (cooldown[3].getElapsedTime().asSeconds() >= 5) {
        sprites[3].setTexture(texture[3]);
        sprites[3].setTextureRect(sf::IntRect(0, 0, 75, 100));
    }
    if (cooldown[4].getElapsedTime().asSeconds() >= 5) {
        sprites[4].setTexture(texture[4]);
        sprites[4].setTextureRect(sf::IntRect(0, 0, 100, 101));
    }
    if (cooldown[5].getElapsedTime().asSeconds() >= 5) {
        sprites[5].setTexture(texture[5]);
        sprites[5].setTextureRect(sf::IntRect(0, 0, 120, 101));
    }
    if (cooldown[6].getElapsedTime().asSeconds() >= 5) {
        sprites[6].setTexture(texture[6]);
        sprites[6].setTextureRect(sf::IntRect(0, 0, 110, 101));
    }
    if (selected) //checks if shop sprite is clicked
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
                if (mouse.x > 270 && mouse.x < xRange && mouse.y > 80 && mouse.y <= 700)
                {
                    checkGrid(row, col, xPos, yPos, window, mouse);
                    // Check if the target grid cell is empty
                    if (!FIELD_GAME_STATUS[row][col])
                    {
                        bool spawned = false;

                        // Place the needed plant on the grid and checks if player has money to place plant
                        if (id[index] == "sunflower" && money >= 100 && cooldown[0].getElapsedTime().asSeconds() >= 5) {
                            ptr.push_back(new SunFlower(money));
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos - 30);
                            money -= ptr.back()->GetCost();
                            spawned = true;
                            cooldown[0].restart();
                            sprites[0].setTexture(texture[0]);
                            sprites[0].setTextureRect(sf::IntRect(110, 0, 114, 101));
                            sprites[0].setPosition(10, 50);
                        }

                        else if (id[index] == "peashooter" && money >= 100 && cooldown[1].getElapsedTime().asSeconds() >= 5) {
                            ptr.push_back(new PeaShooter);
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos - 30);
                            money -= ptr.back()->GetCost();
                            spawned = true;
                            cooldown[1].restart();
                            sprites[1].setTexture(texture[1]);
                            sprites[1].setTextureRect(sf::IntRect(87, 0, 85, 101));
                        }
                        else if (id[index] == "wallnut" && money >= 50 && cooldown[2].getElapsedTime().asSeconds() >= 5) {
                            ptr.push_back(new WallNut);
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos - 30);
                            money -= ptr.back()->GetCost();
                            spawned = true;
                            cooldown[2].restart();
                            sprites[2].setTexture(texture[2]);
                            sprites[2].setTextureRect(sf::IntRect(91, 0, 94, 95));
                        }
                        else if (id[index] == "repeater" && money >= 200 && cooldown[4].getElapsedTime().asSeconds() >= 5) {
                            ptr.push_back(new Repeater);
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos - 30);
                            money -= ptr.back()->GetCost();
                            spawned = true;
                            cooldown[4].restart();
                            sprites[4].setTexture(texture[4]);
                            sprites[4].setTextureRect(sf::IntRect(100, 0, 200, 84));
                        }
                        else if (id[index] == "cherrybomb" && money >= 150 && cooldown[3].getElapsedTime().asSeconds() >= 5) {
                            ptr.push_back(new CherryBomb);
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos - 30);
                            money -= ptr.back()->GetCost();
                            spawned = true;
                            cooldown[3].restart();
                            sprites[3].setTexture(texture[3]);
                            sprites[3].setTextureRect(sf::IntRect(75, 0, 160, 100));
                        }
                        else if (id[index] == "snowpea" && money >= 200 && cooldown[4].getElapsedTime().asSeconds() >= 5) {
                            ptr.push_back(new SnowPea);
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos - 30);
                            money -= ptr.back()->GetCost();
                            spawned = true;
                            cooldown[5].restart();
                            sprites[5].setTexture(texture[5]);
                            sprites[5].setTextureRect(sf::IntRect(120, 0, 240, 101));
                        }
                        else if (id[index] == "fume" && money >= 200 && cooldown[6].getElapsedTime().asSeconds() >= 5) {
                            ptr.push_back(new FumeShroom);
                            ptr.back()->setX(xPos);
                            ptr.back()->setY(yPos - 30);
                            money -= ptr.back()->GetCost();
                            spawned = true;
                            cooldown[6].restart();
                            sprites[6].setTexture(texture[6]);
                            sprites[6].setTextureRect(sf::IntRect(110, 0, 220, 101));
                        }
                        if (spawned)
                        {
                            if (ptr.back()->GetType() != "CherryBomb" && ptr.back()->GetType()!="Wallnut") {
                                FIELD_GAME_STATUS[row][col] = true;
                                ptr.back()->setI(row);
                                ptr.back()->setJ(col);
                            }
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
    for (int i = 0; i < ptr.GetSize(); ++i) {
        int temp=0;
        Plants* plant = ptr[i];
        //checks if attacking plants hit zombies
        if (plant->GetType() == "PeaShooter" || plant->GetType()=="Repeater" || plant->GetType() == "Snowpea" || plant->GetType()=="FumeShroom") {
            Shooter* shooter = (Shooter*)(plant);
            shooter->CheckBulletCollision(zptr, zombiesKilled);
        }
        if (plant->GetType() == "CherryBomb") {
            Explosive* shooter = (Explosive*)(plant);
            shooter->CheckExplosionCollision(zptr, zombiesKilled);
        } 
        if (plant->GetType() == "Wallnut") {
            WallNut* moveplant = (WallNut*)(plant);
            moveplant->CheckCollision(zptr, zombiesKilled);
        }
    }
}


void Gameplay::StartGamePlay(RenderWindow& window, int level, int& playerLives) { //starts game
    spawnZombies(level);//spawns zombies
    for (int i = 0; i < Guardians.GetSize(); ++i) {
        Guardians[i]->CheckCollision(this->zptr, zombiesKilled);
        if (Guardians[i]->GetExistance())
            window.draw(Guardians[i]->GetSprite());
    }
    if (!restart) {
        shop.setShop(level);
        restart = true;
    }
    if (endZombies == 0)
        endZombies = level * 5;
    shop.DrawShop(window); //draws available plants in shop
    this->checkShopClick(window); //checks shop click
    this->dropToGrid(window); //checks if plant is dropped to grid

    for (int i = 0; i < zptr.GetSize(); i++) {
        if (zptr[i]->getType() == "dancing") {
            zptr[i]->spawnBackupZombies(zptr, endZombies); //spawns backup zombies for dancing zombie
        }
        zptr[i]->action(window, ptr, this->FIELD_GAME_STATUS); //moves and draws all zombies
        this->CheckCollision();
        if (zptr[i]->GetPosition().GetX() <= 150 && zptr[i]->GetExistance()) //deducts player life if zombies reach home
        {
            zptr[i]->setExistence(false);
            zptr.Destroy(i);
            playerLives--;
            zombiesKilled++;
        }
    }
    for (int i = 0; i < ptr.GetSize(); i++)
    {
        if (ptr[i]->GetType() == "FumeShroom") {
            Plants* plant = ptr[i];
            RangedShooter* ranged = (RangedShooter*)ptr[i];
            if (ranged->CheckRange(this->zptr)) { //shoots bullets of fumeshroom
                ptr[i]->Action(window); //function that shoots bullets if attacking plant
            }
        }
        else {
            ptr[i]->Action(window);
        }
        if (ptr[i]->GetType() != "CherryBomb")
            ptr[i]->drawPlant(window);


    }
    sun.DrawSun(window, money);
    this->checkRemoverClick(window); //checks if remover clicked
    this->removePlant(window); //removes plants
    shovel.drawRemover(window);
    //currency text
    text.setString(to_string(money));
    window.draw(text);

}

void Gameplay::spawnZombies(int level)
{
    static int x = 0;
    initialTime = 5 - 2 * (level - 1); 
    timeInterval = initialTime / 1.5 + 3;
    //spawns zombies with delay and until max zombies for level are reached
    if (zombiesSpawned == 0)
    {
        if (clock.getElapsedTime().asSeconds() >= initialTime) {
            clock.restart();
            zombiesSpawned++;
        }
    }
    else if (zombiesSpawned==1){
        if (clock.getElapsedTime().asSeconds() >= initialTime)
        {

            zptr.push_back(new NormalZombie);
            zptr[zptr.GetSize() - 1]->setX(1200);
            zptr[zptr.GetSize() - 1]->setY(zptr[0]->getYPositions()[rand() % 5]);
            zombiesSpawned++;
            clock.restart();
        }
    }
    else if (zombiesSpawned < level * 5 + 1)
        if (clock.getElapsedTime().asSeconds() >= timeInterval)
        {
            if (level > 1)
            {
                srand((unsigned)time(0));
                int check = rand() % 4;

                if (check == 0)
                {
                    zptr.push_back(new NormalZombie);
                }
                else if (check == 1) {
                    zptr.push_back(new FootballZombie);
                }
                else if (check == 2) {
                    zptr.push_back(new DancingZombie);
                }
                else if (check == 3) {
                    zptr.push_back(new FlyingZombie);
                }
            }
            else
                zptr.push_back(new NormalZombie);

            zptr[zptr.GetSize() - 1]->setX(1250);
            zptr[zptr.GetSize() - 1]->setY(zptr[0]->getYPositions()[rand() % 5]);
            zombiesSpawned++;
            clock.restart();
        }
 
}

void Gameplay::resetGame()
{
    //resets game, destroying any plants and zombies
    for (int i = 0; i < zptr.GetSize(); ++i) {
        zptr[i]->setExistence(false);
    }
    for (int i = 0; i < ptr.GetSize(); i++)
    {
        ptr[i]->SetExistence(false);
    }
    for (int i = 0; i < gridRows; i++)
        for (int j = 0; j < gridCols; j++)
            FIELD_GAME_STATUS[i][j] = false;
    int yPositions[5];
    yPositions[0] = 97.5 - 40;
    yPositions[1] = 203 - 40;
    yPositions[2] = 309 - 40;
    yPositions[3] = 415 - 30;
    yPositions[4] = 521 - 20;
    for (int i = 0; i < 5; ++i) {
        Coordinates pos1(200 - (i * 3), (i * 120) + 95);
        Coordinates pos2(200 - (i * 3), yPositions[i]);
        Guardians[i]->SetSpritePosGuard(pos1);
        Guardians[i]->SetSprtePos(pos1);
        Guardians[i]->SetCoordinates(pos2);
        Guardians[i]->setExistence(true);
        Guardians[i]->setDestroyed(false);
    }
    zombiesKilled = 0;
    clock.restart();
    restart = false;
    sun.setExists(false);
    for (int i = 0; i < 7; ++i) {
        cooldown[i].restart();
    }
    endZombies = 0;
    money = 1500;
}
bool Gameplay::CheckTransitionCondition(int levels) {

    if (zombiesKilled == endZombies) //checks if level is to be changed
        return true;
    return false;
}

bool Gameplay::checkEnd(int levels, int playerLives)
{
    if (levels < 6 && playerLives>0) //checks game ending condition
        return false;
    return true;
}