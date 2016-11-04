#include<iostream>
#include<string.h>
using namespace std;
const int defaultsize=10;
struct huffmannode{
    double data;
    char zimu;
    string huffmanma;
    huffmannode *leftchild,*rightchild,*parent;
    huffmannode():leftchild(NULL),rightchild(NULL),parent(NULL){}
    huffmannode(double elem,char zimu1,huffmannode *left=NULL,huffmannode *right=NULL,huffmannode *pr=NULL):data(elem),zimu(zimu1),leftchild(left),rightchild(right),parent(pr){}
    bool operator<=(huffmannode& R){return data<=R.data;}
    bool operator>(huffmannode& R){return data>R.data;}
};
template<class T>
class minheap{
private:
    T *heap;

    int currentsize;
    int maxheapsize;
    void siftdown(int start,int m);
    void siftup(int start);
public:
    minheap(int sz=defaultsize);
    minheap(T arr[],int n);
    ~minheap(){delete []heap;}
    bool insert1(const T& x);
    bool removemin(T& x);
    bool isempty()const{return (currentsize==0)?true:false;}
    bool isfull()const{return (currentsize==maxheapsize)?true:false;}
    void makeempty(){currentsize=0;}
};
template<class T>
minheap<T>::minheap(int sz){
    maxheapsize=(defaultsize<sz)?sz:defaultsize;
    heap=new T[maxheapsize];
    if(heap==NULL){cout<<"堆存储分配失败"<<endl;}
    currentsize=0;
}
template<class T>
minheap<T>::minheap(T arr[],int n){
    maxheapsize=(defaultsize<n)?n:defaultsize;
    heap=new T[maxheapsize];
    if(heap==NULL){cout<<"堆存储分配失败"<<endl;}
    for(int i=0;i<n;i++)heap[i]=arr[i];
    currentsize=n;
    int currentpos=(currentsize-2)/2;
    while(currentpos>=0){
        siftdown(currentpos,currentsize-1);
        currentpos--;
    }
}
template<class T>
void minheap<T>::siftdown(int start,int m){
    int i=start,j=2*i+1;
    T temp=heap[i];
    while(j<=m){
        if(j<m&&heap[j]>heap[j+1])j++;
        if(temp<=heap[j])break;
        else{heap[i]=heap[j];i=j;j=2*j+1;}
    }
    heap[i]=temp;
}
template<class T>
void minheap<T>::siftup(int start){
    int j=start,i=(j-1)/2;T temp=heap[j];
    while(j>0){
        if(heap[i]<=temp)break;
        else{heap[j]=heap[i];j=i;i=(i-1)/2;}
    }
    heap[j]=temp;
}
template<class T>
bool minheap<T>::insert1(const T& x){
    heap[currentsize]=x;
    siftup(currentsize);
    currentsize++;
    return true;
}
template<class T>
bool minheap<T>::removemin(T& x)
{
    x=heap[0];heap[0]=heap[currentsize-1];
    currentsize--;
    siftdown(0,currentsize-1);
    return true;
}
struct ch{
    char x;
    double y;
    string huffman;
    ch() : x('\0'), y(0) {}
	ch(char c, double v) : x(c), y(v) {}
	ch(ch &c) : x(c.x), y(c.y) {}
	bool operator <= (ch &t) {
		return y <= t.y;
	}
	bool operator > (ch &t) {
		return y > t.y;
	}
	bool operator < (ch &t) {
		return y < t.y;
	}
};
class huffmantree{
public:
    void PrintBTree(huffmannode *BT);
    void bianma(huffmannode *BT);
    void gethuffmanma(huffmannode *BT,char v,string &a);
    huffmantree(ch w[],int n);
    ~huffmantree(){delete root;}
    huffmannode *getroot(){return root;}
protected:
    huffmannode *root;
    string b="";
    void deletetree(huffmannode *t);
};

