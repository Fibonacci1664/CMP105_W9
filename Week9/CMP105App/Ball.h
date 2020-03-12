#pragma once
#include"Framework\GameObject.h"
#include <iostream>

class Ball : public GameObject
{
public:
	Ball();
	~Ball();

	void handleInput(float dt) override;
	void update(float dt) override;

private:


};

