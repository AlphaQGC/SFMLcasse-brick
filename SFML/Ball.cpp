#include "Ball.h"

Ball::Ball(int x, int y, int size1, int size2) : GameObject(x, y, size1, size2) {
	
}

Ball::Ball(int x, int y, int size1) : GameObject(x, y, size1) {

}


bool Ball::windowCollidedY(sf::RenderWindow* window) {
	sf::Vector2f position_1 = shape->getPosition();
	if (position_1.y < 0) {
		return true;
	} else {
		return false;
	}
}

bool Ball::windowCollidedX(sf::RenderWindow* window) {
	sf::Vector2f position_1 = shape->getPosition();
	if (window->getSize().x < position_1.x + radius * 2 || position_1.x < 0) {
		return true;
	} else {
		return false;
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
