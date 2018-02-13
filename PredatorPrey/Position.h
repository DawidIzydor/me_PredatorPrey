#pragma once
class Position
{
	int x;
	int y;
public:
	Position(int x, int y);
	~Position();

	int getX() const;
	int getY() const;

	bool operator==(Position&& other) const;
};

