#include <iostream>
#include<string>
using namespace std;

template<class T>
struct BiNode
{
	T data;
	BiNode<T> *lchild, *rchild,*parent=NULL;
	int h;
};

template<class T>
class BiTree
{
public:
	BiTree(){ this->root = Creat();maxdata=root->data; };
	void LeverOrder();
	void duwei1();
	void duwei2();
	void duwei0();
	void PrintBTree(BiNode<T> *BT);
	void ceheight(BiNode<T> *BT);
	void findpoint(BiNode<T> *BT,T a);
	void findjiedian(BiNode<T> *BT,BiNode<T> *a);
	void findmax(BiNode<T> *BT);
	T getmaxdata(){return maxdata;}
	int getheight(){return height;}
	BiNode<T> *getroot(){return root;}
	void treekuandu();
private:
    int height=0,height1=0;
	BiNode<T>*root;
	BiNode<T>* Creat();
	T maxdata;
};
template<class T>
void BiTree<T>::treekuandu()//���Ŀ��
{
	if (root == NULL) return;
	const int MaxSize = 100;
	int a[12];
	int n=0;
	for(int i=0;i<12;i++)
    {
        a[i]=0;
    }
	int front = 0; int rear = 0;
	BiNode<T>* Q[MaxSize]; BiNode<T>* q;
	{
		Q[rear++] = root;
		while (front != rear)
		{
			q = Q[front++];
			a[q->h]++;
			if (q->lchild != NULL)
				Q[rear++] = q->lchild;
			if (q->rchild != NULL)
				Q[rear++] = q->rchild;
		}
	}
	for(int i=0;i<12;i++)
    {
        if(n<a[i])n=a[i];
    }
    cout<<"���Ŀ��Ϊ��"<<n<<endl;
};

template<class T>//���ҽڵ����ڲ���
void BiTree<T>::findjiedian(BiNode<T> *BT,BiNode<T> * a)
{
    if(BT!=NULL){
        if(BT!=a){
        if(BT->lchild!=NULL||BT->rchild!=NULL){

            if(BT->lchild!=NULL)
            findpoint(BT->lchild,a);
            if(BT->rchild!=NULL)
            findpoint(BT->rchild,a);
        }
        }
        else {cout<<"�����ڵ�"<<BT->h<<"��"<<endl;}
    }
}
template<class T>
void BiTree<T>::duwei0()//��Ϊ0
{
    int n=0;
	if (root == NULL){ cout<<"��Ϊ��"<<endl;return;}
	const int MaxSize = 100;
	int front = 0; int rear = 0;
	BiNode<T>* Q[MaxSize]; BiNode<T>* q;
	{
		Q[rear++] = root;
		while (front != rear)
		{
			q = Q[front++];
			if (q->lchild != NULL)
				Q[rear++] = q->lchild;
			if (q->rchild != NULL)
				Q[rear++] = q->rchild;
			if ((q->lchild == NULL) && (q->rchild == NULL))
				{
				    n++;
				}
		}
		cout << endl << "��Ϊ0�Ľڵ����Ϊ��" << n << endl;
	}
};
template<class T>
void BiTree<T>::duwei2()//��Ϊ2
{
    int n=0;
	if (root == NULL){ cout<<"��Ϊ��"<<endl;return;}
	const int MaxSize = 100;
	int front = 0; int rear = 0;
	BiNode<T>* Q[MaxSize]; BiNode<T>* q;
	{
		Q[rear++] = root;
		while (front != rear)
		{
			q = Q[front++];
			if (q->lchild != NULL)
				Q[rear++] = q->lchild;
			if (q->rchild != NULL)
				Q[rear++] = q->rchild;
			if ((q->lchild != NULL) && (q->rchild != NULL))
				{
				    n++;
				}
		}
		cout << endl << "��Ϊ2�Ľڵ����Ϊ��" << n << endl;
	}
};
template<class T>
void BiTree<T>::duwei1()//��Ϊ1
{
    int n=0;
	if (root == NULL){ cout<<"��Ϊ��"<<endl;return;}
	const int MaxSize = 100;
	int front = 0; int rear = 0;
	BiNode<T>* Q[MaxSize]; BiNode<T>* q;
	{
		Q[rear++] = root;
		while (front != rear)
		{
			q = Q[front++];
			if (q->lchild != NULL)
				Q[rear++] = q->lchild;
			if (q->rchild != NULL)
				Q[rear++] = q->rchild;
			if (((q->lchild == NULL) && (q->rchild != NULL))||((q->lchild != NULL) && (q->rchild == NULL)))
				{
				    n++;
				}
		}
		cout << endl << "��Ϊ1�Ľڵ����Ϊ��" << n << endl;
	}
};
template<class T>
void BiTree<T>::LeverOrder()//ɾ��Ҷ�ӽڵ�
{
	if (root == NULL) return;
	const int MaxSize = 100;
	int front = 0; int rear = 0;
	BiNode<T>* Q[MaxSize]; BiNode<T>* q;
	{
		Q[rear++] = root;
		while (front != rear)
		{
			q = Q[front++];
			if (q->lchild != NULL)
				Q[rear++] = q->lchild;
			if (q->rchild != NULL)
				Q[rear++] = q->rchild;
			if ((q->lchild == NULL) && (q->rchild == NULL))
				{
				    if(q->parent->lchild==q){q->parent->lchild=NULL;}
				    if(q->parent->rchild==q){q->parent->rchild=NULL;}
				    delete q;
				}
		}
	}
};

