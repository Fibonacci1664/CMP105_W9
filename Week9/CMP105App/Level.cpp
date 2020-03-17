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

	player.setSize(sf::Vector2f(100, 100));
	player.setFillColor(sf::Color::Green);
	player.setOutlineColor(sf::Color::Black);
	player.setOutlineThickness(1.0f);
	player.setPosition(sf::Vector2f(200, 400));

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	isMoving = false;
	delay += dt;
	sf::Vector2f vel = sf::Vector2f(100, 100);

	// Spawn beach balls.
	if (input->isKeyDown(sf::Keyboard::Space) && delay > 0.2f)
	{
		bm.spawn();
		delay = 0;
	}

	// Drop ice spikes.
	if(input->isKeyDown(sf::Keyboard::D) && delay > 0.2)
	{
		spikeMan.spawn();
		delay = 0;
	}

	// Move right.
	if (input->isKeyDown(sf::Keyboard::L))
	{
		player.setPosition(sf::Vector2f(player.getPosition().x + (vel.x * dt), player.getPosition().y));
		isMoving = true;
	}

	// Move left.
	if (input->isKeyDown(sf::Keyboard::J))
	{
		player.setPosition(sf::Vector2f(player.getPosition().x - (vel.x * dt), player.getPosition().y));
		isMoving = true;
	}

	// Move up.
	if (input->isKeyDown(sf::Keyboard::I))
	{
		player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y - (vel.y * dt)));
		isMoving = true;
	}

	// Move down.
	if (input->isKeyDown(sf::Keyboard::K))
	{
		player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y + (vel.y * dt)));
		isMoving = true;
	}

	// Fire bullet.
	if (input->isKeyDown(sf::Keyboard::F) && !isMoving && delay > 0.2)
	{
		int mouseX = input->getMouseX();
		int mouseY = input->getMouseY();

		bullMan.spawn(&player, mouseX, mouseY, dt);
		delay = 0;
	}
}

// Update game objects
void Level::update(float dt)
{
	bullMan.update(dt);
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
	bullMan.render(window);
	window->draw(textBox);
	window->draw(text);
	window->draw(player);
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