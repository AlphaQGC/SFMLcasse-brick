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
	shape->setPosition(x, y += time * 1);
}

void GameObject::moveUp(float time) {
	shape->setPosition(x, y -= time * 1);
}

void GameObject::moveLeft(float time) {
	shape->setPosition(x -= time * 1, y);
}

void GameObject::moveRight(float time) {
	shape->setPosition(x += time * 1, y);
}

void GameObject::rotate(int degree) {
	shape->rotate(degree);
}

//bool GameObject::hasCollided(sf::Shape* other_shape) {
	
//}

// collide :
// 
// if xmin green > xmin red && xmin green < max red || if xmax green > xmin red && xmax green < max red 
// && ymin green > ymin red && ymin green < yax red || if ymax green > ymin red && ymax green < ymax red 
// 
// toujours faire la vérification sur le plus petit rectangle 