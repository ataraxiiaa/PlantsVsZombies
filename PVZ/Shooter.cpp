#include "Shooter.h"

Shooter::Shooter(int totalBullets) // Will change depending on plant
{
    bullet = new Pea[totalBullets]; // Array of bullets 

}
void Shooter::Fire(sf::RenderWindow& window,Coordinates PlantCoords,int index) // Fire function
{
    // Check if enough time has passed to allow firing
    if (clock.getElapsedTime().asSeconds() >= 3 && !bullet[index].ShowFire())
    {
        // Restart the clock for the next firing interval
        clock.restart();

        // Fire the bullet
        bullet[index].SetFire(true);
        bullet[index].SetPosition(PlantCoords);
    }

    // Move the bullet if it's fired
    if (bullet[index].ShowFire())
    {
        // Update bullet position based on its speed
        Coordinates pos = bullet[index].GetPosition();
        pos.SetX(pos.GetX() + bullet[index].GetSpeed());
        bullet[index].SetPosition(pos);

        // Check if the bullet has gone off the screen
        if (bullet[index].GetPosition().GetX() >= 1200)
        {
            bullet[index].SetFire(false); // Hide the bullet
        }
    }

    // Always draw the bullet (whether fired or not)
    bullet[index].DrawPea(window);

}

