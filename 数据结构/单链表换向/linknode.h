#ifndef linknode_H
#define linknode_H
#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
struct linknode{
	T data;
	linknode<T> *link;
	linknode(linknode<T> *ptr = NULL){ link = ptr; }
	linknode(const T& item, linknode<T> *ptr = NULL)
	{
		data = item; link = ptr;
	}
};
template<class T>
class list
{
public:
	list(){ first = new linknode<T>; }
	list(const T& x){ first = new linknode<T>(x); }
	list(list<T>& L);
	~list(){ makeempty(); }
	void makeempty();
	int length()const;
	linknode<T> *gethead()const{ return first; }
	linknode<T> *search(T x);
	linknode<T> *locate(int i);
	bool getdata(int i, T &x)const;
	void setdata(int i, T& x);
	bool insert(int i, T& x);
	bool remove(int i, T& x);
	bool isempty()const{ return first->link == NULL ? true : false; }
	bool isfull()const{ return false; }
	void output();
	void diandao();
protected:
	linknode<T> *first;
};
template<class T>
list<T>::list(list<T>& L)
{
	T value;
	linknode<T> *srcptr = L.gethead();
	linknode<T> *destptr = first = new linknode<T>;
	while (srcptr->link != NULL)
	{
		value = srcptr->link->data;
		destptr->link = new linknode<T>(value);
		destptr = desptr->link;
		srcptr = srcptr->link;
	}
	desptr->link = NULL;
};
template<class T>
void list<T>::makeempty()
{
	linknode<T>*q;
	while (first->link != NULL)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
};
template<class T>
int list<T>::length()const
{
	linknode<T> *p = first->link; int count = 0;
	while (p != NULL)
	{
		p = p->link; count++;
	}
	return count;
};
template<class T>
linknode<T> *list<T>::search(T x)
{
	linknode<T> *current = first->link;
	while (current != NULL)
	{
		if (current->data == x)break;
		else current = current->link;
	}
	return current;
};
template<class T>
linknode<T> *list<T>::locate(int i)
{
	if (i<0)return NULL;
	linknode<T> *current = first;
	int k = 0;
	while (current != NULL&&k<i)
	{
		current = current->link;
		k++;
	}
	return current;
};
template<class T>
bool list<T>::getdata(int i, T& x)const
{
	if (i <= 0)return NULL;
	linknode<T> *current = locate(i);
	if (current == NULL)return false;
	else { x = current->data; return true; }
};
template<class T>
void list<T>::setdata(int i, T& x)//修改第i个元素
{
	if (i <= 0)return;
	linknode<T> *current = locate(i);
	if (current == NULL)return;
	else current->data = x;
};
template<class T>
bool list<T>::insert(int i, T& x)
{
	linknode<T> *current = locate(i);
	if (current == NULL)return false;
	linknode<T> *newnode = new linknode<T>(x);
	if (newnode == NULL){ cerr << "存储分配错误!" << endl; exit(1); }
	newnode->link = current->link;
	current->link = newnode;
	return true;
};
template<class T>
bool list<T>::remove(int i, T& x)
{
	linknode<T> *current = locate(i - 1);
	if (current == NULL || current->link == NULL)return false;
	linknode<T> *del = current->link;
	current->link = del->link;
	x = del->data; delete del;
	return true;
};
template<class T>
void list<T>::output()
{
	linknode<T> *current = first->link;
	while (current != NULL)
	{
		cout << current->data << endl;
		current = current->link;
	}
};
template<class T>
void list<T>::diandao()
{
	if (first->link == NULL)return;
	linknode<T> *current1 = first->link;
	linknode<T> *current2 = NULL;
	while(current1->link != NULL)
	{
		current2 = current1->link;
		current1->link = current2->link;
		current2->link = first->link;
		first->link = current2;
			}
	//delete current1,current2,current3;
}
#endif
