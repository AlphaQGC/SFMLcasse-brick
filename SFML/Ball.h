#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
public:

	Ball(int x, int y, int size1, const char* img);

	int windowCollided(sf::RenderWindow* window);

	bool ballOutsideWindow(sf::RenderWindow* window);

	float invertDirection(float speed);

};

