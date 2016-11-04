#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
using namespace std;
void setData(int a[],int n)
{
    //ifstream in("1.txt");
    cout<<"请输入"<<n<<"个元素"<<endl;
    /*for(int i=0;i<n;i++)
    {
        in>>a[i];
    }*/
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%1000;
    }
    cout<<"输入完成"<<endl;
}
void sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                int k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
}
int localData(int a[],int value)
{
    int i=0;
    while (a[i]!=value)i++;
    return i;
}
void copyData(int a[],int d[],int n)
{
    for(int i=0;i<n;i++)
        a[i]=d[i];
}
template<class T>
int Partition(T r[], int low, int high)
{
	int pivotpos = low;
	T pivot = r[low], t;
	for (int i = low + 1; i <= high; i++)
	if (r[i] < pivot){
		pivotpos++;
		if (pivotpos != i){
			t = r[pivotpos];
			r[pivotpos] = r[i];
			r[i] = t;
		}
	}
	r[low] = r[pivotpos]; r[pivotpos] = pivot;
	return pivotpos;
}
int divisionRecursion(int a[],int n,int k)
{
    if(n<=6)
    {
        sort(a,n);
        return a[k-1];
    }
    else
    {
        int b[2000],c[2000],d[10001],e[10001];
        int i=0,j=0,t=0;
        while(i<n)
        {
            e[i]=a[i];
            b[j++]=a[i++];
            if(i%5==0||i==n)
            {
                sort(b,j);
                c[t++]=b[j/2];
                j=0;
            }
        }
        sort(c,t);
        int f;
        f=e[localData(e,c[t/2])];
        e[localData(e,c[t/2])]=e[0];
        e[0]=f;
        Partition(e,0,n-1);
        if(k==localData(e,c[t/2]))return c[t/2];
        else if(k<=localData(e,c[t/2]))
        {
            int i=0,j=0;
            while(i<localData(e,c[t/2]))
            {
                if(e[i]<c[t/2])d[j++]=e[i];
                i++;
            }
            n=j;
            copyData(e,d,j);
            return divisionRecursion(e,n,k);
        }
        else
        {
            int i=0,j=0;
            while(i<n)
            {
                if(e[i]>c[t/2])d[j++]=e[i];
                i++;
            }
            k=k-n+j;
            n=j;
            copyData(e,d,j);
            return divisionRecursion(e,n,k);
        }
    }
}
int main()
{
    int a[10001],n,k,value;
    cout<<"请输入元素总数"<<endl;
    cin>>n;
    setData(a,n);
    cout<<"请输入想求第几小的元素"<<endl;
    cin>>k;
    int start=clock();
    value=divisionRecursion(a,n,k);
    int finish=clock();
    cout<<"第"<<k<<"小元素是:"<<value<<"  "<<"位置是第"<<localData(a,value)+1<<"个"<<endl;
    cout<<"耗时:"<<finish-start<<endl;
    return 0;
}
