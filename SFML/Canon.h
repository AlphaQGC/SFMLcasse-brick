#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Canon
{
public:

	sf::Mouse mouse;
	float init_angle;

	float vect_x, vect_y;
	
	Canon();

	void update(sf::Shape* shape, sf::RenderWindow* window);

};

