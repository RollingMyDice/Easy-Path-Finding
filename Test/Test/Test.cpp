// Test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Map.h"
#include <iostream>
void go(int x, int y,Map &m,int act)
{
	if (x == 3) 
	{
		std::cout << "Goal\n";
		return;
	}
	switch (act)
	{
	case 1:
		m._cell[y][x].down = false;
		break;
	case 2:
		m._cell[y][x].left = false;
		break;
	case 3:
		m._cell[y][x].up = false;
		break;
	case 4:
		m._cell[y][x].right = false;
		break;
	default:
		break;
	}
	if (m._cell[y][x].left ||
		m._cell[y][x].right ||
		m._cell[y][x].up ||
		m._cell[y][x].down
		){
		if (m._cell[y][x].up == true)
		{
			m._cell[y][x].up = false;
			go(x, y - 1, m, 1);
			m._cell[y][x].up = true;
		}
		if (m._cell[y][x].down == true)
		{
			m._cell[y][x].down = false;
			go(x, y + 1, m, 3);
			m._cell[y][x].down = true;
		}
		if (m._cell[y][x].left == true)
		{
			m._cell[y][x].left = false;
			go(x - 1, y, m, 4);
			m._cell[y][x].left = true;
		}
		if (m._cell[y][x].right == true)
		{
			m._cell[y][x].right = false;
			go(x + 1, y, m, 2);
			m._cell[y][x].right = true;
		}
	}
	else
	{
		switch (act)
		{
		case 1:
			m._cell[y][x].down = true;
			break;
		case 2:
			m._cell[y][x].left = true;
			break;
		case 3:
			m._cell[y][x].up = true;
			break;
		case 4:
			m._cell[y][x].right = true;
			break;
		}
	}
	return;
}

int main()
{
	auto t = new Map;
	go(0, 0, *t,0);
	getchar();
    return 0;
}

