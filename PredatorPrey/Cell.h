#pragma once
#include <vector>
#include <memory>

#include "Animal.h"

class Animal;

using animal_ptr = Animal*;

class Cell
{
	std::vector<animal_ptr> animals;

	int resourcesAvaible;
	int resourcesPer;

public:
	Cell() = delete;
	Cell(int initResources, int resourcesPer);
	~Cell();

	std::vector<animal_ptr>& getAnimals();

	int getResources() const;
	int eatResources(int count);
	int predatorsCount();
	int preysCount();

	void moveAnimal(animal_ptr& who, Cell& to);
	//void removeAnimal(animal_ptr& who);
	void removeAnimal(Animal* who);
	void addAnimal(animal_ptr& animal);
	void addAnimals(int predators, int preys);
	void doMove();
	void cleanUp();
};

