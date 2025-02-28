#include "BallManager.h"

BallManager::BallManager()
{
	spawnPoint = sf::Vector2f(350, 250);
	initTextures();

	for (int i = 0; i < 10; ++i)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&ballTexture);
		balls[i].setSize(sf::Vector2f(60, 60));
	}
}

BallManager::~BallManager()
{
	std::cout << "Destroyed a ball manager object!\n";
}

void BallManager::spawn()
{
	std::cout << "Balls on display : " << onScreenCount << '\n';

	for (int i = 0; i < balls.size(); ++i)
	{
		int randXVel = (rand() % 200) - 100;
		int randYVel = (rand() % 200) - 100;

		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			++onScreenCount;
			balls[i].setVelocity(randXVel, randYVel);
			balls[i].setPosition(spawnPoint);
			return;
		}
	}

	addBall();
}

void BallManager::update(float dt)
{
	// Call update on all ALIVE balls.
	for (int i = 0; i < balls.size(); ++i)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}

		deathCheck();
	}
}

void BallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); ++i)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().x < -100)
			{
				balls[i].setAlive(false);
				--onScreenCount;
			}

			if (balls[i].getPosition().x > 800)
			{
				balls[i].setAlive(false);
				--onScreenCount;
			}

			if (balls[i].getPosition().y < -100)
			{
				balls[i].setAlive(false);
				--onScreenCount;
			}

			if (balls[i].getPosition().y > 600)
			{
				balls[i].setAlive(false);
				--onScreenCount;
			}
		}	
	}
}

void BallManager::addBall()
{
	for (int i = 0; i < balls.size(); ++i)
	{
		if ((i = balls.size()) - 1)
		{
			std::cout << "Added ball number : " << balls.size() << '\n';
			balls.push_back(Ball());
			balls[i].setAlive(false);
			balls[i].setTexture(&ballTexture);
			balls[i].setSize(sf::Vector2f(60, 60));
			break;
		}	
	}
}

void BallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); ++i)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}

void BallManager::initTextures()
{
	if (!ballTexture.loadFromFile("gfx/Beach_Ball.png"))
	{
		std::cout << "Could not load beach ball texture!\n";
	}
}
