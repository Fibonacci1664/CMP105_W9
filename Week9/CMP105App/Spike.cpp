#include "Spike.h"

Spike::Spike()
{
	std::cout << "Spike created\n";
}

Spike::~Spike()
{
	std::cout << "Spike destroyed\n";
}

void Spike::handleInput(float dt)
{

}

void Spike::update(float dt)
{
	move(velocity * dt);
}
