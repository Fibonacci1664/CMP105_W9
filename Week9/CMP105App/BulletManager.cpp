#include "BulletManager.h"

BulletManager::BulletManager()
{
	std::cout << "Bullet manager created\n";

	initTextures();

	for (int i = 0; i < 50; ++i)
	{
		bullets.push_back(Bullet());
		bullets[i].setAlive(false);
		bullets[i].setSize(sf::Vector2f(20, 20));
		bullets[i].setTexture(&bulletTexture);
	}
}

BulletManager::~BulletManager()
{
	std::cout << "Bullet manager destroyed!\n";
}

void BulletManager::spawn(sf::RectangleShape* l_player, int l_mouseX, int l_mouseY, float dt)
{
	int xSpawn = l_player->getPosition().x + l_player->getSize().x;
	int ySpawn = l_player->getPosition().y + (l_player->getSize().y / 2.0f);
	sf::Vector2f spawnPoint = sf::Vector2f(xSpawn, ySpawn);

	sf::Vector2f mousePos = sf::Vector2f(l_mouseX, l_mouseY);
	sf::Vector2f dir = mousePos - spawnPoint;

	// Loop over checking for dead obejcts, when one is found bring it to life and return.
	for (int i = 0; i < bullets.size(); ++i)
	{
		if (!bullets[i].isAlive())
		{
			bullets[i].setAlive(true);
			bullets[i].setPosition(spawnPoint);
			bullets[i].setVelocity(dir);
			return;
		}
	}
}

void BulletManager::update(float dt)
{
	// Call update on all ALIVE spikes.
	for (int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].update(dt);
		}

		deathCheck();
	}
}

void BulletManager::deathCheck()
{
	/*
	 * Loop over all ALIVE spikes and check them against certain bounds, if they are
	 * outwith those bounds then kill them.
	 */
	for (int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].isAlive())
		{
			if (bullets[i].getPosition().x > 1200)
			{
				bullets[i].setAlive(false);
			}
		}
	}
}

void BulletManager::addSpike()
{

}

void BulletManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].isAlive())
		{
			window->draw(bullets[i]);
		}
	}
}

void BulletManager::initTextures()
{
	if (!bulletTexture.loadFromFile("gfx/bullet.png"))
	{
		std::cout << "Error loading bullet texture!\n";
	}
}