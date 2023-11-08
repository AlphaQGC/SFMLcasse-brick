#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
public:

	Ball(int x, int y, int size1, int size2);

	bool windowCollidedX(sf::RenderWindow* window);
	bool windowCollidedY(sf::RenderWindow* window);

	float invertDirection(float speed);

};

