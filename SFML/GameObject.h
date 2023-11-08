#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:

	float x, y, width, height, radius;
	float speed, speedX, speedY;

	sf::Shape* shape;

	GameObject(int x, int y, int size1, int size2);
	GameObject(int x, int y, int radius);

	void moveY(float time);
	void moveX(float time);

	void moveDirection(float time, float vect_x, float vect_y);

	void setPositionObject(int x, int y);
	void setOriginToCenter();
	void rotate(int degree);

	bool hasCollided(sf::Shape* other_shape, int other_width, int other_heigth);

};

