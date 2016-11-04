#include<iostream>
#include<time.h>
using namespace std;
void knapsack(int v[],int w[],int c,int m[100][100],int n)
{
    n=n-1;
    int jMax;
    if(w[n]<c)jMax=w[n];
    else jMax=c;

    for(int j=0;j<jMax;j++)
    {
        m[n][j]=0;
    }
    for(int j=w[n];j<=c;j++)
        m[n][j]=v[n];
    for(int i=n-1;i>0;i--)
    {
        if(w[i]<c)jMax=w[i];
        else jMax=c;
        for(int j=0;j<jMax;j++)
            m[i][j]=m[i+1][j];
        for(int j=w[i];j<=c;j++)
        {
            if(m[i+1][j]>m[i+1][j-w[i]]+v[i])m[i][j]=m[i+1][j];
            else m[i][j]=m[i+1][j-w[i]]+v[i];
        }
    }
    m[0][c]=m[1][c];
    if(c>w[0])
    {
        if(m[0][c]>m[1][c-w[0]]+v[0])m[0][c]=m[0][c];
        else m[0][c]=m[1][c-w[0]]+v[0];
    }
}
int main()
{
    int v[100],w[100],c,m[100][100],n;
    cout<<"请输入物品的数量(10个以内)"<<endl;
    cin>>n;
    cout<<"请输入包最大载重量(背包最大容量为100)"<<endl;
    cin>>c;
    cout<<"请输入每个物品的重量和价值量"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }
    int start=clock();
    knapsack(v,w,c,m,n);
    int finish=clock();
    cout<<"最大价值量为:"<<m[0][c]<<endl;
    cout<<"时间消耗为:"<<finish-start<<endl;
    return 0;
}
