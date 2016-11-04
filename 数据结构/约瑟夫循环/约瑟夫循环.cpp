// 约瑟夫循环.cpp : 定义控制台应用程序的入口点。
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

