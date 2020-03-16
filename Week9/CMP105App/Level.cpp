#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	delay = 0;

	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	textBox.setSize(sf::Vector2f(400, 100));
	textBox.setOrigin(textBox.getSize().x / 2, textBox.getSize().y / 2);
	textBox.setFillColor(sf::Color(126, 126, 126, 126));
	textBox.setPosition(sf::Vector2f(window->getSize().x / 2, 75));

	text.setFont(font);
	text.setString("Spikes on screen : " + std::to_string(spikeMan.getOnScreenCount()));
	text.setCharacterSize(16);
	text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
	text.setPosition(sf::Vector2f(textBox.getPosition().x, textBox.getPosition().y - 30));
	text.setFillColor(sf::Color::Red);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	delay += dt;

	if (input->isKeyDown(sf::Keyboard::Space) && delay > 0.2f)
	{
		bm.spawn();
		delay = 0;
	}

	if(input->isKeyDown(sf::Keyboard::D) && delay > 0.2)
	{
		spikeMan.spawn();
		delay = 0;
	}
}

// Update game objects
void Level::update(float dt)
{
	bm.update(dt);
	spikeMan.update(dt);
	text.setString("Spikes on screen : " + std::to_string(spikeMan.getOnScreenCount()));
}

// Render level
void Level::render()
{
	beginDraw();
	bm.render(window);
	spikeMan.render(window);
	window->draw(textBox);
	window->draw(text);
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