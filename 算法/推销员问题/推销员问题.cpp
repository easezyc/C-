#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;
struct moneytype
{
    double d_money;
    int point1,point2;
};
double start, finish;
moneytype money[10][10];
moneytype sortmoney[45];
int mark[10];
int endmark[10];
int routine[10];
int markmoney=35000;
int allmoney=0;
int count=0;
int n=0;
void Hamilton(int x)
{
    if(count==n-1&&allmoney<markmoney)
    {
        int i;
        for(i=0; i<n; i++)
        {
            endmark[i]=routine[i];
        }
        markmoney=allmoney;
    }
    int i;
    for(i=0; i<n; i++)
    {
        if(mark[i]==0&&money[x][i].d_money!=0)
        {
            mark[i]=1;
            count++;
            routine[count]=i;
            allmoney+=money[x][i].d_money;
            Hamilton(i);
            allmoney-=money[x][i].d_money;
            count--;
            mark[i]=0;
        }
    }
}
int main()
{

    ifstream in;
    in.open("money.txt",ios_base::in);
    int i,j,k=1;
    for(i=0; i<10; i++)
    {
        for(j=0; j<k; j++)
        {
            in>>money[i][j].d_money;
            money[i][j].point1=i;
            money[i][j].point2=j;
            money[j][i].d_money=money[i][j].d_money;
            money[j][i].point1=i;
            money[j][i].point2=j;
        }
        k++;
    }
    cout<<"请输入要周游的城市数量:"<<endl;
    cin>>n;
    start = clock();
    for(i=0; i<10; i++)
    {
        mark[i]=0;
        endmark[i]=0;
        routine[i]=0;
    }
    mark[0]=1;
    routine[0]=0;
    Hamilton(0);
    for(i=0; i<n; i++)
    {
        if(i<n-1)
        {
            cout<<endmark[i]<<"-";
        }
        else cout<<endmark[i]<<endl;
    }
    finish = clock();
    cout<<"周游所需要的钱:"<<markmoney<<endl;
    cout<<"程序所用时间："<<finish-start<<endl;
    return 0;
}
