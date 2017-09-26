// Test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Map.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;
int sum=0;
list<string> solutions;
void update(Map &m,int x,int y)
{
	system("cls");
	for (int i = 0; i < Mheight; i++)
	{
		for (int t = 0; t < Mwidth; t++)
		{
			cout << "*" << (m._cell[i][t].up ? "1" : "0") << "*";
		}
		cout << endl;
		for (int t = 0; t < Mwidth; t++)
		{
			cout << (m._cell[i][t].left ? "1" : "0") << ((x==t&&y==i)?"@":" ")<< (m._cell[i][t].right ? "1" : "0");
		}
		cout << endl;
		for (int t = 0; t < Mwidth; t++)
		{
			cout << "*" << (m._cell[i][t].down ? "1" : "0") << "*";
		}
		cout << endl;
	}
}

void go(int x, int y,Map &m,int act,string &s)
{
	update(m,x,y);
	if (x == Mwidth) 
	{
		std::cout << "Goal\n";
		solutions.emplace_back(s);
		if (s.length())
		s.pop_back();
		++sum;
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
	update(m, x, y);
	{
		if (m._cell[y][x].up)
		{
			m._cell[y][x].up = false;
			s.append("U");
			go(x, y - 1, m, 1,s);
			m._cell[y][x].up = true;
			update(m, x, y);
		}
		if (m._cell[y][x].down)
		{
			m._cell[y][x].down = false;
			s.append("D");
			go(x, y + 1, m, 3,s);
			m._cell[y][x].down = true;
			update(m, x, y);
		}
		if (m._cell[y][x].left)
		{
			m._cell[y][x].left = false;
			s.append("L");
			go(x - 1, y, m, 4,s);
			m._cell[y][x].left = true;
			update(m, x, y);
		}
		if (m._cell[y][x].right)
		{
			m._cell[y][x].right = false;
			s.append("R");
			go(x + 1, y, m, 2,s);
			m._cell[y][x].right = true;
			update(m, x, y);
		}
	}
	{
		switch (act)
		{
		case 1:
			m._cell[y][x].down = true;
			update(m, x, y);
			break;
		case 2:
			m._cell[y][x].left = true;
			update(m, x, y);
			break;
		case 3:
			m._cell[y][x].up = true;
			update(m, x, y);
			break;
		case 4:
			m._cell[y][x].right = true;
			update(m, x, y);
			break;
		}
	}
	update(m, x, y);
	if(s.length())
	s.pop_back();
	return;
}

int main()
{
	auto t = new Map;
	string s;
	update(*t,Mheight,Mwidth);
//	system("pause");
	go(0, 0, *t,0,s);
	delete t;
	cout << sum << endl;
	for (string t : solutions)
	{
		cout << t << endl;
	}
	getchar();
    return 0;
}

