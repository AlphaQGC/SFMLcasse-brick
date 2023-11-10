#include "GameObject.h"
#include <SFML/Graphics.hpp>

GameObject::GameObject(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	speed = 500;
	speedX = 0;
	speedY = 0;

	shape = new sf::RectangleShape(sf::Vector2f(width, height));
	shape->setPosition(x, y);
	shape->setFillColor(sf::Color::Red);
}


GameObject::GameObject(int x, int y, int radius) {
	this->x = x;
	this->y = y;
	this->radius = radius;
	speed = 500;
	speedX = 0;
	speedY = 0;

	shape = new sf::CircleShape(radius);
	shape->setPosition(x, y);
	shape->setFillColor(sf::Color::Blue);
}

void GameObject::moveX(float time) {
	x += time * speedX;
	shape->setPosition(x, y);
}

void GameObject::moveY(float time) {
	y += time * speedY;
	shape->setPosition(x, y);
}

void GameObject::moveDirection(float time, float vect_x, float vect_y) {
	x += vect_x * speed * time;
	y += vect_y * speed * time;
	shape->setPosition(x,y);
}

void GameObject::setPositionObject(int x, int y) {
	shape->setPosition(x, y);
}

void GameObject::setOriginToCenter() {
	shape->setOrigin(sf::Vector2f(shape->getLocalBounds().width, shape->getLocalBounds().height) / 2.f);
}

void GameObject::rotate(int degree) {
	shape->rotate(degree);
}

bool GameObject::hasCollided(sf::Shape* other_shape, int other_width, int other_height) {
	sf::Vector2f position_1 = shape->getPosition();
	sf::Vector2f position_2 = other_shape->getPosition();
	if(position_2.x < position_1.x + width && position_2.x + other_width > position_1.x && position_2.y < position_1.y + height && position_2.y + other_height > position_1.y) {
		return true;
	} 
	return false;
}

bool GameObject::checkCollisionX(sf::Shape* brick, int brick_width) {
	float ballRight = shape->getPosition().x + radius * 2;
	float ballLeft = shape->getPosition().x;
	float brickRight = brick->getPosition().x + brick_width;
	float brickLeft = brick->getPosition().x;

	return (ballLeft >= brickLeft and ballLeft <= brickRight) or (ballRight >= brickLeft and ballRight <= brickRight);
}

bool GameObject::checkCollisionY(sf::Shape* brick, int brick_height) {
	float ballBottom = shape->getPosition().y + radius * 2;
	float ballTop = shape->getPosition().y;
	float brickBottom = brick->getPosition().y + brick_height;
	float brickTop = brick->getPosition().y;

	return (ballTop >= brickTop and ballTop <= brickBottom) or (ballBottom >= brickTop and ballBottom <= brickBottom);
}


