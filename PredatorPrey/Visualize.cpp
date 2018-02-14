#include "stdafx.h"
#include "Visualize.h"
#include <iostream>
#include <cstdio>
#include <sstream>
#include <boost/format.hpp>


Visualize::Visualize(CellsArray* _cells)
{
	cells = _cells;
}


Visualize::~Visualize()
{
}

void Visualize::show()
{
	auto& vec = cells->getCellVec();
	std::stringstream ss;

	/*for (int i{ 0 }; i < vec.at(0).size(); i++)
	{
		ss << "____";
	}*/
	ss << "\n";
	for (auto& a : vec)
	{
		ss << "|";
		for (auto& b : a)
		{
			ss <<boost::format("%-10i")% b.getResources();

			ss << "|";

		}
		ss << "\n|";
		for (auto& b : a)
		{
			ss << boost::format("%-10i") % b.predatorsCount();
			//std::cout << b.predatorsCount();
			//printf("%5d", b.predatorsCount());

			ss << "|";

		}
		ss << "\n|";
		for (auto& b : a)
		{
			ss << boost::format("%-10i") % b.preysCount();
			//std::cout << b.preysCount();
			//printf("%5d", b.preysCount());

			ss << "|";

		}
		ss << "\n____\n";
	}
	// ", " << b.predatorsCount() << ", " << b.preysCount();
	/*for (int i{ 0 }; i < vec.at(0).size(); i++)
	{
		ss << "_____";
	}*/

	std::cout << ss.str();
}
