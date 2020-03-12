#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "BallManager.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

	bool getSpawned();
	void setSpawned(bool spawned);

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	bool spawned;
	float delay;

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	BallManager bm;
};