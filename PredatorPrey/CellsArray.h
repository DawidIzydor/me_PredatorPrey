#pragma once

#include "Cell.h"
#include <vector>

class Cell;

class CellsArray
{
	std::vector<std::vector<Cell>> cellVec;

	int statsAnim;
	int statsPrey;
	int statsPred;

public:
	CellsArray() = delete;
	CellsArray(int x, int y, int initfood, int foodper, int preys, int preds);
	~CellsArray();

	std::vector<std::vector<Cell>>& getCellVec();

	void doMove();
	void show();

	int getStatsAnim();
	int getStatsPrey();
	int getStatsPred();
};

