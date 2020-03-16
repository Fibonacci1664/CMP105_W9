#pragma once

#include "Framework/GameObject.h"
#include <iostream>


class Spike : public GameObject
{
public:
	Spike();
	~Spike();

	void handleInput(float dt) override;
	void update(float dt) override;

private:
	
};

