// 2.17��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "linknode.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "������Ҫ������������ݸ���" << endl;
	int n;
	cin >> n;
	cout << "������Ҫ�������������" << endl;
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
	cout << "�ߵ���:" << endl;
	x.output();
	return 0;
}

