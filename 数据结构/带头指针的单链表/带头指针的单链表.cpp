// ��ͷ�ĵ�����.cpp : Defines the entry point for the console application.
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
	char ch;	
	while (1)
	{
		cout << "A�鿴��i���ڵ�ĵ�ַ   B����ڵ�    C�鿴���Ľڵ�   Dͳ��ĳ��Ԫ���������еĸ���    E��������create    F����   G����" << endl;
		cin >> ch;
		if (ch == 'A')
		{
			int i;
			cout << "������ڵ�����" << endl;
			cin >> i;			
			cout << "��" << i << "���ڵ�ĵ�ַΪ��" << x.locate(i) << endl;
			continue;
		}
		if (ch == 'B')
		{
			cout << "������Ҫ�����λ��:";
			int i;
			cin >> i;
			cout << "������Ҫ�����Ԫ��:";
			int num;
			cin >> num;
			x.insert(i, num);
			continue;
		}
		if (ch == 'C')
		{
			int max;
			x.max(max);
			cout << "���ֵ�ǣ�" << max << endl;
		}
		if (ch == 'D')
		{
			cout << "������Ҫͳ�Ƹ�����Ԫ��ֵ��";
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

