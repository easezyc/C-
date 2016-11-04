#ifndef seqlist_H
#define seqlist_H
#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class seqlist{
protected:
	T *data;
	int maxsize;
	int last;
public:
	seqlist(int sz = 0);
	seqlist(seqlist<T>& L);
	~seqlist(){ delete[] data; }
	int length()const{ return last + 1; }
	bool getdata(int i, T& x)const
	{
		if (i > 0 && i <= last + 1){ x = data[i - 1]; return true; }
		else return false;
	}
	void setdata(int i, T& x)
	{
		if (i > 0 && i <= last + 1)data[i - 1] = x;
	}
	int search(T &x)const;
	int locate(int i)const;
	bool insert(int i, T& x);
	bool remove(int i, T& x);
	int size()const{ return maxsize; }
	void input();
	void output();
	seqlist<T>operator=(seqlist<T>& L);
	friend void josephus(seqlist<T>& x,int n, int m)
	{
		int a;
		a = x.last;
		if (n > a + 1){ cout << "数据错误"; exit(1); }
		int i, j;
		int b = n;
		for (i = 0; i <= a; i++)
		{
			for (j = 0; j < m; j++)
			{
				b++;
				if (b>x.last + 1)b = 1;
			}
			T c;
			bool d;
			d = x.remove(b, c);
			cout << "删除的是:" << c << endl;
			b--;
			if (b <= 0)b = x.last + 1;
			cout << b << endl;
		}
	}
};
template<class T>
seqlist<T>::seqlist(int sz)
{
	if (sz > 0){
		maxsize = sz;
		last = -1;
		data = new T[maxsize];
		if (data == NULL){ cerr << "存储分配错误！" << endl; exit(1); }
	}
}
template<class T>
seqlist<T>::seqlist(seqlist<T>& L)
{
	maxsize = L.size();
	last = L.length() - 1;
	T value;
	date = new T[maxsize];
	if (data == NULL)
	{
		cerr << "存储分配错误" << endl; exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getdata(i,value);
		data[i - 1] = value;
	}
}
template<class T>
int seqlist<T>::search(T& x)const
{
	for (int i = 0; i <= last;i++)
	if (data[i] == x)return i + 1;
	return 0;
}
template<class T>
int seqlist<T>::locate(int i)const
{
	if (i >= 1 && i <= last + 1)return 1;
	else return 0;
}
template<class T>
bool seqlist<T>::insert(int i, T& x)
{
	if (last == maxsize - 1)return false;
	if (i<0 || i>last + 1)return false;
	for (int j = last; j >= i; j--)
		data[j + 1] = data[j];
	data[i] = x;
	last++;
	return true;
}
template<class T>
bool seqlist<T>::remove(int i, T& x)
{
	if (last == -1)return false;
	if (i<1 || i>last + 1)return false;
	x = data[i - 1];
	for (int j = i; j <= last; j++)
		data[j - 1] = data[j];
	last--;
	return true;
}
template<class T>
void seqlist<T>::input()
{
	cout << "开始建立顺序表，请输入表中元素个数：";
	while (1){
		int n;
		cin >> n;
		last = n - 1;
		if (last <= maxsize - 1)break;
		cout << "表元素个数输入有误，范围不能超过" << maxsize << ":";
	
	}
	for (int i = 0; i <= last; i++)
	{
		cin >> data[i];
	}
}
template<class T>
void seqlist<T>::output()
{
	if (last < 0)cout << "表中无元素" << endl;
	else{
		cout << "顺序表当前元素最后位置为：" << last << endl;
		for (int i = 0; i <= last; i++)
			cout << "#" << i + 1 << ":" << data[i] << endl;
	}
}
template<class T>
seqlist<T>seqlist<T>::operator=(seqlist<T>& L)
{
	maxsize = L.size();
	last = L.length() - 1;
	T value;
	date = new T[maxsize];
	if (data == NULL)
	{
		cerr << "存储分配错误" << endl; exit(1);
	}
	for (int i = 1; i <= last + 1; i++)
	{
		L.getdata(i, value);
		data[i - 1] = value;
	}
}
#endif