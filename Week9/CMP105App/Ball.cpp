#include "Ball.h"

Ball::Ball()
{
	std::cout << "Ball created.\n";
}

Ball::~Ball()
{
	std::cout << "Destroyed a ball object!\n";
}

void Ball::handleInput(float dt)
{

}

void Ball::update(float dt)
{
	move(velocity * dt);
}