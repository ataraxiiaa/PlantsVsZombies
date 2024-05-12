#include "Shooter.h"

Shooter::Shooter(int totalBullets) // Will change depending on plant
{
    bullet = new Pea[totalBullets]; // Array of bullets 
    this->totalBullets = totalBullets;
    delay = 2.0f;
    this->damage = 0;
    this->shooterType = true;
}
void Shooter::Fire(sf::RenderWindow& window,Coordinates PlantCoords,int index) // Fire function
{
    if (this->exists) {
        for (int i = 0; i < totalBullets; ++i) {
            float bulletDelay = delay * i; // Used to ensure theres a delay if a plant is a repeater
            // Check if enough time has passed to allow firing
            if (clock.getElapsedTime().asSeconds() >= bulletDelay && !bullet[i].ShowFire() && this->exists)
            {
                // Restart the clock for the next firing interval
                clock.restart();
                // Fire the bullet
                bullet[i].SetFire(true);
                bullet[i].SetPosition(PlantCoords);
            }

            // Move the bullet if it's fired
            if (bullet[i].ShowFire())
            {
                // Update bullet position based on its speed
                Coordinates pos = bullet[i].GetPosition();
                pos.SetX(pos.GetX() + bullet[i].GetSpeed());
                bullet[i].SetPosition(pos);

                // Check if the bullet has gone off the screen
                if (bullet[i].GetPosition().GetX() >= 1150)
                {
                    bullet[i].SetFire(false); // Hide the bullet
                }
            }
            // Always draw the bullet (whether fired or not)
            bullet[i].DrawPea(window);
        }
    }

}
// CHecking collision with bullet of zombie
void Shooter::CheckBulletCollision(Vector<Zombie*>& Zombie, int& killed) {
    for (int i = 0; i < totalBullets; ++i) {
        for (int j = 0; j < Zombie.GetSize(); ++j) {
            if (bullet[i].GetPosition().GetX() - Zombie[j]->GetPosition().GetX() >= -10 &&
                bullet[i].GetPosition().GetX() - Zombie[j]->GetPosition().GetX() <= 10 &&
                bullet[i].GetPosition().GetY() - Zombie[j]->GetPosition().GetY() >= -60 &&
                bullet[i].GetPosition().GetY() - Zombie[j]->GetPosition().GetY() <= 60 &&
                Zombie[j]->GetExistance() && bullet[i].ShowFire()
                )
            {
                if (Zombie[j]->getLives() > 0) {
                    Zombie[j]->setLives(Zombie[j]->getLives() - getDamage());
                    if (this->Type == "Snowpea")
                        Zombie[i]->slowDown();
                }
                else
                {
                    killed++;
                    Zombie[j]->setExists(false);
                    Zombie.Destroy(j);
                }
                if(this->Type != "FumeShroom")
                    bullet[i].SetFire(false);
                return;
            }
        }
    }
}
