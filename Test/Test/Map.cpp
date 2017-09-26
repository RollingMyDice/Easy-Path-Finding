#include "stdafx.h"
#include "Map.h"
#include <iostream>

using namespace std;

Map::Map()
{
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
	update();
	for (int i = 0; i < Mwidth; i++)
	{
		_cell[0][i].up = false;
		update();
		_cell[Mheight - 1][i].down = false;
		update();
	}
	update();
	for (int i = 0; i < Mheight; i++)
	{
		_cell[i][0].left = false;
		update();
		_cell[i][Mwidth - 1].right = false;
		update();
	}
	update();
	_cell[Mheight-2][Mwidth-1].right = true;
}


Map::~Map()
{
}

void Map::update()
{
	system("cls");
	for (int i = 0; i < Mheight; i++)
	{
		for (int t = 0; t < Mwidth; t++)
		{
			cout << "*" << (_cell[i][t].up ? "1" : "0") << "*";
		}
		cout << endl;
		for (int t = 0; t < Mwidth; t++)
		{
			cout << (_cell[i][t].left ? "1" : "0") << " " << (_cell[i][t].right ? "1" : "0");
		}
		cout << endl;
		for (int t = 0; t < Mwidth; t++)
		{
			cout << "*" << (_cell[i][t].down ? "1" : "0") << "*";
		}
		cout << endl;
	}
}
