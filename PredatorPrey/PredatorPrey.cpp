// PredatorPrey.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "Cell.h"
#include <iostream>
#include <cstdlib>
#include "defines.h"
#include <windows.h>
#include <fstream>


std::random_device rd;
std::mt19937 gen{ rd() };
std::uniform_int_distribution<> randmax{ 0, 2 * MAXANIMS };
std::uniform_int_distribution<> rand100{ 0, 100 };

int main()
{
	std::ofstream out("out.txt");
	std::streambuf *coutbuf = std::cout.rdbuf();

	long int initfood, initper, initprey, initpred;

	std::cout << "Init food [1500]: ";
	std::cin >> initfood;

	std::cout << "Food per turn [200]: ";
	std::cin >> initper;

	std::cout << "Init prey [20]: ";
	std::cin >> initprey;

	std::cout << "Init predators[5]: ";
	std::cin >> initpred;
	std::cout << "\n";

	CellsArray cells(10, 10, initfood,initper,initprey,initpred);

	long int maxpreds = 0,maxpreys = 0,maxanims = 0,maxfood = 0;

	char bumba;

	std::cout.rdbuf(out.rdbuf());
	for (int i = 0; i < 20; i++)
	{
		std::cout << "[Move no. " << i+1 << "]\n";
		cells.doMove();
		/*if (cell.predatorsCount() > maxpreds)
		{
			maxpreds = cell.predatorsCount();
		}
		if (cell.preysCount() > maxpreys)
		{
			maxpreys = cell.preysCount();
		}
		if (cell.predatorsCount() + cell.preysCount() > maxanims)
		{
			maxanims = cell.predatorsCount() + cell.preysCount();
		}
		if (cell.getResources() > maxfood)
		{
			maxfood = cell.getResources();
		}*/

		//std::cin >> bumba;
	}

	std::cout.rdbuf(coutbuf);

	std::cout << "Init food:" << initfood << "\n";
	std::cout << "Food per turn:" << initper << "\n";
	std::cout << "Init prey:" << initprey << "\n";
	std::cout << "Init predators:" << initpred << "\n\n";
	/*
	std::cout << "Max preys: " << maxpreys << "\n";
	std::cout << "Max preds: " << maxpreds << "\n";
	std::cout << "Max anims: " << maxanims << "\n";
	std::cout << "Max food: " << maxfood << "\n";*/
	std::cout << "\n";
	system("PAUSE");
}