template<class T>
BiNode<T>*BiTree<T>::Creat()
{
	BiNode<T>* root;
	BiNode<T>* q;
	BiNode<T>* p;
	T ch;
	cin >> ch;
	if (ch == "#") root = NULL;
	else
	{
	    height1++;
		root = new BiNode<T>;
		root->data = ch;
		root->h=height1;
		q = Creat();
		if(q!=NULL)
		q->parent=root;
		root->lchild=q;
		p = Creat();
		if(p!=NULL)
        p->parent=root;
		root->rchild=p;
		height1--;
	}
	return root;
}
template<class T>
void BiTree<T>::PrintBTree(BiNode<T> *BT)
{
    if(BT!=NULL){
        cout<<BT->data<<"["<<BT->h<<"]";
        if(BT->lchild!=NULL||BT->rchild!=NULL){
            cout<<"(";
            if(BT->lchild!=NULL)
            PrintBTree(BT->lchild);
            cout<<",";
            if(BT->rchild!=NULL)
            PrintBTree(BT->rchild);
            cout<<")";
        }
    }
}
template<class T>
void BiTree<T>::ceheight(BiNode<T> *BT)
{
    if(BT!=NULL){
        height1++;
        if(height<height1)height=height1;
        if(BT->lchild!=NULL||BT->rchild!=NULL){

            if(BT->lchild!=NULL)
            ceheight(BT->lchild);

            if(BT->rchild!=NULL)
            ceheight(BT->rchild);

        }
        height1--;
    }
}
template<class T>//���ҽڵ��������ڲ���
void BiTree<T>::findpoint(BiNode<T> *BT,T a)
{
    if(BT!=NULL){
        if(BT->data!=a){
        if(BT->lchild!=NULL||BT->rchild!=NULL){

            if(BT->lchild!=NULL)
            findpoint(BT->lchild,a);
            if(BT->rchild!=NULL)
            findpoint(BT->rchild,a);
        }
        }
        else {cout<<"�����ڵ�"<<BT->h<<"��"<<endl;}
    }
}
template<class T>
void BiTree<T>::findmax(BiNode<T> *BT)
{
    if(BT!=NULL){
        if(BT->data>maxdata)maxdata=BT->data;
        if(BT->lchild!=NULL||BT->rchild!=NULL){
            if(BT->lchild!=NULL)
            findmax(BT->lchild);
            if(BT->rchild!=NULL)
            findmax(BT->rchild);
        }
    }
}
int main()
{
    cout << "�����봴��һ�ö������Ľ������(#��ʾ�գ����������)��" << endl;
	BiTree<string> bt;
	cout<<"��������Ϊ([]��ı�ʾ����):"<<endl;
	bt.PrintBTree(bt.getroot());
	cout<<endl<<endl;
	bt.treekuandu();
	string a;
	cout<<endl;
	bt.findmax(bt.getroot());
	cout<<"����Ԫ��Ϊ:"<<bt.getmaxdata()<<endl;
	cout<<"\n"<<"������Ҫ���ҵ�����:";
	cin>>a;
	bt.findpoint(bt.getroot(),a);
	bt.ceheight(bt.getroot());
	cout<<"\n"<<"���ĸ߶ȣ�"<<bt.getheight()<<endl;
	bt.duwei1();
	bt.duwei2();
	bt.duwei0();
	cout<<endl<<"ɾ��Ҷ�ڵ��:"<<endl;
	bt.LeverOrder();
	bt.PrintBTree(bt.getroot());
	return 0;
}
