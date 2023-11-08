#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Canon
{
public:

	sf::Mouse mouse;
	float init_angle;
	
	Canon();

	void update(sf::Shape* shape, sf::RenderWindow* window);

};

