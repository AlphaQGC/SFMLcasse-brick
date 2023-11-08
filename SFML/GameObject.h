#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:

	float x, y, width, height, radius;
	float speedX, speedY;

	sf::Shape* shape;

	GameObject(int x, int y, int size1, int size2);
	GameObject(int x, int y, int radius);

	void moveY(float time);
	void moveX(float time);

	void setOriginToCenter();
	void rotate(int degree);

	bool hasCollided(sf::Shape* other_shape, int other_width, int other_heigth);

};

