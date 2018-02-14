#include "stdafx.h"
#include "Prey.h"


Prey::Prey(Cell* cell, int needs) : Animal(cell, needs)
{
	this->type = AnimalTypes::Prey;
	HP = 5;
}

Prey::~Prey()
{
}

void Prey::Eat()
{
	Aging();

	int eaten = currentCell->eatResources(needs);
	HP -= needs - eaten;
}