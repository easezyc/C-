#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
void optimalBinarySearchTree(float a[10],float b[10],float m[10][10],int s[10][10],float w[10][10],int n)
{
    for(int i=0;i<=n;i++)
    {
        w[i+1][i]=a[i];
        m[i+1][i]=0;
    }
    for(int r=0;r<n;r++)
    {
        for(int i=1;i<=n-r;i++)
        {
            int j=i+r;
            w[i][j]=w[i][j-1]+a[j]+b[j];
            m[i][j]=m[i+1][j];
            s[i][j]=i;
            for(int k=i+1;k<=j;k++)
            {
                float t=m[i][k-1]+m[k+1][j];
                if(t<m[i][j])
                {
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
            m[i][j]+=w[i][j];
        }
    }
}
int main()
{
    int n,s[10][10];
    cout<<"请输入元素的个数（测试数据只能输入1-5）"<<endl;
    cin>>n;
    float a[10],b[10],m[10][10],w[10][10];
    ifstream in("in.txt");
    for(int i=0;i<=n;i++)
        in>>a[i];
    for(int i=1;i<=n;i++)
        in>>b[i];
    int start=clock();
    optimalBinarySearchTree(a,b,m,s,w,n);
    int finish=clock();
    int k=s[1][n];
    cout<<"根节点为x"<<k<<endl;
    int k2=s[k+1][n];
    k=s[1][k-1];
    cout<<"左根节点为x"<<k<<endl;
    cout<<"右根节点为x"<<k2<<endl;
    cout<<"程序耗时为:"<<finish-start<<endl;
    return 0;
}
