#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "BallManager.h"
#include "SpikeManager.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	float delay;

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::RectangleShape textBox;
	sf::Font font;
	sf::Text text;

	BallManager bm;
	SpikeManager spikeMan;
};