#include "stdafx.h"
#include "Cell.h"

#include <algorithm>
#include <memory>
#include <iostream>
#include "Predator.h"
#include "Prey.h"

Cell::Cell(int initResources, int resourcesPer)
{
	resourcesAvaible = initResources;
	this->resourcesPer = resourcesPer;
}


Cell::~Cell()
{
}

std::vector<animal_ptr>& Cell::getAnimals()
{
	return animals;
}

int Cell::getResources() const
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
	int ret = 0;
	for (int i = 0; i < animals.size(); i++)
	{
		if (animals.at(i)->getType() == AnimalTypes::Predator)
		{
			ret++;
		}
	}
	return ret;
}

int Cell::preysCount()
{
	int ret = 0;
	for (int i = 0; i < animals.size(); i++)
	{
		if (animals.at(i)->getType() == AnimalTypes::Prey)
		{
			ret++;
		}
	}
	return ret;
}

void Cell::moveAnimal(animal_ptr & who, Cell & to)
{
	to.addAnimal(who);
	removeAnimal(who);
}

/*void Cell::removeAnimal(animal_ptr & who)
{
	removeAnimal(who.get());
}*/

void Cell::removeAnimal(Animal * who)
{
	auto finded = std::find(animals.begin(), animals.end(), who);
	if (finded != animals.end())
	{
		animals.erase(finded);
	}
}

void Cell::addAnimal(animal_ptr & animal)
{

	if (std::find(animals.begin(), animals.end(), animal) == animals.end())
	{
		animals.push_back(animal);
	}
}


void Cell::addAnimals(int predators, int preys)
{

	for (int i = 0; i < preys; i++)
	{
		//animal_ptr temp = std::make_unique<Predator>(this, 1);
		animal_ptr temp = new Prey(this, 10);
		addAnimal(temp);
	}
	
	for (int i = 0; i < predators; i++)
	{
		//animal_ptr temp = std::make_unique<Predator>(this, 1);
		animal_ptr temp = new Predator(this, 1);
		addAnimal(temp);
	}

}


void Cell::doMove()
{
	std::cout << "Move start\n";
	std::cout << "\nFood available before: " << resourcesAvaible << "\n";
	std::cout << "Predators before: " << predatorsCount() << "\n";
	std::cout << "Preys before: " << preysCount() << "\n";

	resourcesAvaible += resourcesPer;

	for (int i = 0; i < animals.size(); i++)
	{
		auto a = animals.at(i);
		/*
		std::cout << "[" << i << "]";
		std::cout << "Type: " << (a->getType() == AnimalTypes::Predator ? "Predator" : "Prey")<<"\n";
		std::cout << "HP before eat: " << a->getHP() << "\n";*/
		a->Eat();
		//std::cout << "HP after eat: " << a->getHP() << "\n";
	}
	cleanUp();
	if (resourcesAvaible > 0) {
		addAnimals(predatorsCount() / 2, preysCount() / 2);
	}
	std::cout << "\nFood available after: " << resourcesAvaible << "\n";
	std::cout << "Predators after: " << predatorsCount() << "\n";
	std::cout << "Preys after: " << preysCount() << "\n";
	//std::cout<<
	std::cout << "Move end\n\n";
}

void Cell::cleanUp()
{
	for (int i = 0; i < animals.size(); i++)
	{
		if (animals.at(i)->getHP() <= 0)
		{
			animals.erase(animals.begin() + i);
			i--;
		}
	}
}
