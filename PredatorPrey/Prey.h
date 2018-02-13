#pragma once
#include "Animal.h"
class Prey :
	public Animal
{
public:
	Prey() = delete;
	Prey(Cell* cell, int needs);
	~Prey();

	void Eat() override;
};

