#include "Brick.h"

Brick::Brick(int x, int y, int size1, int size2) : GameObject(x, y, size1, size2) {

	int health = 2;

}

void Brick::update() {
	health--;
}

bool Brick::dropBonus() {
	int chance = random(15);
	if (chance == 1) {
		return true;
	}
	return false;
}