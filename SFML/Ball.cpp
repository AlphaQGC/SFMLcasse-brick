#include "Ball.h"

Ball::Ball(int x, int y, int size1, const char* img) : GameObject(x, y, size1, img) {

}


int Ball::windowCollided(sf::RenderWindow* window) {
	sf::Vector2f position_1 = shape->getPosition();
	if (position_1.y < 0) {
		return 1;
	} else if (window->getSize().x < (position_1.x + radius * 2)) {
		return 2;
	} else if (position_1.x < 0) {
		return 3;
	} else {
		return 0;
	}
}

bool Ball::ballOutsideWindow(sf::RenderWindow* window) {
	sf::Vector2f position_1 = shape->getPosition();
	if (window->getSize().y < position_1.y + radius) {
		return true;
	}
	else {
		return false;
	}
}

float Ball::invertDirection(float speed) {
	return speed = -speed;
}
