// 栈的迷宫问题.cpp : 定义控制台应用程序的入口点。
//


#include<iostream>
using namespace std;
struct offsets
{
	int x, y;
	char *dir;
	friend ostream &operator<<(ostream &os, offsets& newx)
	{
		return os << "(" << newx.x << "," << newx.y << ")" << newx.dir << " -> ";
	}
};
class stack
{
private:
	offsets *element;
	int top;
	int maxsize;
public:
	stack(int sz = 200)
	{
		maxsize = sz;
		element = new offsets[maxsize];
		top = -1;
	}
	bool isempty()
	{
		if (top == -1)return true;
		else return false;
	}
	void push(const offsets newx)
	{
		element[++top] = newx;
	}
	bool pop(offsets &x)
	{
		if (isempty() == true)return false;
		else{
			x = element[top];
			top--;
			return true;
		}
	}

	friend ostream &operator<<(ostream &os,stack newx)
	{
		for (int i = 0; i <= newx.top; i++)
		{
			cout << newx.element[i];
		}
		return os;
	}
};
int m, p;
int mark[100][100];
int maze[100][100];

void path(int a,int s,int m, int p)
{
	offsets move[8] = { { -1, 0, "N" }, { -1, 1, "NE" }, { 0, 1, "E" }, { 1, 1, "SE" }, { 1, 0, "S" }, { 1, -1, "SW" }, { 0, -1, "W" }, { -1, -1, "NW" } };
	int i, j, g, h;
	int direct=2;
	mark[a][s] = 1;
	stack st(m*p);
	offsets tmp;
	tmp.x = a; tmp.y = s; tmp.dir = "E";
	st.push(tmp);
    if (a == m&&s == p)
			{
				cout << st;
				cout <<"("<< m << "," << p <<")"<< endl;
				return;
			}

	while (st.isempty() == false)
	{
		st.pop(tmp);
		i = tmp.x;
		j = tmp.y;
		while (direct < 8)
		{

			g = i + move[direct].x;
			h = j + move[direct].y;
			if (maze[g][h] == 0 && mark[g][h] == 0)
			{
				mark[g][h] = 1;
				tmp.x = i; tmp.y = j; tmp.dir = move[direct].dir;
				st.push(tmp);
				i = g; j = h; direct = 0;
			}
			if (g == m&&h == p)
			{
				cout << st;
				cout <<"("<< m << "," << p <<")"<< endl;
				return;
			}

			else direct++;
		}
	}
}
int main()
{
    cout<<"请输入迷宫的行列数:";
    cin>>m>>p;
    cout<<"请输入你的迷宫矩阵:"<<endl;
	int i, j;
	for (i = 0; i < m + 2; i++)
	for (j = 0; j < p + 2; j++)
		{maze[i][j] = 1;mark[i][j]=1;}
	for (i = 1; i < m + 1; i++)
	for (j = 1; j < p + 1; j++)
		cin >> maze[i][j];
	for (i = 1; i < m + 1; i++)
	for (j = 1; j < p + 1; j++)
		mark[i][j]=0;
		cout<<"生成的迷宫矩阵:"<<endl;
	for (i = 0; i < m + 2; i++){
	for (j = 0; j < p + 2; j++)
		cout<<maze[i][j]<<" ";
        cout<<endl;
	}
	mark[1][1] = 1;
	cout<<"请输入迷宫的起点坐标:";
	cin>>i>>j;
    cout<<"请输入迷宫的终点坐标:";
    int k,l;
    cin>>k>>l;
    if(i>m||i<=0||j>p||j<=0||k>m||k<=0||l>p||l<=0){cout<<"输入的终点或者起点不正确";}
    else{
	cout<<"一种解决方案:"<<endl;
	path(i,j,k, l);}
	return 0;
}

