// Լɪ��ѭ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "seqlist.h"
#include<iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	seqlist<int> x(20);
	x.input();
	josephus(x,1, 5);
	x.output();
	return 0;
}

