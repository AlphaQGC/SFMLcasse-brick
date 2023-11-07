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

void GameObject::moveDown() {
	shape->setPosition(x, y += 2);
}

void GameObject::moveUp() {
	shape->setPosition(x, y -= 2);
}

void GameObject::moveLeft() {
	shape->setPosition(x -= 2, y);
}

void GameObject::moveRight() {
	shape->setPosition(x += 2, y);
}