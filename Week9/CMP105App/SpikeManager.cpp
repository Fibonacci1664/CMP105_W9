#include "SpikeManager.h"

SpikeManager::SpikeManager()
{
	std::cout << "Spike manager created\n";

	// Initialize the texture.
	initTextures();

	// Create 40 dead objects.
	for (int i = 0; i < 40; ++i)
	{
		spikes.push_back(Spike());
		spikes[i].setAlive(false);
		spikes[i].setTexture(&spikeTexture);
		spikes[i].setSize(sf::Vector2f(60, 60));
	}
}

SpikeManager::~SpikeManager()
{
	std::cout << "Spike manager destoryed\n";
}

void SpikeManager::spawn()
{
	int randXSpawn = rand() % 1080 + 60;
	int randYVel = (rand() % -400) + 200;

	spawnPoint = sf::Vector2f(randXSpawn, 20);

	// Loop over checking for dead obejcts, when one is found bring it to life and return.
	for (int i = 0; i < spikes.size(); ++i)
	{
		if (!spikes[i].isAlive())
		{
			spikes[i].setAlive(true);
			++onScreenCount;
			spikes[i].setPosition(spawnPoint);
			spikes[i].setVelocity(0, randYVel);		
			return;
		}
	}

}

void SpikeManager::update(float dt)
{
	// Call update on all ALIVE spikes.
	for (int i = 0; i < spikes.size(); ++i)
	{
		if (spikes[i].isAlive())
		{
			spikes[i].update(dt);
		}

		deathCheck();
	}
}

void SpikeManager::deathCheck()
{
	/*
	 * Loop over all ALIVE spikes and check them against certain bounds, if they are
	 * outwith those bounds then kill them.
	 */
	for (int i = 0; i < spikes.size(); ++i)
	{
		if (spikes[i].isAlive())
		{
			if (spikes[i].getPosition().y > 675)
			{
				spikes[i].setAlive(false);
				--onScreenCount;
			}
		}
	}
}

void SpikeManager::addSpike()
{

}

void SpikeManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < spikes.size(); ++i)
	{
		if (spikes[i].isAlive())
		{
			window->draw(spikes[i]);
		}
	}
}

void SpikeManager::initTextures()
{
	if (!spikeTexture.loadFromFile("gfx/spike.png"))
	{
		std::cout << "Could not load spike texture!\n";
	}
}

int SpikeManager::getOnScreenCount()
{
	return onScreenCount;
}