#include "LevelCreater.h"

LevelCreater::LevelCreater() {

}

vector<Brick*> LevelCreater::loadTable() {
		vector<Brick*> list;
		int X = 50;
		int Y = 100;
		const char* img = "img/blue-full.png";
		for (int j = 0; j < 15; j++) {
			for (int i = 0; i < 11; i++) {
				list.push_back(new Brick(X, Y, 80, 25, img));
				X += 80;
			}
			X = 50;
			Y += 30;
		}
		return list;
}