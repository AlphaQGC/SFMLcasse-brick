#include "LevelCreater.h"

LevelCreater::LevelCreater() {

}

vector<Brick*> LevelCreater::loadTable() {
		vector<Brick*> list;
		int X = 50;
		int Y = 100;
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 5; i++) {
				list.push_back(new Brick(X, Y, 100, 50));
				X += 200;
			}
			X = 50;
			Y += 100;
		}
		return list;
}