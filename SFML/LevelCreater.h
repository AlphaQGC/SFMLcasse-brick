#pragma once
#include "Brick.h"
#include <vector>
using namespace std;

class LevelCreater
{
public:

	LevelCreater();

	vector<Brick*> loadTable();

};