#include<iostream>
#include<time.h>
#include<stdio.h>
using namespace std;
#define N 7
#define maxsize 0x3f3f3f3f
double a[8][8]={
    {0,0,0,0,0,0,0,0},
  {0,maxsize,13,8,maxsize,30,maxsize,32},
  {0,maxsize,maxsize,maxsize,maxsize,maxsize,9,7},
  {0,maxsize,maxsize,maxsize,5,maxsize,maxsize,maxsize},
  {0,maxsize,maxsize,maxsize,maxsize,6,maxsize,maxsize},
  {0,maxsize,maxsize,maxsize,maxsize,maxsize,2,maxsize},
  {0,maxsize,maxsize,maxsize,maxsize,maxsize,maxsize,17},
  {0,maxsize,maxsize,maxsize,maxsize,maxsize,maxsize,maxsize}
 };
void dijkstra(int v,double a[N+1][N+1],double dist[],int prev[],int n)
{
    if(v<1||v>n) return;
    int mark[N+1];
    for(int i=1;i<=n;i++)
    {
        dist[i]=a[v][i];
        mark[i]=0;
        if(dist[i]==maxsize)prev[i]=0;
        else prev[i]=v;
    }
    mark[v]=1;
    dist[v]=0;
    prev[v]=0;
    for(int i=1;i<n;i++)
    {
        double temp=maxsize;
        int u=v;
        for(int j=1;j<=n;j++)
        {
            if((!mark[j])&&dist[j]<temp)
            {
                u=j;temp=dist[j];
            }
        }
        mark[u]=1;
        for(int j=1;j<=n;j++)
        {
            if((mark[j]==0)&&(a[u][j]<maxsize))
            {
                double newlist=dist[u]+a[u][j];
                if(newlist<dist[j]){
                    dist[j]=newlist;
                    prev[j]=u;
                }
            }
        }
    }
}
int main()
{
    cout<<"修改宏定义中的值来确定顶点个数"<<endl;
    cout<<"请输入起始点"<<endl;
    int v;
    cin>>v;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=i;j++)
            a[i][j]=a[j][i];

    int prev[N+1];
    double dist[N+1];
    int start=clock();
    int n=N;
    dijkstra(v,a,dist,prev,n);
    int finish=clock();
    int pre;
    for(int i=1;i<=N;i++)
    {
        cout<<v<<"到"<<i<<"的最短距离为"<<dist[i]<<endl;
        pre=prev[i];
        cout<<"路径："<<i;
        while(pre!=0)
        {
            cout<<"<——"<<pre;
            pre=prev[pre];
        }
        cout<<endl;
    }
    cout<<"时间消耗为:"<<finish-start<<endl;
    return 0;
}
