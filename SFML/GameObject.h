#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:

	int x, y, width, height, radius;

	sf::Shape* shape;

	GameObject(int x, int y, int size1, int size2);
	GameObject(int x, int y, int radius);

};

