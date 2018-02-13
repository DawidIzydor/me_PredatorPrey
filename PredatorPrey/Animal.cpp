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

void Animal::Die()
{
	HP = 0;
}

int Animal::getNeeds()
{
	return needs;
}

int Animal::getHP()
{
	return HP;
}
