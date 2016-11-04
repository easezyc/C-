// 迷宫算法递归.cpp : 定义控制台应用程序的入口点。
//


#include<iostream>
using namespace std;
const int m = 4, p = 4;
struct offsets{
	int a, b;
	char *dir;
};

int mark[m + 2][p + 2];
int maze[m + 2][p + 2] = { 1, 1, 1, 1, 1, 1,
0, 0, 1, 1, 0, 1,
1, 0, 1, 1, 1, 1,
1, 0, 0, 0, 1, 1,
1, 1, 0, 0, 0, 1,
1, 1, 1, 1, 1, 1 };
int seekpath(int x, int y)
{
	offsets move[8] = { { -1, 0, "N" }, { -1, 1, "NE" }, { 0, 1, "E" }, { 1, 1, "SE" }, { 1, 0, "S" }, { 1, -1, "SW" }, { 0, -1, "W" }, { -1, -1, "NW" } };
	int i, g, h;
	char *d;
	if (x == m&&y == p)
	{
		cout << "已达到出口" << endl;
		return 1;
	}
	for (i = 0; i < 8; i++)
	{
		g = x + move[i].a;
		h = y + move[i].b;
		d = move[i].dir;
		if (maze[g][h] == 0 && mark[g][h] == 0)
		{
			mark[g][h] = 1;
			if (seekpath(g, h)){
				cout << "(" << g << "," << h << ")," << "direction" << d << ",";
				return 1;
			}
		}
	}
		if(x==1&&y==1)cout << "no path in maze" << endl;
		return 0;
}
int main()
{
	int i, j;
	//for (i = 0; i < m + 2; i++)
	//for (j = 0; j < p + 2; j++)
		//cin >> maze[i][j];
	for (i = 0; i < m + 2; i++)
	{
		for (j = 0; j < p + 2; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
		for (i = 0; i < m + 2; i++)
	for (j = 0; j < p + 2; j++)
		mark[i][j] = 0;
	mark[1][1] = 1;
	if (seekpath(1, 1))cout << "(1,1)" << "drection" << "E" << endl;
	return 0;
}

