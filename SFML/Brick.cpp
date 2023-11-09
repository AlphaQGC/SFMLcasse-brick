#include "Brick.h"

Brick::Brick(int x, int y, int size1, int size2) : GameObject(x, y, size1, size2) {

	int health = 1;

}

void Brick::update() {
	health--;
}
