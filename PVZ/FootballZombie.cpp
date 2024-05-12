#include "FootballZombie.h"

FootballZombie::FootballZombie() {
	srand((unsigned)time(0));
	rand();
	this->exists = true;
	this->speed = 1.2;
	this->damage = 1;
	this->lives = 16;
	this->texture.loadFromFile("../Images/FBZ.png");
	this->animate = new Animation;
	this->animate->SetSheet(0.125, 3,texture, 5, 5);
	this->animate->ChangeScale(2.3, 2.3);
	this->type = "football";
}

void FootballZombie::moveZombie(Vector<Plants*>& ptr, bool** set)
{
	static Clock clock;
	srand((unsigned)time(0));
	int random = rand() % 5;
	if (clock.getElapsedTime().asSeconds() >= 5)
	{
		//check y position
		int y = 0;
		for (int i = 0; i < 5; i++)
			if (this->yPositions[i] == this->position.GetY())
			{
				y = i;
				break;
			}
		if (random == 0 && y > 0) //moves zombie into below row
		{
			this->position.SetY(this->yPositions[y - 1]);
			clock.restart();
		}
		else if (random == 1 && y < 4) //moves zombie into above row
		{
			this->position.SetY(this->yPositions[y + 1]);
			clock.restart();
		}
	}
	if (!checkIfPlantAhead(ptr)) //moves zombie if no plant infront of it
	{
		if (position.GetX() > 0)
			this->position.SetX(position.GetX() - speed);
	}
	else
	{
		doDamage(ptr, set);
	}
}

void FootballZombie::drawZombie(sf::RenderWindow& window) {
	if (exists) {
		this->animate->Update();
		this->animate->DrawAnimation(window,this->position);
	}

}