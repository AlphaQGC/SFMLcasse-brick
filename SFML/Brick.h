#pragma once
#include "GameObject.h"

class Brick : public GameObject
{
public:

	int health;

	Brick(int x, int y, int size1, int size2);

	void update();

	bool dropBonus();
};


