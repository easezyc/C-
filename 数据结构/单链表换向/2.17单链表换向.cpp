// 2.17单链表换向.cpp : 定义控制台应用程序的入口点。
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
	x.output();
	x.diandao();
	cout << "颠倒后:" << endl;
	x.output();
	return 0;
}

