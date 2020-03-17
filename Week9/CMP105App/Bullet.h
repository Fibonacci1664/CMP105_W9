#pragma once
#include "Framework/GameObject.h"
#include<iostream>

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();

	void handleInput(float dt) override;
	void update(float dt) override;

private:


};

