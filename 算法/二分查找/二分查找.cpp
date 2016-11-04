#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int array[10000001];
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
void binarysearch(int a[],int x,int n)
{
    int left=0;
    int right=n-1;
    while(left<=right){
        int middle=(left+right)/2;
        if(x==a[middle]){cout<<"已找到"<<x<<"位置"<<middle<<endl;
        return;}
        if(x>a[middle])left=middle+1;
        else right=middle-1;
    }
    cout<<"没有找到"<<x<<endl;
    return;
}
int main()
{
    cout<<"请输入数组的规模"<<endl;
    int n;
    cin>>n;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        array[i]=rand();
    }
    QuickSort(array,0,n-1);
    int num;
    cout<<"请输入想查询的数字"<<endl;
    cin>>num;
    int start=clock();
    binarysearch(array,num,n);
    int finish=clock();
    cout<<"耗时："<<finish-start<<endl;
    return 0;
}
