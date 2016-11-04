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
	BiTree(){ this->root = Creat();};
	void PrintBTree(BiNode<T> *BT);
	void ceheight(BiNode<T> *BT);
	int getheight(){return height;}
	BiNode<T> *getroot(){return root;}
private:
    int height=0,height1=0;
	BiNode<T>*root;
	BiNode<T>* Creat();
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
        for(int i=0;i<3*BT->h-1;i++)
        cout<<" ";
        cout<<BT->data<<endl;
        if(BT->lchild!=NULL||BT->rchild!=NULL){
            if(BT->lchild!=NULL)
            PrintBTree(BT->lchild);
            if(BT->rchild!=NULL)
            PrintBTree(BT->rchild);
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
int main()
{
    cout<<"6.37txt中有两个设计好的树，粘贴过来输入就可以"<<endl;
    while(1)
    {
    cout << "请输入创建一棵二叉树的结点数据(#表示空，按层次输入)：" << endl;
	BiTree<string> bt;
	cout<<"建立的树为([]里的表示层数):"<<endl;
	bt.PrintBTree(bt.getroot());
    }
    return 0;
}
