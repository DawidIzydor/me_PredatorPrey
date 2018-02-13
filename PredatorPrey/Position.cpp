#include "stdafx.h"
#include "Position.h"


Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}


Position::~Position()
{

}

int Position::getX() const
{
	return x;
}

int Position::getY() const
{
	return y;
}

bool Position::operator==(Position && other) const
{
	if (this->x == other.x && this->y == other.y)
	{
		return true;
	}
	else {
		return false;
	}
}
