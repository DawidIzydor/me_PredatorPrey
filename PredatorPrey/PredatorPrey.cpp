// PredatorPrey.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "Cell.h"
#include <iostream>
#include <cstdlib>


int main()
{
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
	Cell cell{ initfood, initper };

	cell.addAnimals(initpred, initprey);

	long int maxpreds = 0,maxpreys = 0,maxanims = 0,maxfood = 0;

	for (int i = 0; cell.predatorsCount()>0; i++)
	{
		std::cout << "[Move no. " << i+1 << "]\n";
		cell.doMove();
		if (cell.predatorsCount() > maxpreds)
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
		}
	}

	std::cout << "Init food:" << initfood << "\n";
	std::cout << "Food per turn:" << initper << "\n";
	std::cout << "Init prey:" << initprey << "\n";
	std::cout << "Init predators:" << initpred << "\n\n";

	std::cout << "Max preys: " << maxpreys << "\n";
	std::cout << "Max preds: " << maxpreds << "\n";
	std::cout << "Max anims: " << maxanims << "\n";
	std::cout << "Max food: " << maxfood << "\n";
	std::cout << "\n";
	system("PAUSE");
}

