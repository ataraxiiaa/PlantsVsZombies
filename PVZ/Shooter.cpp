#include "Shooter.h"

Shooter::Shooter(int totalBullets) // Will change depending on plant
{
    bullet = new Pea[totalBullets]; // Array of bullets 
    this->totalBullets = totalBullets;
    delay = 2.0f;
}
void Shooter::Fire(sf::RenderWindow& window,Coordinates PlantCoords,int index) // Fire function
{
    for (int i = 0; i < totalBullets; ++i) {
        float bulletDelay = delay * i; // Used to ensure theres a delay if a plant is a repeater
        // Check if enough time has passed to allow firing
        if (clock.getElapsedTime().asSeconds() >= bulletDelay && !bullet[i].ShowFire())
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
            if (bullet[i].GetPosition().GetX() >= 1200)
            {
                bullet[i].SetFire(false); // Hide the bullet
            }
        }
        // Always draw the bullet (whether fired or not)
        bullet[i].DrawPea(window);
    }

}

