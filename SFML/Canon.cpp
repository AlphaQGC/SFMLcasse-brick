#include "Canon.h"
#include <SFML/Graphics.hpp>


Canon::Canon() {

}

void Canon::update(sf::Shape* shape, sf::RenderWindow* window) {

	sf::Vector2i mouse_pos = mouse.getPosition(*window);
	sf::Vector2f canon_origin = shape->getPosition();

	if (window->getSize().x < mouse_pos.x or mouse_pos.x < 0 and 0 > mouse_pos.y > window->getSize().y) {
		return;
	}

	float opposite = mouse_pos.x - canon_origin.x;
	float near = mouse_pos.y - canon_origin.y;

	// 200 intialement mis a 100 voir si problème
	float angle = -atan(opposite / near) * 200 / 3.14;

	shape->rotate(angle - init_angle);
	init_angle = angle;

}
