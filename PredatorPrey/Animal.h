#pragma once
#include <vector>
#include "Cell.h"

enum class AnimalTypes { None, Prey, Predator };

class Cell;

class Animal
{

protected:
	int HP;
	int needs;
	AnimalTypes type;
	Cell* currentCell;

public:
	/// We do not want to have non-cell animal
	Animal() = delete;

	Animal(Cell* cell, int needs);
	virtual ~Animal();

	virtual void Eat() = 0;

	int	getNeeds();
	int getHP();

	AnimalTypes getType();

	void Die();
};

