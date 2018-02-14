#pragma once

#include "CellsArray.h"
#include <ios>

class Visualize
{

	CellsArray* cells;
	//std::fstream* stream;

public:
	Visualize() = delete;
	Visualize(CellsArray* cells);
	//Visualize(CellsArray* cells, std::fstream* stream) : Visualize(cells) { this->stream = stream; };
	~Visualize();

	void show();
};

