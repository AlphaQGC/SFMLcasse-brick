#include "Brick.h"

Brick::Brick(int x, int y, int width, int height, const char* img) : GameObject(x, y, width, height, img) {

	health = 2;
}

void Brick::update() {
	health -= 1;
}

bool Brick::dropBonus() {
	int chance = random(15);
	if (chance == 1) {
		return true;
	}
	return false;
}