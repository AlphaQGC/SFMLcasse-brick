#include "Canon.h"
#include <SFML/Graphics.hpp>


Canon::Canon() {

}

void Canon::getVect(sf::Shape* shape, sf::RenderWindow* window, sf::Shape* other_shape) {

	sf::Vector2f other_pos = other_shape->getPosition();
	sf::Vector2f canon_origin = shape->getPosition();

	float opposite = other_pos.x - canon_origin.x;
	float near = other_pos.y - canon_origin.y;

	vect_x = opposite;
	vect_y = near;

}
