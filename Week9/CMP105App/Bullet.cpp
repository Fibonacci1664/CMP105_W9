#include "Bullet.h"


Bullet::Bullet()
{
	std::cout << "Bullet object created\n";
}

Bullet::~Bullet()
{
	std::cout << "Bullet object destroyed\n";
}

void Bullet::handleInput(float dt)
{

}

void Bullet::update(float dt)
{
	move(velocity * dt);
}