void huffmantree::PrintBTree(huffmannode *BT)
{
    if(BT!=NULL){
        cout<<BT->data;
        if(BT->leftchild!=NULL||BT->rightchild!=NULL){
            cout<<"(";
            if(BT->leftchild!=NULL)
            PrintBTree(BT->leftchild);
            cout<<",";
            if(BT->rightchild!=NULL)
            PrintBTree(BT->rightchild);
            cout<<")";
        }
    }
}
huffmantree::huffmantree(ch w[],int n)
{
    minheap <huffmannode>hp;
    huffmannode *parent,work,*first,*second;
    for(int i=0;i<n;i++)
    {
        work.data=w[i].y;
        work.zimu=w[i].x;
        work.leftchild=NULL;
        work.rightchild=NULL;
        work.parent=NULL;
        hp.insert1(work);
    }
    for(int i=0;i<n-1;i++)
    {
        first=new huffmannode;
        second=new huffmannode;
        hp.removemin(*first);
        hp.removemin(*second);
        parent=new huffmannode;
        if(first->data<=second->data){
        parent->leftchild=first;parent->rightchild=second;
        }
        else {parent->leftchild=second;parent->rightchild=first;}
        parent->data=first->data+second->data;
        first->parent=parent;
        second->parent=parent;
        hp.insert1(*parent);
        root=parent;
    }

}
void huffmantree::bianma(huffmannode *BT)
{
    if(BT!=NULL){
        if(BT->leftchild!=NULL||BT->rightchild!=NULL){
            if(BT->leftchild!=NULL)
            {
            string a="0";
            b=b+a;
            bianma(BT->leftchild);
            b.erase(b.end()-1);
            }
            if(BT->rightchild!=NULL)
            {
            string a="1";
            b=b+a;
            bianma(BT->rightchild);
            b.erase(b.end()-1);
            }
        }
        else {BT->huffmanma=b;cout<<"zimu    "<<BT->zimu<<"  huffmanma:"<<b<<endl;}
    }
}
void huffmantree::gethuffmanma(huffmannode *BT,char v,string &a)
{
    if(BT!=NULL){
        if(BT->leftchild!=NULL||BT->rightchild!=NULL){
            if(BT->leftchild!=NULL)
            gethuffmanma(BT->leftchild,v,a);
            if(BT->rightchild!=NULL)
            gethuffmanma(BT->rightchild,v,a);
        }
        else {if(BT->zimu==v)a=BT->huffmanma;}
    }
}
string f(ch a[],string b)
{
    string c="";int mark=0;
    while(1)
    {
        int i;
        if(b.length()==0)break;
        string d;
        if(b.length()<2){cout<<"error"<<endl;return "error";}
        d=b.substr(0,2);
        b=b.substr(2, b.length()-2);
        mark=0;
        for(i=0;i<5;i++)
        {
            if(a[i].huffman==d){c=c+a[i].x;mark=1;break;}
        }
        if(i==5&&mark==1)continue;

        if(mark==0){
        d=d+b.substr(0,1);
        b=b.substr(1, b.length()-1);
        for(i=0;i<5;i++)
        {
            if(a[i].huffman==d){c=c+a[i].x;mark=1;break;}
        }
        if(i==5&&mark==0){cout<<"huffman字符串错误"<<endl;break;}
        else mark=0;
    }
    }
    return c;
}
int main()
{
    ch a[5];
    a[0].x = 'a'; a[0].y = 4;
	a[1].x = 'b'; a[1].y = 7;
	a[2].x = 'c'; a[2].y = 5;
	a[3].x = 'd'; a[3].y = 2;
	a[4].x = 'e'; a[4].y = 9;
    huffmantree x(a,5);
    x.PrintBTree(x.getroot());
    cout<<endl;
    x.bianma(x.getroot());
    x.gethuffmanma(x.getroot(),'a',a[0].huffman);
    x.gethuffmanma(x.getroot(),'b',a[1].huffman);
    x.gethuffmanma(x.getroot(),'c',a[2].huffman);
    x.gethuffmanma(x.getroot(),'d',a[3].huffman);
    x.gethuffmanma(x.getroot(),'e',a[4].huffman);
    string l="110001110001010";
    string o=f(a,l);
    cout<<"110001110001010 translation:"<<o;
    return 0;
}
