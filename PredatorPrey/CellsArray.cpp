#include "stdafx.h"
#include "CellsArray.h"
#include <random>

CellsArray::CellsArray(int x, int y, int initfood, int foodper, int preys, int preds)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disPrey(0, preys);
	std::uniform_int_distribution<> disPred(0, preds);

	Cell tempCell{ initfood, foodper, this };

	cellVec = std::vector<std::vector<Cell>>(y);
	
	int ax = 0;
	for (auto& a : cellVec)
	{
		a = std::vector<Cell>(x, Cell(tempCell));
		int ay = 0;
		for (auto& i : a)
		{
			i.setCoords(ax, ay);
			i.addAnimals(disPred(gen), disPrey(gen));
			
			ay++;
		}
		ax++;
	}


}


CellsArray::~CellsArray()
{
}

std::vector<std::vector<Cell>>& CellsArray::getCellVec()
{
	return cellVec;
}

void CellsArray::doMove()
{
	for (auto& a : cellVec)
	{
		for (auto& b : a)
		{
			b.doMove();
		}
	}
}
