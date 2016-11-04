#include<iostream>
using namespace std;
int maze[7][7] = { 1, 1, 1, 1, 1, 1, 1,
1, 0, 0, 1, 0, 0, 1,
1, 1, 1, 0, 0, 0, 1,
1, 0, 0, 1, 0, 0, 1,
1, 0, 0, 0, 0, 1, 1,
1, 0, 0, 1, 0, 0, 0,
1, 1, 1, 1, 1, 1, 1 };
struct que{
	int x, y, front;
};
class queue{
private:
	que *q;
	int front, rear;
	int maxsize;
public:
	queue(int sz)
	{
		maxsize = sz;
		q = new que[maxsize];
		front = 0;
		rear = 0;
	}
	~queue(){ delete q; };
	void enqueue(const que &x)
	{
		q[rear] = x;
		rear++;
	}
	void dequeue(que &x)
	{
		x = q[front];
		front++;
	}
	bool isempty()
	{
		if (front == rear){
			 return true;
		}
		else{
			 return false;
		}
	}
	void visit(que x)
	{
		if (maze[x.x][x.y] == 0)
		{
			
			maze[x.x][x.y] = 1;
			que f = { x.x, x.y, front - 1 };
			enqueue(f);
		}
	}
	void out(int x,que &y)
	{
		y = q[x];
	}
};
int main()
{
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 7; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
	que q = { 1, 1, -1 };
	queue p(1000);
	p.enqueue(q);
	maze[1][1] = 1;
	while (!p.isempty())
	{
		p.dequeue(q);
		
		if (q.x == 5 && q.y == 5)break;
		if (q.x + 1 <= 5){
			que newq = { q.x + 1, q.y, q.front }; p.visit(newq);
		}
		if (q.x + 1 <= 5&&q.y+1<=5){
			 que newq = { q.x + 1, q.y + 1, q.front }; p.visit(newq);
		}
		if (q.x <= 5 && q.y + 1 <= 5){
			que newq = { q.x, q.y + 1, q.front }; p.visit(newq);
		}
		if (q.x - 1 <= 5 && q.y + 1 <= 5){
			que newq = { q.x - 1, q.y + 1, q.front }; p.visit(newq);
		}
		if (q.x + 1 <= 5 && q.y - 1 <= 5){
			que newq = { q.x + 1, q.y - 1, q.front }; p.visit(newq);
		}
		if (q.x - 1 <= 5 && q.y  <= 5){
			que newq = { q.x - 1, q.y, q.front }; p.visit(newq);
		}
		if (q.x <= 5 && q.y -1 <= 5){
			que newq = { q.x, q.y - 1, q.front }; p.visit(newq);
		}
		if (q.x - 1 <= 5 && q.y - 1 <= 5){
			que newq = { q.x - 1, q.y - 1, q.front }; p.visit(newq);
		}
	}
	if (q.x == 5 && q.y == 5){
		cout << "(" << q.x << "," << q.y << ")" << endl;
		while (q.front != -1)
		{
			p.out(q.front, q);
			cout << "(" << q.x << "," << q.y << ")" << endl;
		}
	}
	else cout << "no path";
}
