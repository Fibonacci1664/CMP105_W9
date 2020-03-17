#pragma once

#include <SFML\Graphics\RenderWindow.hpp>
#include "Spike.h"
#include <iostream>
#include "Bullet.h"

class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void spawn(sf::RectangleShape* l_player, int l_mouseX, int l_mouseY, float dt);
	void update(float dt);
	void deathCheck();
	void addSpike();
	void render(sf::RenderWindow* window);

private:
	std::vector<Bullet> bullets;
	sf::Vector2f spawnPoint;
	sf::Texture bulletTexture;

	void initTextures();
};

