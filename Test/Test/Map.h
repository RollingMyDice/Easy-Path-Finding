#pragma once
#include "Cell.h"
#define Mwidth 3
#define Mheight 3
class Map
{
public:
	Cell _cell[Mheight][Mwidth];
	Map();
	~Map(); 
	void update();
};

