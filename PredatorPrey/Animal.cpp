#include "stdafx.h"
#include "Animal.h"

Animal::Animal(Cell* cell, int needs)
{
	currentCell = cell;
	this->needs = needs;
}

Animal::~Animal()
{

}

AnimalTypes Animal::getType()
{
	return type;
}

void Animal::Aging()
{
	age++;
	if (rand100(gen) < age)
	{
		Die();
	}
}

void Animal::Die()
{
	HP = -1;
}

void Animal::moveAnimal(Cell * destination)
{
	if (destination != nullptr) {
		destination->addAnimal(this);
		currentCell->removeAnimal(this);
	}
}

int Animal::getNeeds() const
{
	return needs;
}

int Animal::getHP() const
{
	return HP;
}

int Animal::removeHP(int count)
{
	HP -= count;
	return HP;
}
