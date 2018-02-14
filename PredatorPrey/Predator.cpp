#include "stdafx.h"
#include "Predator.h"


Predator::Predator(Cell* cell, int needs) : Animal(cell, needs)
{
	this->type = AnimalTypes::Predator;
	HP = 3;
}

Predator::~Predator()
{
}

void Predator::Eat()
{
	Aging();

	for (int a = needs; a > 0; a--) {

		bool ate = false;

		for (auto&  a : currentCell->getAnimals())
		{
			if (a->getType() == AnimalTypes::Prey && a->getHP()>0)
			{

				a->Die();

				ate = true;
				break;
			}
		}

		if (!ate)
		{
			HP -= a;
			break;
		}
	}

	if (HP <= 0)
	{
		Die();
	}
}
