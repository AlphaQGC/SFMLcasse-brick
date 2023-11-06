#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{

public :
	
	int x, y, size1, size2, type;
	GameObject(int x, int y, int size1, int size2,int type);
	sf::Shape* shape;


};

