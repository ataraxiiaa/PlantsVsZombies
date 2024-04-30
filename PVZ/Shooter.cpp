#include "Shooter.h"

Shooter::Shooter()
{
	
}
void Shooter::Fire(sf::RenderWindow& window,Coordinates PlantCoords)
{
    // Check if enough time has passed to allow firing
    if (clock.getElapsedTime().asSeconds() >= 3 && !bullet.ShowFire())
    {
        // Restart the clock for the next firing interval
        clock.restart();

        // Fire the bullet
        bullet.SetFire(true);
        bullet.SetPosition(PlantCoords);
    }

    // Move the bullet if it's fired
    if (bullet.ShowFire())
    {
        // Update bullet position based on its speed
        Coordinates pos = bullet.GetPosition();
        pos.SetX(pos.GetX() + bullet.GetSpeed());
        bullet.SetPosition(pos);

        // Check if the bullet has gone off the screen
        if (bullet.GetPosition().GetX() >= 1200)
        {
            bullet.SetFire(false); // Hide the bullet
        }
    }

    // Always draw the bullet (whether fired or not)
    bullet.DrawPea(window);
}

