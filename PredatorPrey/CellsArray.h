#pragma once

#include "Cell.h"
#include <vector>

class Cell;

class CellsArray
{
	std::vector<std::vector<Cell>> cellVec;

public:
	CellsArray() = delete;
	CellsArray(int x, int y, int initfood, int foodper, int preys, int preds);
	~CellsArray();

	std::vector<std::vector<Cell>>& getCellVec();

	void doMove();
	void show();
};

