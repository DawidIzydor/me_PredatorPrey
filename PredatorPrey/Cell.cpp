#include "stdafx.h"
#include "Cell.h"

#include <algorithm>
#include <memory>
#include <iostream>
#include "Predator.h"
#include "Prey.h"
#include <random>
#include "defines.h"

Cell::Cell(int initResources, int resourcesPer, CellsArray* cells)
{
	this->cells = cells;
	resourcesAvaible = initResources;
	this->resourcesPer = resourcesPer;
}


Cell::~Cell()
{
}

std::vector<Animal*>& Cell::getAnimals()
{
	return animals;
}

int Cell::getResources()
{
	return resourcesAvaible;
}

int Cell::eatResources(int count)
{
	if (resourcesAvaible > count)
	{
		resourcesAvaible -= count;
		return count;
	}
	else {
		int returned = count - resourcesAvaible;
		resourcesAvaible = 0;
		return returned;
	}
}

int Cell::predatorsCount()
{
	/*int ret = 0;
	for (int i = 0; i < animals.size(); i++)
	{
		if (animals.at(i)->getType() == AnimalTypes::Predator)
		{
			ret++;
		}
	}
	return ret;*/
	return curpred;
}

int Cell::preysCount()
{/*
	int ret = 0;
	for (int i = 0; i < animals.size(); i++)
	{
		if (animals.at(i)->getType() == AnimalTypes::Prey)
		{
			ret++;
		}
	}
	return ret;*/
	return curprey;
}

int Cell::animalsCount()
{
	return curanim;
}

/*void Cell::moveAnimal(Animal* & who, Cell & to)
{
	to.addAnimal(who);
	removeAnimal(who);
}*/

/*void Cell::removeAnimal(Animal* & who)
{
	removeAnimal(who.get());
}*/

void Cell::removeAnimal(Animal * who)
{
	auto& finded = std::find(animals.begin(), animals.end(), who);
	if (finded != animals.end())
	{
		if (who->getType() == AnimalTypes::Predator)
		{
			curpred--;
		}
		else {
			curprey--;
		}
		curanim--;
		animals.erase(finded);
	}
}

void Cell::addAnimal(Animal* animal)
{

	if (std::find(animals.begin(), animals.end(), animal) == animals.end())
	{
		animals.push_back(animal);
		
		if (animal->getType() == AnimalTypes::Predator)
		{
			curpred++;
		}
		else {
			curprey++;
		}
		curanim++;
	}
}


void Cell::addAnimals(int predators, int preys)
{

	for (int i = 0; i < preys; i++)
	{
		//Animal* temp = std::make_unique<Predator>(this, 1);
		Animal* temp = new Prey(this, 10);
		addAnimal(temp);
	}
	
	for (int i = 0; i < predators; i++)
	{
		//Animal* temp = std::make_unique<Predator>(this, 1);
		Animal* temp = new Predator(this, 1);
		addAnimal(temp);
	}

}


void Cell::doMove()
{

	if (curanim > 0) {
		std::cout << "Move start ("<< x << "," << y << ")\n";
		std::cout << "\nFood: " << resourcesAvaible << ",";
		std::cout << "Predators: " << predatorsCount() << ",";
		std::cout << "Preys: " << preysCount() << std::endl;
	}

	resourcesAvaible += resourcesPer;

	
	for (int i = 0; i < animals.size(); i++)
	{
		Animal* a = animals.at(i);

		int newx, newy;
		if (randmax(gen) < curanim)
		{
			int randet = rand100(gen);
			if (randet < 33)
			{
				newx = x - 1;
			}
			else if (randet > 66)
			{
				newx = x + 1;
			}
			else {
				newx = x;
			}
			randet = rand100(gen);
			if (randet < 33)
			{
				newy = y - 1;
			}
			else if (randet > 66)
			{
				newy = y + 1;
			}
			else {
				newy = y;
			}

			if (newx < 0) newx = 0;
			if (newx >= 10) newx = 9;
			if (newy < 0) newy = 0;
			if (newy >= 10) newy = 9;

			if (newx != x && newy != y)
			{
				//std::cout << "Moved from " << x << ", " << y << " to " << newx << ", " << newy << "\n";
				a->moveAnimal(&(cells->getCellVec().at(newx).at(newy)));
			}
		}
		
		a->Eat();

		if (curanim > maxAnims)
		{
			a->removeHP((curanim - maxAnims));
		}
		
		/*
		std::cout << "[" << i << "]";
		std::cout << "Type: " << (a->getType() == AnimalTypes::Predator ? "Predator" : "Prey")<<"\n";
		std::cout << "HP before eat: " << a->getHP() << "\n";*/
		//std::cout << "HP after eat: " << a->getHP() << "\n";
	}

	cleanUp();

	if (resourcesAvaible > 0) {
		addAnimals(predatorsCount() / 2, preysCount() / 2);
	}

	if (curanim > 0) {
		std::cout << "Food: " << resourcesAvaible << ",";
		std::cout << "Predators: " << predatorsCount() << ",";
		std::cout << "Preys: " << preysCount() << "\n";
		//std::cout<<
		std::cout << "Move end\n"<< std::endl;
	}
}

void Cell::cleanUp()
{
	for (int i = 0; i < animals.size(); i++)
	{
		if (animals.at(i)->getHP() <= 0)
		{
			if (animals.at(i)->getType() == AnimalTypes::Predator)
			{
				curpred--;
			}
			else {
				curprey--;
			}
			curanim--;

			animals.erase(animals.begin() + i);
			i--;
		}
	}
}

void Cell::setCoords(int x, int y)
{
	if (x >= 0 && y >= 0) {
		if (this->x == -1)
		{
			this->x = x;
			this->y = y;
		}
	}
}
