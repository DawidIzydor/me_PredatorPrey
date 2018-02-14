#pragma once
#include <vector>
#include "Cell.h"

enum class AnimalTypes { None, Prey, Predator };

class Cell;

class Animal
{

protected:
	int age = 0;
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

	int	getNeeds() const;
	int getHP() const;
	int removeHP(int HP);

	AnimalTypes getType();

	void Aging();
	void Die();
	void moveAnimal(Cell* destination);

};

