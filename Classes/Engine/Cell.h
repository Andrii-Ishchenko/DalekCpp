#pragma once

enum class FieldCellType
{
	FREE = 1,
	OBSTACLE = 2
};


class Cell
{
public:
	Cell(int x,int y, FieldCellType type);
	~Cell();

public:
	int x, y;
	FieldCellType type;
	
	bool isObstacle() { return type != FieldCellType::OBSTACLE; }
};

