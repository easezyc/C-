// 带头的单链表.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linknode.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "请输入要加入链表的数据个数" << endl;
	int n;
	cin >> n;
	cout << "请输入要加入链表的数据" << endl;
	list<int> x;
	int y;
	int len;
	for (int i = 0; i<n; i++)
	{
		cin >> y;
		len = x.length();
		x.insert(len, y);
	}
	char ch;	
	while (1)
	{
		cout << "A查看第i个节点的地址   B插入节点    C查看最大的节点   D统计某个元素在链表中的个数    E建立函数create    F结束   G整理" << endl;
		cin >> ch;
		if (ch == 'A')
		{
			int i;
			cout << "请输入节点的序号" << endl;
			cin >> i;			
			cout << "第" << i << "个节点的地址为：" << x.locate(i) << endl;
			continue;
		}
		if (ch == 'B')
		{
			cout << "请输入要插入的位置:";
			int i;
			cin >> i;
			cout << "请输入要加入的元素:";
			int num;
			cin >> num;
			x.insert(i, num);
			continue;
		}
		if (ch == 'C')
		{
			int max;
			x.max(max);
			cout << "最大值是：" << max << endl;
		}
		if (ch == 'D')
		{
			cout << "请输入要统计个数的元素值：";
			int tongji;
			cin >> tongji;
			x.tongji(tongji);
			continue;
		}
		if (ch == 'E')
		{
			list<int> xx;
			xx.create();
		}
		if (ch == 'F'){ break; }
		if (ch == 'G'){ x.tidyup(); x.output(); }
		
	}
	return 0;
}

