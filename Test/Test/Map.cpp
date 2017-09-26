#include "stdafx.h"
#include "Map.h"


Map::Map()
{
	for (int i = 0; i < Mwidth*Mheight; i++)
	{
		_cell[i/Mwidth][i%Mwidth].num = i;
	}
	for (int i = 0; i < Mheight; i++)
	{
		for (int t = 0; t < Mwidth; t++)
		{
			_cell[i][t].up = true;
			_cell[i][t].left = true;
			_cell[i][t].right = true;
			_cell[i][t].down = true;
		}
	}
	for (int i = 0; i < Mwidth; i++)
	{
		_cell[0][i].up = false;
		_cell[Mheight - 1][i].down = false;
	}
	for (int i = 0; i < Mwidth; i++)
	{
		_cell[i][0].left = false;
		_cell[i][Mwidth - 1].right = false;
	}
	_cell[1][2].right = true;
}


Map::~Map()
{
}
