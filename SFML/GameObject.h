#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:

	float x, y, width, height, radius;

	sf::Shape* shape;

	GameObject(int x, int y, int size1, int size2);
	GameObject(int x, int y, int radius);

	void moveDown(float time);
	void moveUp(float time);
	void moveLeft(float time);
	void moveRight(float time);

	void rotate(int degree);

	bool hasCollided(sf::Shape* other_shape, int other_width, int other_heigth);

};

