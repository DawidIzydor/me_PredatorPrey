#pragma once
#include "Animal.h"
class Predator :
	public Animal
{

public:

	Predator() = delete;
	Predator(Cell* cell, int needs);

	~Predator();

	void Eat() override;
};

