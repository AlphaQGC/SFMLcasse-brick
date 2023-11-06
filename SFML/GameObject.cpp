#include "GameObject.h"
#include <SFML/Graphics.hpp>

GameObject::GameObject(int x, int y, int size1, int size2, int type) {
    this->x = x;
    this->y = y;
    this->size1 = size1;
    this->size2 = size2;
    if (type == 1) {
        shape = new sf::RectangleShape(sf::Vector2f(size1, size2));
        shape->setPosition(x, y);
        shape->setFillColor(sf::Color::Red);
    }
    else if (type == 2) {
        shape = new sf::CircleShape(size1);
        shape->setPosition(x, y);
        shape->setFillColor(sf::Color::Blue);
    }
}
