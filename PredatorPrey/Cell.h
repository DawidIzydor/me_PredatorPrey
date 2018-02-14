#pragma once
#include <vector>
#include <memory>
#include <random>

#include "Animal.h"
#include "CellsArray.h"
#include "defines.h"

class Animal;

class CellsArray;

class Cell
{
	CellsArray* cells;

	std::vector<Animal*> animals;

	int resourcesAvaible;
	int resourcesPer;

	const int maxAnims = MAXANIMS;

	int curprey = 0;
	int curpred = 0;
	int curanim = 0;

	int x = -1;
	int y = -1;

	int statsAnim;
	int statsPrey;
	int statsPred;

public:
	Cell() = delete;
	Cell(int initResources, int resourcesPer, CellsArray* cells);
	~Cell();

	std::vector<Animal*>& getAnimals();

	int getResources();
	int eatResources(int count);
	int predatorsCount();
	int preysCount();
	int animalsCount();

	void moveAnimal(Animal*& who, Cell& to) = delete;
	//void removeAnimal(Animal*& who);
	void removeAnimal(Animal* who);
	void addAnimal(Animal* animal);
	void addAnimals(int predators, int preys);
	void doMove();
	void cleanUp();

	void setCoords(int x, int y);

	int getStatsAnim();
	int getStatsPrey();
	int getStatsPred();
};

