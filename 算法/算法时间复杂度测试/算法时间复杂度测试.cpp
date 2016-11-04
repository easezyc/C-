#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
template<class T>
void InsertSort(T r[], int n)
{
	T temp;
	int i, j;
	for (i = 1; i < n; i++)
	{
		if (r[i] < r[i - 1])
		{
			temp = r[i];
			j = i - 1;
			do{
				r[j + 1] = r[j];
				j--;
			} while (j >= 0 && temp < r[j]);
			r[j + 1] = temp;
		}
	}
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
template<class T>
void QuickSort(T r[], int left, int right)
{
	if (left < right){
		int pivotpos = Partition(r, left, right);
		QuickSort(r, left, pivotpos - 1);
		QuickSort(r, pivotpos + 1, right);
	}
}

int t1[100000001],t2[100000001];
int main()
{
    srand(time(NULL));
    int start,finish,time;
    long long n;
    cout<<"请输入要对多少个数排序"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        t1[i]=rand();
        t2[i]=t1[i];
    }
    start=clock();
    QuickSort(t1,0,n-1);
    finish=clock();
    time=finish-start;
    cout<<"快排耗时："<<time<<endl;
    start=clock();
    InsertSort(t2,n);
    finish=clock();
    time=finish-start;
    cout<<"插入排序耗时："<<time<<endl;
}
