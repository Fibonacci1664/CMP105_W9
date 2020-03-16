#pragma once

#include <SFML\Graphics\RenderWindow.hpp>
#include "Spike.h"
#include <iostream>

class SpikeManager
{
public:
	SpikeManager();
	~SpikeManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void addSpike();
	void render(sf::RenderWindow* window);
	int getOnScreenCount();

private:
	std::vector<Spike> spikes;
	sf::Vector2f spawnPoint;
	sf::Texture spikeTexture;

	int onScreenCount = 0;

	void initTextures();
};

