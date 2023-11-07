#include "GameObject.h"
#include <SFML/Graphics.hpp>

GameObject::GameObject(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	shape = new sf::RectangleShape(sf::Vector2f(width, height));
	shape->setPosition(x, y);
	shape->setFillColor(sf::Color::Red);
}


GameObject::GameObject(int x, int y, int radius) {
	this->x = x;
	this->y = y;
	this->radius = radius;

	shape = new sf::CircleShape(radius);
	shape->setPosition(x, y);
	shape->setFillColor(sf::Color::Blue);
}

void GameObject::moveDown(float time) {
	y += time * 20.f;
	shape->setPosition(x, y);
}

void GameObject::moveUp(float time) {
	y -= time * 40.f;
	shape->setPosition(x, y);
}

void GameObject::moveLeft(float time) {
	x -= time * 10.f;
	shape->setPosition(x, y);
}

void GameObject::moveRight(float time) {
	x += time * 10.f;
	shape->setPosition(x, y);
}

void GameObject::rotate(int degree) {
	shape->rotate(degree);
}

bool GameObject::hasCollided(sf::Shape* other_shape, int other_width, int other_height) {
	sf::Vector2f position_1 = shape->getPosition();
	sf::Vector2f position_2 = other_shape->getPosition();
	if(position_2.x < position_1.x + width && position_2.x + other_width > position_1.x && position_2.y < position_1.y + height && position_2.y + other_height > position_1.y) {
		return true;
	} else {
		return false;
	}
}