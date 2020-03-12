#include "Ball.h"

Ball::Ball()
{

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