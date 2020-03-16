#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include "Ball.h"
#include <iostream>

class BallManager
{
public:
	BallManager();
	~BallManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void addBall();
	void render(sf::RenderWindow* window);
	int getBallVectorSize();

private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture ballTexture;

	int onScreenCount = 0;

	void initTextures();
};

