#include "FootballZombie.h"

FootballZombie::FootballZombie() {
	srand((unsigned)time(0));
	rand();
	this->exists = true;
	this->speed = 3;
	this->damage = 0.5;
	this->lives = 4;
	this->texture.loadFromFile("../Images/FBZ.png");
	this->animate = new Animation;
	this->animate->SetSheet(0.125, 6, texture, 8, 1);
	this->animate->ChangeScale(1.25, 1.25);
	//Coordinates pos(700, 350);
	//this->position = pos;
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
		if (random == 0 && y > 0)
		{
			cout << "up" << endl;
			this->position.SetY(this->yPositions[y - 1]);
			clock.restart();
		}
		else if (random == 1 && y < 4)
		{
			cout << "down" << endl;
			this->position.SetY(this->yPositions[y + 1]);
			clock.restart();
		}
	}
	if (!checkIfPlantAhead(ptr))
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