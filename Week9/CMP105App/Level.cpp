#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	spawned = false;
	delay = 0;

	// initialise game objects
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	delay += dt;

	if (input->isKeyDown(sf::Keyboard::Space) && delay > 2)
	{
		spawned = true;
		bm.spawn();
		delay = 0;
	}

	//std::cout << delay << '\n';
}

// Update game objects
void Level::update(float dt)
{
	bm.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	bm.render(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}

bool Level::getSpawned()
{
	return spawned;
}

void Level::setSpawned(bool hasSpawned)
{
	spawned = hasSpawned;
}